<?php

$creds = [];
$creds["admin"] = "ba75afed3493355ee6b8ebe003e53f04b25d2464";
$creds["eax64"] = "bcede3aa44b7136d422c77870d4fb2cd7dfbfc1a";

$privilege = [];
$privilege["admin"] = 42;
$privilege["eax64"] = 42;

function creds_login($u, $p)
{
    global $creds;

    if (isset($creds[$u]) &&
        $creds[$u] === $p)
        return true;
    return false;
}

function creds_get_priv($u)
{
    global $creds;
    global $privilege;

    if (isset($creds[$u]))
        return $privilege[$u];
    return 0;
}

?>