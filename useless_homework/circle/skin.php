<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tic-Tac-Toe</title>
</head>

<body>
    <h1>Player ID: <span id="playerId"></span></h1>
    <h2>Online Players:</h2>
    <ul id="playerList"></ul>
    <!-- 引入外部 JavaScript 檔案 -->
    <script>
        let conn = new WebSocket('ws://localhost:8080');
        let playerId = null;

        conn.onopen = () => console.log("WebSocket connected!");
        conn.onmessage = (e) => {
            let data = JSON.parse(e.data);

            switch (data.action) {
                case 'welcome':
                    playerId = data.playerId;
                    document.getElementById('playerId').textContent = playerId;
                    console.log("Your Player ID: " + playerId);
                    break;

                case 'playerList':
                    updatePlayerList(data.players);
                    break;

                case 'challenge':
                    if (confirm(`Player ${data.fromId} wants to play with you. Accept?`)) {
                        conn.send(JSON.stringify({
                            action: 'challengeResponse',
                            accept: true
                        }));
                    } else {
                        conn.send(JSON.stringify({
                            action: 'challengeResponse',
                            accept: false
                        }));
                    }
                    break;
            }
        };

        // 更新玩家列表
        function updatePlayerList(players) {
            const list = document.getElementById('playerList');
            list.innerHTML = players
                .map(p => `<li onclick="challengePlayer('${p.id}')">${p.id}</li>`)
                .join('');
        }

        // 發起挑戰
        function challengePlayer(targetId) {
            conn.send(JSON.stringify({
                action: 'challenge',
                targetId: targetId
            }));
        }
    </script>
</body>

</html>