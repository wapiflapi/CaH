<?php

include("flag.php");

if (!isset($_GET["a"]))
  die("Nop");

$a = $_GET["a"];
if (strspn($a, "01") != strlen($a))
  die("Nop, binary please.");

if (strstr($a, "1") == NULL)
  die("Nop, it must be > 0");

if (base_convert(base_convert($a, 2, 10), 10, 2) == 0)
  echo $flag;
else
  echo "nop";

?>
