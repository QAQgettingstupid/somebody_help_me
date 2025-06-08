### 開啟教學
1. 先灌composer
2. 把這個上層資料夾circle下的檔案全下載放到xampp的htdocs
3. 找到game_server.php (在circle/game/bin下) 並在此處開cmd 打php game_server.php, 然後不要關這cmd
4. 開xampp, 用xampp開skin.php或try.php(skin是入口看在線玩家,try是圈圈叉叉進行的頁面)

#### 題外話

-  skin.php的 let conn = new WebSocket('ws://localhost:8080'); 的localhost改伺服器IP同內網可互聯

************************************************

### 以下還沒做QAQ

-  skin.php連到try.php (因為要從socket確認對戰玩家再連過去try.php)
-  try.php遊戲邏輯判斷 (其實try.php根本沒動過)
  
