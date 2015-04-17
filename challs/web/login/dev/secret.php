<?php
include_once("cache.php");
include_once("classes.php");

if(!isset($_COOKIE["userinfo"]))
    die("Not connected");

$cookie = base64_decode($_COOKIE["userinfo"]);

$o = unserialize($cookie);

if ($o->isConnected() !== true)
    die("Not connected");

if ($o->isAdmin() !== true)
    die("You must be admin to view this page");

if ($o->user != "eax64")
{
    echo "Here is your flag: ...well, actually I don't want to give it to you.<br />\n";
    echo "Try to login with the user eax64, maybe.";
}
else
    echo "Ok, here is your flag: flag{sessions_are_too_lame}";

?>