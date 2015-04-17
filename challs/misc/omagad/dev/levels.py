#!/usr/bin/python2.7
## levels.py for  in /home/sin/cyber@hack/cq-ctf/challs/misc/omagad/dev
##
## Made by SiN
## Login   <sin@epitech.net>
##
## Started on  Mon Mar  9 00:28:17 2015 
## Last update Fri Mar 20 22:27:15 2015 
##

import random
import os

flag = "flag{goodjobforomagad}"

def level1(sock):
    vari = os.listdir("./level1")
    for i in range(75):
        val = random.randint(0, len(vari) - 1)
        fd = open("./level1/" + vari[val])
        if sock:
            sock.send(fd.read() + '\n')
        a = sock.recv(3);
        if a[0] != vari[val][0]:
            fd.close()
            if sock:
                sock.send("bad answer bye bye\n")
            exit()
        fd.close()

def level2(sock):
    vari = os.listdir("./level2")
    for i in range(75):
        val = random.randint(0, len(vari) - 1)
        fd = open("./level2/" + vari[val])
        if sock:
            sock.send(fd.read() + '\n')
        a = sock.recv(3);
        if a[0] != vari[val][0]:
            fd.close()
            if sock:
                sock.send("bad answer bye bye\n")
            exit()
        fd.close()

def level3(sock):
    vari = os.listdir("./level3")
    for i in range(75):
        val = random.randint(0, len(vari) - 1)
        fd = open("./level3/" + vari[val])
        if sock:
            sock.send(fd.read() + '\n')
        a = sock.recv(3);
        if a[0] != vari[val][0]:
            fd.close()
            if sock:
                sock.send("bad answer bye bye\n")
            exit()
        fd.close()
    if sock:
        sock.send(flag + '\n')
