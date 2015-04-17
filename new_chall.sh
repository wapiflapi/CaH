#!/bin/bash
## new_chall.sh for  in /home/eax/dev/cq-ctf
## 
## Made by eax
## Login   <soules_k@epitech.net>
## 
## Started on  Sun Mar  8 07:53:36 2015 eax
## Last update Sun Mar  8 22:03:31 2015 eax
##

known_cats=(web crypto sploit stega forensics misc reverse)

cat=""

function check_args {
    if [ "$#" -ne 2 ]
    then
	echo "Usage: $0 category chall_name"
	exit
    fi
    
    for j in "${known_cats[@]}"
    do
	if [ "$j" == "$1" ]
	then
	    cat=$1
	fi
    done
    
    if [ -z $cat ]
    then
       echo "'$1' is not a knwon category"
       echo "known categoies are: ${known_cats[@]}"
       exit
    fi
}

function create_file {
    ok="y"
    if [ -f $1 ]
    then
	read -p "$1 already exist. Overwrite? [y/n]" ok
    fi
    if [ $ok == "y" ]
    then
	echo "[*] Creating $1"
	base64 -d <<< $2 > $1
    else
	echo "Skipping $1"
    fi
}

function create_chall {
    echo "[*] Creating directory challs/$1/$2"
    mkdir -p challs/$1/$2

    cd challs/$1/$2 || exit

    
    # Makefile

    
    content=$(cat << EOF | base64 -w0
PLAYERFILES	= 
SERVERFILES	= 

include ../../../chall_generic.mk
EOF
	   )
    create_file Makefile $content

    
    # chall.cfg

    content=$(cat << EOF | base64 -w0
[chall]
name=$2
flag=flag{exemple_flag}
EOF
	   )
    create_file chall.cfg $content


    
    # desc.txt

    content=$(cat << EOF | base64 -w0
Replace this with the actual description of this chall
EOF
	   )
    create_file desc.txt $content
    
    echo "[*] Creating dev/ directory"
    mkdir -p dev

    echo "You can now cd to challs/$1/$2"
}

check_args $*
create_chall $*

