<?php
// 如果需要，這裡可以加上初始化邏輯（例如設定 CSP 標頭）
header("Content-Security-Policy: connect-src 'self' ws://localhost:8080;");
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tic-Tac-Toe</title>
    <style>
        body { font-family: Arial, sans-serif; text-align: center; margin-top: 50px; }
        .board { display: grid; grid-template-columns: repeat(3, 100px); gap: 5px; margin: 20px auto; }
        .cell { width: 100px; height: 100px; border: 1px solid #000; font-size: 36px; display: flex; align-items: center; justify-content: center; cursor: pointer; }
        .cell.taken { cursor: not-allowed; background: #eee; }
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
        // 建立 WebSocket 連線
        let conn = new WebSocket('ws://localhost:8080');
        let symbol = 'X'; // 預設玩家符號，實際應該由伺服器分配

        conn.onopen = () => {
            console.log("WebSocket connection established!");
        };

        conn.onmessage = (e) => {
            let data = JSON.parse(e.data);
            // 更新棋盤
            let cell = document.querySelector(`.cell[data-index='${data.index}']`);
            if (cell) {
                cell.textContent = data.symbol;
                cell.classList.add('taken');
            }
        };

        // 監聽棋盤點擊事件
        document.querySelectorAll('.cell').forEach(cell => {
            cell.addEventListener('click', () => {
                if (cell.classList.contains('taken')) return;
                let index = cell.getAttribute('data-index');
                cell.textContent = symbol;
                cell.classList.add('taken');
                // 發送步數訊息到伺服器
                conn.send(JSON.stringify({ action: "move", index: index, symbol: symbol }));
            });
        });
    </script>
</body>
</html>
