#!/usr/bin/env python3
## test.py for  in /home/eax/dev/cq-ctf
## 
## Made by eax
## Login   <soules_k@epitech.net>
## 
## Started on  Sun Mar  8 09:19:25 2015 eax
## Last update Mon Mar  9 14:50:18 2015 eax
##

import sys
sys.path.append("../../../test/")

import os
import subprocess
from challtest import ChallTest

PROG_NAME = "ex42"
CHALL_PATH = os.getcwd()

class TestDev(ChallTest):

    def setUp(self):
        os.chdir(CHALL_PATH + "/dev")
    
    def testFlag(self):
        output = b""
        p = subprocess.Popen(["./" + PROG_NAME], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        output, err = p.communicate()
        self.assertEqual(p.returncode, 0, "program exit with error (%s)" % err)
        output = output.decode("utf-8").strip()
        self.assertEqual(output, self.config["flag"], "Output differ [%s] != [%s]" % (output, self.config["flag"]))
