# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

'''Run the different code generations for the selected mission configuration'''

import sys
from .packet_queues_config import generate_packet_queues_config
from .st03_config import generate_st03_config
from .st05_config import generate_st05_config
from .st08_config import generate_st08_config
from .st11_config import generate_st11_config
from .st12_config import generate_st12_config
from .st18_config import generate_st18_config
from .st19_config import generate_st19_config
from .st20_config import generate_st20_config
from .st23_config import generate_st23_config

def generate(jsonDir, outDir):
    print('Generate mission configuration for {} in {}:'.format(jsonDir,outDir))
    generate_packet_queues_config(jsonDir, outDir)
    generate_st03_config(jsonDir, outDir)
    generate_st05_config(jsonDir, outDir)
    generate_st08_config(jsonDir, outDir)
    generate_st11_config(jsonDir, outDir)
    generate_st12_config(jsonDir, outDir)
    generate_st18_config(jsonDir, outDir)
    generate_st19_config(jsonDir, outDir)
    generate_st20_config(jsonDir, outDir)
    generate_st23_config(jsonDir, outDir)

