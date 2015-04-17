<?php
include_once("cache.php");
include_once("creds.php");
include_once("classes.php");

$o = new UserLogin($_POST["user"], $_POST["password"]);
$o->login();

setcookie("userinfo", base64_encode(serialize($o)));

if ($o->isConnected())
    echo "ok";
else
    echo "Bad login or password";
?>