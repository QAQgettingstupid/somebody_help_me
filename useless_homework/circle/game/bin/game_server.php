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
            'playerID' => null,
            'connection' => $conn,
            'game' => null // 尚未加入遊戲
        ];

        // 生成玩家 ID
        $conn->send(json_encode([
            'action' => 'requestPlayerId'
        ]));
    }

    public function onMessage(ConnectionInterface $from, $msg)
    {
        $data = json_decode($msg, true);
        switch ($data['action']) {

            // 玩家回覆生成 ID
            case 'replyPlayerId':
                $this->players[$from->resourceId]['playerID'] = $data['playerId'];
                $this->players[$from->resourceId]['game'] = $data['game'];
                $this->broadcastPlayerList();
                break;

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
                    'fromId' => $this->players[$from->resourceId]['playerID'],
                    'otherplayer' => $data['otherplayer'],
                    'player' => $data['player']
                ];

                // 切到遊戲頁面
                foreach ($this->players as $player) { // 找發起玩家
                    if ($player['playerID'] == $data['otherplayer']) {
                        // 發起玩家
                        $player['connection']->send(json_encode(['action' => 'change_page']));
                    }
                }

                // 被發起玩家
                $this->players[$from->resourceId]['connection']->send(json_encode(['action' => 'change_page']));
                echo "challenge_confirm, otherplayer= " . $data['otherplayer'] . " player= " . $data['player'] . ",\n";
                break;

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
        unset($this->players[$conn->resourceId]);
        $this->clients->detach($conn);
        $this->broadcastPlayerList();
    }

    public function onError(ConnectionInterface $conn, \Exception $e)
    {
        $conn->close();
    }

    private function broadcastPlayerList()
    {
        // 取得所有玩家的 resourceId 作為玩家 ID
        $playerList = [];

        foreach ($this->players as $player) {
            if ($player['game'] === null) {
                $playerList[] = [
                    'id' => $player['playerID']
                ];
            }
        }

        // 廣播玩家列表
        foreach ($this->players as $player) {
            if ($player['game'] === null) {
                $player['connection']->send(json_encode([
                    'action' => 'playerList',
                    'players' => $playerList
                ]));
            }
        }
    }

    // $from 是發起挑戰的玩家$conn，$targetId 是被挑戰的玩家 ID
    private function openChallenge($from, $targetId)
    {
        foreach ($this->players as $player) {
            if ($player['playerID'] == $targetId) {
                $player['connection']->send(json_encode(['action' => 'challenge', 'fromId' => $this->players[$from->resourceId]['playerID']]));
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

class TicTacToeGame
{
    protected $rooms; // 遊戲房間集合

    public function __construct()
    {
        // 初始化遊戲房間
        $this->rooms = [];
    }

    public function createRoom($playerId)
    {
        // 為玩家創建一個新的遊戲房間
        $roomId = uniqid('room_');
        $this->rooms[$roomId] = [
            'players' => [$playerId],
            'board' => array_fill(0, 9, null), // 初始化棋盤
            'currentPlayer' => $playerId
        ];
        return $roomId;
    }
};

// 啟動伺服器
$server = IoServer::factory(
    new HttpServer(
        new WsServer(
            new TicTacToeServer(),
            new TicTacToeGame()
        )
    ),
    8080
);

echo "game server started on port 8080\n";

$server->run();
