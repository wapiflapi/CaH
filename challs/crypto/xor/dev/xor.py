#!/usr/bin/env python3

import os
import hashlib

key = hashlib.md5(os.urandom(100)).digest()

infile = "xor.png"
outfile = "xor.out.png"

f = bytearray(open(infile, "rb").read())
fout = open(outfile, "wb")

for i,b in enumerate(f):
    fout.write(bytearray([b ^ key[i % len(key)]]))

