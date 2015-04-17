<?php

header('Content-type: application/json; charset=UTF-8');
date_default_timezone_set('Europe/Paris');

$letters_to_morse = array(
     "a" => ".-", "b" => "-...",
     "c" => "-.-.", "d" => "-..",
     "e" => ".", "f" => "..-.",
     "g" => "--.", "h" => "....",
     "i" => "..", "j" => ".---",
     "k" => ".-.", "l" => ".-..",
     "m" => "--", "n" => "-.",
     "o" => "---", "p" => ".--.",
     "q" => "--.-", "r" => ".-.",
     "s" => "...", "t" => "-",
     "u" => "..-", "v" => "...-",
     "w" => ".--", "x" => "-..-",
     "y" => "-.--", "z" => "--..",
     "1" => ".----", "2" => "..---",
     "3" => "...--", "4" => "....-",
     "5" => ".....", "6" => "-....",
     "7" => "--...", "8" => "---..",
     "9" => "----.", "0" => "-----",
     " " => "/", "." => ".-.-.-",
     "?" => "--..--", "'" => ".----.",
     "!" => "-.-.-----.", "/" => "-..-.",
     "(" => "-.--.", ")" => "-.--.-",
     "&" => ".-...", ":" => "---...",
     ";" => "-.-.-.", "=" => "-...-",
     "+" => ".-.-.", "-" => "-....-",
     "_" => "..--.-", "\"" => ".-..-.",
     "$" => "...-..-", "@" => ".--.-.",
     "," => "--..--", "EOM" => ".-.-."
);

$morse_to_letters = array_flip($letters_to_morse);

function morse_decode($string) {
  global $morse_to_letters;
  $line = "";
  $letters = explode(" ", $string);
  foreach ($letters as $letter) {
    if (empty($letter))
      $line .= " ";
    if (empty($morse_to_letters[$letter]))
      continue;
    $line .= $morse_to_letters[$letter];
  }
  return $line;
}

if (!isset($_POST['act']))
  exit('{"status": 1, "error": "There is a needle in the haystack."}');

switch ($_POST['act']) {
  case 'decode':
    if (!isset($_POST['morse']) || empty($_POST['morse']))
       exit('{"status": 1, "error": "You have to provide a source string."}');
    $encoded = $_POST['morse'];
    if (!preg_match('#^[/.\- ]+$#', $encoded))
       exit('{"status": 1, "error": "Your string must contain only [/.- ] chars."}');
    $decoded = morse_decode($encoded);
    $sql = mysql_connect("!!SQL_HOST!!", "!!SQL_USER!!", "!!SQL_PASSWORD!!");
    mysql_select_db("!!SQL_DATABASE!!", $sql);
    $client_ip = $_SERVER['REMOTE_ADDR'];
    $res = mysql_query("INSERT INTO morse_last(ip, text) VALUES('" . $client_ip. "', '" . $decoded . "')", $sql);
    if ($res == false)
      exit('{"status": 1, "error": "There is a needle in the haystack."}');
    echo '{"status": 0, "text": "' . $decoded . '", "date":"' . date("r") . '", "id":' . mysql_insert_id() . '}';
    break;

  default:
    exit('{"status": 1, "error": "There is a needle in the haystack."}');
}
