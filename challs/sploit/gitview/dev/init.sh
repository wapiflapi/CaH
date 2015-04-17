#!/bin/bash

echo "I will create and remove files in the current working directory: $(cwd)"
read -p "Is that OK? (yN) "

if [[ $REPLY =~ ^[Yy] ]]
then

    rm -rf .git
    git init

    echo "this is not the real flag" > FLAG
    git add FLAG
    git commit -am "Add a temporary flag to the challenge."

    echo "foo" > bar
    echo "spam" > eggs
    git add bar eggs
    git commit -am "Add some other files."

    git checkout -b "flag"
    echo "flag{seriously_who_never_used_yolo}" > FLAG
    git commit -am "Set the real flag for this challenge."

    echo "I need sudo to make sure the flag backup can't be touched."
    sudo cp FLAG FLAG.backup
    sudo chmod 004 FLAG.backup

    echo "Foo" > bar
    echo "Spam" > eggs

    git checkout master

fi
