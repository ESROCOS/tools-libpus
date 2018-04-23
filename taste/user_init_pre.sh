#!/bin/sh


export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/esrocos/esrocos-ws-pus/tools-libpus/debug/src/:/home/esrocos/esrocos-ws-pus/tools-libpus/debug/mission/test_01/:/home/esrocos/esrocos-ws-pus/tools-libpus/debug/asn1/:/home/esrocos/esrocos-ws-pus/tools-libpus/debug/mpy/mpy/

#gcc -shared -o ~/esrocos-ws-pus/tools-libpus/debug/mission/test_01/libesrocos_pus_mission_test_01_st08_functions.so -fPIC ~/esrocos-ws-pus/tools-libpus/mission/test_01/st08_functions.c -I/home/esrocos/esrocos-ws-pus/tools-libpus/include/
#cp ~/esrocos-ws-pus/pus/mission/test_01/libesrocos_pus_mission_test_01_st08_functions.so /home/esrocos/esrocos-ws-pus/pus/debug/mission/test_01/libesrocos_pus_mission_test_01_st08_functions.so

ORCHESTRATOR_OPTIONS+=" --no-retry "
ORCHESTRATOR_OPTIONS+=" -e x86_partition:/usr/include/python3.5m"
ORCHESTRATOR_OPTIONS+=" -e x86_partition:/home/esrocos/esrocos-ws-pus/tools-libpus/include/"
ORCHESTRATOR_OPTIONS+=" -e x86_partition:/home/esrocos/esrocos-ws-pus/tools-libpus/debug/mpy/mpy/include/"
ORCHESTRATOR_OPTIONS+=" -e x86_partition:/home/esrocos/esrocos-ws-pus/tools-libpus/debug/asn1/generated/"
ORCHESTRATOR_OPTIONS+=" -e x86_partition:/home/esrocos/esrocos-ws-pus/tools-libpus/debug/mission/test_01/generated/include/" 

ORCHESTRATOR_OPTIONS+=" -l x86_partition:/usr/lib/x86_64-linux-gnu/libpython3.5m.so"
ORCHESTRATOR_OPTIONS+=" -l x86_partition:/home/esrocos/esrocos-ws-pus/tools-libpus/debug/src/libesrocos_pus.so"
ORCHESTRATOR_OPTIONS+=" -l x86_partition:/home/esrocos/esrocos-ws-pus/tools-libpus/debug/mpy/mpy/libesrocos_mpy.so"
ORCHESTRATOR_OPTIONS+=" -l x86_partition:/home/esrocos/esrocos-ws-pus/tools-libpus/debug/mission/test_01/libesrocos_pus_mission_test_01.so"
ORCHESTRATOR_OPTIONS+=" -l x86_partition:/home/esrocos/esrocos-ws-pus/tools-libpus/debug/mission/test_01/libesrocos_pus_mission_test_01_st08_functions.so"

echo "ORCHESTRATOR_OPTIONS=$ORCHESTRATOR_OPTIONS" 
