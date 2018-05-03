# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

import sys


def main(argv):
    PusGui.create()
    
def usage():
    print("Usage: {} <PUSGUI_MODULE>".format(sys.argv[0]))



if len(sys.argv) != 2:
    usage()
    sys.exit(1)


import builtins
builtins.ESROCOS_PUSGUI_MODULE = sys.argv[1]
builtins.ESROCOS_PUSGUI_CONFIG = "config.json"
import PusGui


if __name__ == "__main__":
    main(sys.argv[1:])
