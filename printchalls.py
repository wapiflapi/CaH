#!/usr/bin/env python3
## genflag.py for  in /home/eax/dev/cq-ctf
##
## Made by eax
## Login   <soules_k@epitech.net>
##
## Started on  Wed Apr 15 18:12:11 2015 eax
## Last update Thu Apr 16 10:22:15 2015 Wannes Rombouts
##

import configparser
import glob
import re

def flag_to_regex(f):

    if not (f.startswith('flag{') and f.endswith('}')):
        raise ValueError("not a valid flag")

    regex = '^(flag{)?%s}?$' % re.escape(f[5:-1])

    # let's make sure this works:

    if not re.match(regex, f):
        raise RuntimeError("regex fail")
    if not re.match(regex, f[5:-1]):
        raise RuntimeError("regex fail")

    if re.match(regex, f[5:-5]):
        raise RuntimeError("regex fail")

    if re.match(regex, f[5:] + "foo"):
        raise RuntimeError("regex fail")

    if re.match(regex, f[5:-1] + "foo"):
        raise RuntimeError("regex fail")

    if re.match(regex, f[5:-5] + "foo"):
        raise RuntimeError("regex fail")

    if re.match(regex, "foo" + f[5:]):
        raise RuntimeError("regex fail")

    if re.match(regex, "foo" + f[5:-1]):
        raise RuntimeError("regex fail")

    if re.match(regex, "foo" + f[5:-5]):
        raise RuntimeError("regex fail")

    return regex

def print_challs(c):
    config = configparser.ConfigParser()
    config.read(c + "/chall.cfg")
    name = config["chall"]["name"]
    flag = config["chall"]["flag"]
    desc = open(c + "/desc.txt").read().strip()
    ip = "<ip>"
    if "ip" in config["chall"]:
        ip = config["chall"]["ip"]
    port = "<port>"
    if "port" in config["chall"]:
        port = config["chall"]["port"]

    desc = desc.replace("<ip>", ip).replace("<port>", port)

    print("#" * 31)
    print("#%s#" % name.center(29))
    print("#%s#" % c.split("/")[1].center(29))
    print("#" * 31)
    print("-" * 31)
    print(flag_to_regex(flag))
    print("-" * 31)
    print(desc)
    print("-" * 31)
    print("\n"*3)

if __name__ == "__main__":
    challs = glob.glob("challs/*/*")
    for c in challs:
        if "ex_category" in c:
            continue
        print_challs(c)
