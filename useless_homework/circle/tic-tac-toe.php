<?php
header("Content-Security-Policy: connect-src 'self' ws://localhost:8080;");

//從URL取得玩家 ID 和房間 ID
$playerId = isset($_GET['playerId']) ? $_GET['playerId'] : null;
$roomId = isset($_GET['roomId']) ? $_GET['roomId'] : null;
?>
<!DOCTYPE html>
<html lang="zh-Hant">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tic-Tac-Toe</title>
    <style>
        body { font-family: Arial, sans-serif; text-align: center; }
    .board { display: grid; grid-template-columns: repeat(3, 80px); gap: 8px; margin: 30px auto; width: 264px;}
    .cell {
      width: 80px; height: 80px; font-size: 2.5em;
      border: 2px solid #333; display: flex;
      align-items: center; justify-content: center; cursor: pointer;
      background: #fff;
    }
    .cell.win { background: #ffe066; }
    #status { margin: 20px; font-size: 1.2em; }
    #restart { margin: 10px; }
    </style>
</head>

<body>
    <h1>Tic-Tac-Toe</h1>
    <div class="board">
        <?php for ($i = 0; $i < 9; $i++): ?>
            <div class="cell" data-index="<?= $i ?>"></div>
        <?php endfor; ?>
    </div>
    <script>
        //php變數轉換為JavaScript變數
        let playerId = <?= json_encode($playerId) ?>;
        let roomId = <?= json_encode($roomId) ?>;
        // 建立 WebSocket 連線
        let conn = new WebSocket('ws://localhost:8080');
        let symbol = 'X'; // 預設玩家符號，實際應該由伺服器分配

        conn.onopen = () => {

            console.log("WebSocket connection established!");
            console.log(playerId);
        };

        conn.onmessage = (e) => {
            let data = JSON.parse(e.data);

            switch (data.action) {
                case 'requestPlayerId':
                    // 當伺服器請求玩家 ID 時，回傳當前玩家 ID
                    conn.send(JSON.stringify({
                        action: 'replyPlayerId',
                        playerId: playerId,
                        game : roomId
                    }));
                    break;

                case 'updateBoard':
                    // 更新棋盤
                    let cell = document.querySelector(`.cell[data-index='${data.index}']`);
                    if (cell) {
                        cell.textContent = data.symbol;
                        cell.classList.add('taken');
                    }
                    break;
            }
        }; // <- 補上此處的結束大括號

        // 監聽棋盤點擊事件
        document.querySelectorAll('.cell').forEach(cell => {
            cell.addEventListener('click', () => {
                if (cell.classList.contains('taken')) return;
                let index = cell.getAttribute('data-index');
                cell.textContent = symbol;
                cell.classList.add('taken');
                // 發送步數訊息到伺服器
                conn.send(JSON.stringify({
                    action: "move",
                    index: index,
                    symbol: symbol
                }));
            });
        });
    </script>

</body>

</html>