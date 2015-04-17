# setup

This chalenge should be run with something like xinetd without arguments.

The compiled binary in /dev/ should be used. Sources are provided FTR.
If custom compiled this should be PIE + ASLR + NX + STACK CANARY.

FYI: xinetd -f hdsaas.xinetd  # with -d for debug / no daemon.
