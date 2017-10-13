#!/bin/env python3

import sys
import getopt
import pus_config

def usage():
    print('Usage: generated_mission_config.py <JSON_DIR> <OUTPUT_DIR>')

def main():
    # parse command line options
    try:
        opts, args = getopt.getopt(sys.argv[1:], '', [])
    except getopt.GetoptError as err:
        print(err)
        usage()
        sys.exit(2)
        
    if len(args) != 2:
        usage()
        sys.exit(2)

    # process arguments
    pus_config.generate(args[0], args[1])

if __name__ == "__main__":
    main()





