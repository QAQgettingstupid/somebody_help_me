<?php
require dirname(__DIR__) . '/vendor/autoload.php';

use Ratchet\MessageComponentInterface;
use Ratchet\ConnectionInterface;
use Ratchet\Server\IoServer;
use Ratchet\Http\HttpServer;
use Ratchet\WebSocket\WsServer;

class TicTacToeServer implements MessageComponentInterface
{
    protected $clients; //所有在線玩家set
    protected $players; //玩家資訊

    public function __construct()
    {
        $this->clients = new \SplObjectStorage; //SplObjectStorage -> Object set
        $this->players = [];
    }

    // 為每個連線分配一個唯一 ID
    public function onOpen(ConnectionInterface $conn)
    {
        $this->clients->attach($conn); // 加入新玩家

        //從 $conn 取 resourceId 當 key (resourceId 是 ratchet 設定 $conn 的屬性)
        $this->players[$conn->resourceId] = [
            'connection' => $conn,
            'game' => null // 尚未加入遊戲
        ];

        // 送出 welcome 訊息，帶 resourceId 當玩家 ID
        $conn->send(json_encode([
            'action' => 'welcome',
            'playerId' => $conn->resourceId
        ]));

        $this->broadcastPlayerList();
    }

    public function onMessage(ConnectionInterface $from, $msg)
    {
        $data = json_decode($msg, true);
        switch ($data['action']) {

            // 玩家發起挑戰
            case 'challenge':
                $this->openChallenge($from, $data['targetId']);
                break;

            case 'move':
                $this->handleMove($from, $data['index']);
                break;

            // 玩家接受挑戰
            case 'challenge_confirm':
                $response = [
                    'action' => $data['action'],
                    'fromId' => $from->resourceId,
                    'otherplayer' => $data['otherplayer'],
                    'player' => $data['player']
                ];

                // 切到遊戲頁面
                $this->players[$data['otherplayer']]['connection']->send(json_encode(['action' => 'change_page']));
                $this->players[$data['player']]['connection']->send(json_encode(['action' => 'change_page']));
                echo "challenge_confirm, otherplayer= " . $data['otherplayer'] . " player= " . $data['player'] . ",\n";

                //未搞
            case 'challenge_not_confirm':
                // 處理玩家對挑戰的回應
                $response = [
                    'action' => $data['action'],
                    'fromId' => $from->resourceId,
                    'otherplayer' => $data['otherplayer']
                ];
                // 廣播給所有玩家
                foreach ($this->players as $player) {
                    $player['connection']->send(json_encode($response));
                }
                break;

            default:
                echo "Unknown action: " . $data['action'] . "\n";
                break;
        }
    }

    public function onClose(ConnectionInterface $conn)
    {
        $this->clients->detach($conn);
        unset($this->players[$conn->resourceId]);
        $this->broadcastPlayerList();
    }

    public function onError(ConnectionInterface $conn, \Exception $e)
    {
        $conn->close();
    }

    private function broadcastPlayerList()
    {
        // 取得所有玩家的 resourceId 作為玩家 ID
        $playerList = array_map(fn($resourceId) => ['id' => $resourceId], array_keys($this->players));

        // 廣播玩家列表
        foreach ($this->players as $player) {
            $player['connection']->send(json_encode([
                'action' => 'playerList',
                'players' => $playerList
            ]));
        }
    }

    // $from 是發起挑戰的玩家$conn，$targetId 是被挑戰的玩家 ID
    private function openChallenge($from, $targetId)
    {
        foreach ($this->players as $playerId => $player) {
            if ($playerId == $targetId) {
                $player['connection']->send(json_encode(['action' => 'challenge', 'fromId' => $from->resourceId]));
                break;
            }
        }
    }

    // 理論上要回覆發出挑戰的玩家,但沒做QAQ
    private function replyChallenge($response)
    {
        // 快寫啊
    }

    private function handleMove($from, $index)
    {
        // 遊戲邏輯省略：傳遞步數給對手
    }
}

// 啟動伺服器
$server = IoServer::factory(
    new HttpServer(
        new WsServer(
            new TicTacToeServer()
        )
    ),
    8080
);
echo "game server started on port 8080\n";
$server->run();
