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
builtins.ESROCOS_PUSGUI_MODULE = "esrocos_pus_mosar"
builtins.ESROCOS_PUSGUI_CONFIG = "/home/peraspera/esrocos_workspace/tools/libpus/mission/mosar/gui_config.json"
builtins.ESROCOS_PUSGUI_MISSION = "/home/esrocos/esrocos_workspace/tools/libpus/mission/mosar"
import PusGui


if __name__ == "__main__":
    main(sys.argv[1:])
