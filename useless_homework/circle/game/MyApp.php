<?php

require __DIR__ . '/vendor/autoload.php';

use Ratchet\MessageComponentInterface;

if(interface_exists(MessageComponentInterface::class)) {
    echo "Ratchet is loaded23546???????????????\n";
} else {
    echo "Ratchet is not loaded\n";
}


