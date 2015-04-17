#!/usr/bin/env python3
## test.py for  in /home/eax/dev/cq-ctf
## 
## Made by eax
## Login   <soules_k@epitech.net>
## 
## Started on  Sun Mar  8 09:19:25 2015 eax
## Last update Sun Mar  8 10:05:13 2015 eax
##

import sys
sys.path.append("../../../test/")

import os
import subprocess
import hashlib
import re
from challtest import ChallTest

PROG_NAME = "secure_hash"

class SecureHashDev(ChallTest):

    def testFlag(self):
        output = b""
        p = subprocess.Popen(["./dev/" + PROG_NAME, self.config["flag"]], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        output, err = p.communicate()
        self.assertEqual(p.returncode, 0, "program exit with error (%s)" % err)
        output = output.decode("utf-8").strip()
        self.assertRegexpMatches(output, ".*debug\(" + re.escape(self.config["flag"]) + "\).*",
                                 "Output don't contain [%s].\n" % ("debug("+self.config["flag"]+")"))

    def hashTest(self, toHash):
        output = b""
        p = subprocess.Popen(["./dev/" + PROG_NAME, toHash], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        output, err = p.communicate()
        self.assertEqual(p.returncode, 0, "program exit with error (%s)" % err)
        output = output.decode("utf-8").strip()
        hexdigest = hashlib.md5(toHash).hexdigest()
        self.assertRegexpMatches(output, ".*Bad input, you current hash is: " + hexdigest + "\..*",
                                 "Output don't contain [%s].\n" % (hexdigest))

    def testHashes(self):
        self.hashTest(b"BestPig is the best pig ever!")
        self.hashTest(b"Hello")
        self.hashTest(b"cq")
        self.hashTest(b"09876rytfghbjklpoiuytfrdgfcbvjkoiptyrfgcvbn")
