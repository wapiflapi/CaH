#!/usr/bin/python2.7
## main.py for  in /home/sin/cyber@hack/cq-ctf/challs/misc/omagad/dev
##
## Made by SiN
## Login   <sin@epitech.net>
##
## Started on  Mon Mar  9 00:23:03 2015 
## Last update Fri Mar 20 22:27:36 2015 
##

import socket
import levels
import multiprocessing
import os
import time
import sys
import signal

def handler(signum, frame):
    if clisock:
        clisock.close()
    exit()

def timing(pid):
    time.sleep(7)
    os.kill(pid, 11)
    exit()

def process(clisock):
    signal.signal(signal.SIGSEGV, handler)
    timer = multiprocessing.Process(target=timing, args=(int(os.getpid()),))
    timer.start()
    levels.level1(clisock)
    levels.level2(clisock)
    levels.level3(clisock)

if __name__ == "__main__":
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.bind(('0.0.0.0', int(sys.argv[1])))
    sock.listen(5)
    while 1:
        (clisock, addr) = sock.accept()
        p = multiprocessing.Process(target=process, args=(clisock,))
        p.start()
