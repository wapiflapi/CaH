CREATE DATABASE IF NOT EXISTS !!SQL_DATABASE!!;

GRANT ALL PRIVILEGES ON !!SQL_DATABASE!!.* To !!SQL_USER!!@!!SQL_HOST!! IDENTIFIED BY '!!SQL_PASSWORD!!';

USE !!SQL_DATABASE!!;

CREATE TABLE IF NOT EXISTS `flag` (
  `flag` text NOT NULL
  ) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `flag` (`flag`) VALUES
('flag{-... .-.. .. -. -.. ... --.- .-.. .. --- ...- . .-. -- --- .-. ... . . . -.-.--}');

CREATE TABLE IF NOT EXISTS `morse_last` (
  `id` int(11) NOT NULL,
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `ip` varchar(15) DEFAULT NULL,
  `text` text
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

ALTER TABLE `morse_last`
  ADD PRIMARY KEY (`id`);

ALTER TABLE `morse_last`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;
