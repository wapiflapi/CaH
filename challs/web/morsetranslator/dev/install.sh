#/bin/sh

SQL_USER="morseuser"
SQL_PASSWORD="25739edf7a715a8894bcf9df7250de1d0bdf4028"
SQL_HOST="localhost"
SQL_DATABASE="morse"

cp -f dump.def.sql dump.sql
sed -i "s/!!SQL_HOST!!/$SQL_HOST/g" dump.sql
sed -i "s/!!SQL_USER!!/$SQL_USER/g" dump.sql
sed -i "s/!!SQL_PASSWORD!!/$SQL_PASSWORD/g" dump.sql
sed -i "s/!!SQL_DATABASE!!/$SQL_DATABASE/g" dump.sql

mysql -h $SQL_HOST -u root -p$SQL_PASSWORD < dump.sql

cp -f service.def.php service.php
sed -i "s/!!SQL_HOST!!/$SQL_HOST/g" service.php
sed -i "s/!!SQL_USER!!/$SQL_USER/g" service.php
sed -i "s/!!SQL_PASSWORD!!/$SQL_PASSWORD/g" service.php
sed -i "s/!!SQL_DATABASE!!/$SQL_DATABASE/g" service.php
