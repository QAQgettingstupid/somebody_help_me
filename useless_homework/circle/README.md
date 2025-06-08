### 開啟教學
1. 先灌composer
2. 把這個上層資料夾circle下的檔案全下載放到xampp的htdocs
3. 找到game_server.php (在circle/game/bin下) 並在此處開cmd 打php game_server.php, 然後不要關這cmd
4. 開xampp, 用xampp開skin.php或try.php(skin是入口看在線玩家,try是圈圈叉叉進行的頁面)

#### 題外話

-  skin.php的 let conn = new WebSocket('ws://localhost:8080'); 的localhost改伺服器IP同內網可互聯
-  在skin.php所在處cmd打指令**php -S 0.0.0.0:8000**

************************************************

### 以下還沒做QAQ

-  tic-tac-toe.php 遊戲邏輯判斷、傳遞功能及結束後處置**在game_server.php裡面的TicTacToeGame寫判斷函式**
-  拒絕的選項還沒做(反是yes no 二選一)

### 想做但沒手(笑)

- 除了list 會顯示ID還有名稱(匿名)
- tic-tac-toe倒數計時
