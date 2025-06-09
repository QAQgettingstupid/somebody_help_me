<?php
// 如果需要，這裡可以加上初始化邏輯（例如設定 CSP 標頭）
header("Content-Security-Policy: connect-src 'self' ws://localhost:8080;");
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>圈圈叉叉遊戲</title>
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
<h1>圈圈叉叉</h1>
  <div id="status">輪到：X</div>
  <div class="board" id="board"></div>
  <button id="restart">重新開始</button>
    <script>
const board = Array(9).fill('');
    let current = 'X';
    let gameOver = false;
    const winPatterns = [
      [0,1,2],[3,4,5],[6,7,8], // 橫
      [0,3,6],[1,4,7],[2,5,8], // 直
      [0,4,8],[2,4,6]          // 斜
    ];
    const boardDiv = document.getElementById('board');
    const statusDiv = document.getElementById('status');
    function render() {
      boardDiv.innerHTML = '';
      board.forEach((cell, i) => {
        const d = document.createElement('div');
        d.className = 'cell';
        d.textContent = cell;
        d.onclick = () => move(i);
        boardDiv.appendChild(d);
      });
    }
    function move(i) {
      if (board[i] || gameOver) return;
      board[i] = current;
      render();
      const winner = checkWinner();
      if (winner) {
        statusDiv.textContent = `勝利者：${winner}`;
        highlightWin(winner.line);
        gameOver = true;
      } else if (board.every(cell => cell)) {
        statusDiv.textContent = '平手！';
        gameOver = true;
      } else {
        current = current === 'X' ? 'O' : 'X';
        statusDiv.textContent = `輪到：${current}`;
      }
    }
    function checkWinner() {
      for (let line of winPatterns) {
        const [a, b, c] = line;
        if (board[a] && board[a] === board[b] && board[a] === board[c]) {
          return {winner: board[a], line};
        }
      }
      return null;
    }
    function highlightWin(line) {
      const cells = boardDiv.children;
      line.forEach(idx => cells[idx].classList.add('win'));
    }
    document.getElementById('restart').onclick = () => {
      for (let i = 0; i < 9; i++) board[i] = '';
      current = 'X';
      gameOver = false;
      statusDiv.textContent = `輪到：${current}`;
      render();
    };
    render();

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
