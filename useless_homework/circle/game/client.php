<?php

require __DIR__ . '/vendor/autoload.php';

use WebSocket\Client;

try {
    $client = new Client("ws://localhost:8080/chat");
    $client->send("Hello from PHP client!");
    echo "Sent message to server.\n";

    $response = $client->receive();
    echo "Received from server: $response\n";

} catch (Exception $e) {
    echo "Error: {$e->getMessage()}\n";
}
