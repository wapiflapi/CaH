#!/usr/bin/env python3
##
## cipher_them_all.py for demochescene in /home/ampotos/c@h/cq-ctf/challs/reverse/demochescene/dev
## 
## Made by 
## Login   <ampotos@epitech.net>
## 
## Started on  Tue Apr 14 18:31:44 2015 
## Last update Wed Apr 15 19:45:03 2015 
##

import itertools
import struct

pwd1 = b"$&z8f70"
pwd2 = b"sdjg87s"
pwd3 = b"[-)}<?*"
final_pwd = b"F1n4l !"

## sub
def cipher_final():
    global stage_final
    
    stage_final = b''.join([struct.pack("B", (c + key) % 256) for (c, key) in zip(stage_final, itertools.cycle(final_pwd))])
    return

## add
def cipher_fourth():
    global stage_final    
    global stage4
    
    stage_final = b''.join([struct.pack("B", (c - key)) if (c - key) >= 0 else struct.pack("B", c - key + 256) for (c, key) in zip(stage_final, itertools.cycle(pwd3))])
    stage4 = b''.join([struct.pack("B", c - key) if (c - key) >= 0 else struct.pack("B", c - key + 256) for (c, key) in zip(stage4, itertools.cycle(pwd3))])
    return

## xor
def cipher_third():
    global stage_final    
    global stage4
    global stage3
    
    stage_final = b''.join([struct.pack("B", c ^ key) for (c, key) in zip(stage_final, itertools.cycle(pwd2))])
    stage4 = b''.join([struct.pack("B", c ^ key) for (c, key) in zip(stage4, itertools.cycle(pwd2))])
    stage3 = b''.join([struct.pack("B", c ^ key) for (c, key) in zip(stage3, itertools.cycle(pwd2))])
    return

## xor with known key
def cipher_second():
    global stage_final    
    global stage4
    global stage3
    global stage2
    
    stage_final = b''.join([struct.pack("B", c ^ key) for (c, key) in zip(stage_final, itertools.cycle(pwd1))])
    stage4 = b''.join([struct.pack("B", c ^ key) for (c, key) in zip(stage4, itertools.cycle(pwd1))])
    stage3 = b''.join([struct.pack("B", c ^ key) for (c, key) in zip(stage3, itertools.cycle(pwd1))])
    stage2 = b''.join([struct.pack("B", c ^ key) for (c, key) in zip(stage2, itertools.cycle(pwd1))])
    return

stage2 = open("second_stage/second", "rb").read()
stage3 = open("third_stage/third", "rb").read()
stage4 = open("fourth_stage/fourth", "rb").read()
stage_final = open("flag_stage/demochescene", "rb").read()

cipher_final()
cipher_fourth()
cipher_third()
cipher_second()

open("second_stage/second.ciph", "wb").write(stage2);
open("third_stage/third.ciph", "wb").write(stage3);
open("fourth_stage/fourth.ciph", "wb").write(stage4);
open("flag_stage/demochescene.ciph", "wb").write(stage_final);
