'''Run the different code generations for the selected mission configuration'''

import sys
from .st03_config import generate_st03_config
from .st05_config import generate_st05_config
from .packet_queues_config import generate_packet_queues_config

def generate(jsonDir, outDir):
    print('Generate mission configuration for {} in {}:'.format(jsonDir,outDir))
    generate_st03_config(jsonDir, outDir)
    generate_st05_config(jsonDir, outDir)
    generate_packet_queues_config(jsonDir, outDir)

