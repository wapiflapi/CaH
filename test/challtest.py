#!/usr/bin/env python3
## challtest.py for  in /home/eax/dev/cq-ctf/test
## 
## Made by eax
## Login   <soules_k@epitech.net>
## 
## Started on  Sun Mar  8 09:08:43 2015 eax
## Last update Sun Mar  8 10:07:57 2015 eax
##

import os.path
import unittest
import configparser

class ChallTest(unittest.TestCase):

    def __init__(self, methodName='runTest'):
        super(ChallTest, self).__init__(methodName)

        for f in ["chall.cfg", "desc.txt"]:
            self.assertTrue(os.path.isfile(f), "The file %s is not present" % f)
        parser = configparser.ConfigParser()
        parser.read("chall.cfg")
        self.config = parser["chall"]

