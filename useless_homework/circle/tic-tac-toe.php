<?php
header("Content-Security-Policy: connect-src 'self' ws://localhost:8080;");
?>
<!DOCTYPE html>
<html lang="zh-Hant">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tic-Tac-Toe</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            text-align: center;
        }

        .board {
            display: grid;
            grid-template-columns: repeat(3, 80px);
            gap: 8px;
            margin: 30px auto;
            width: 264px;
        }

        .cell {
            width: 80px;
            height: 80px;
            font-size: 2.5em;
            border: 2px solid #333;
            display: flex;
            align-items: center;
            justify-content: center;
            cursor: pointer;
            background: #fff;
        }

        .cell.win {
            background: #ffe066;
        }

        #status {
            margin: 20px;
            font-size: 1.2em;
        }

        #restart {
            margin: 10px;
        }
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
        //從上頁取回玩家 ID 和房間 ID
        let playerId = sessionStorage.getItem('playerId');
        let roomId = sessionStorage.getItem('roomId');
        let first = sessionStorage.getItem('first') === 'true'; // === 'true' -> 將字串轉為布林值

        // 先手為X
        let symbol = first ? 'X' : 'O';

        // 建立 WebSocket 連線
        let conn = new WebSocket('ws://localhost:8080');
        conn.onopen = () => {
            // 以下可刪,單純除錯用
            console.log("WebSocket connection established!");
            console.log(playerId);
            console.log(roomId);
            console.log(first);
            console.log(symbol);
        };

        conn.onmessage = (e) => {
            let data = JSON.parse(e.data);

            switch (data.action) {

                // 當伺服器請求玩家 ID 時，回傳當前玩家 ID
                case 'requestPlayerId':
                    conn.send(JSON.stringify({
                        action: 'replyPlayerId',
                        playerId: playerId,
                        game: roomId
                    }));
                    conn.send(JSON.stringify({
                        action: 'updateBoard',
                        playerId: playerId,
                        game: roomId
                    }));
                    break;

                    // 更新棋盤
                case 'updateBoard':
                    


                    let cell = document.querySelector(`.cell[data-index='${data.index}']`);
                    if (cell) {
                        cell.textContent = data.symbol;
                        cell.classList.add('taken');
                    }
                    updateBoard();
                    break;
            }
        };

        //更新當前棋盤狀態
        function updateBoard() {

        }

        // 監聽棋盤點擊事件
        document.querySelectorAll('.cell').forEach(cell => {
            cell.addEventListener('click', () => {

                // 格子已經使用
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