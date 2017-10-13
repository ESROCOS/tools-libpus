'''Run the different code generations for the selected mission configuration'''

import sys
from .st03_config import generate_st03_config

def generate(jsonDir, outDir):
    print('Generate mission configuration for {} in {}:'.format(jsonDir,outDir))
    generate_st03_config(jsonDir, outDir)

