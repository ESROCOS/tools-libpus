#!/bin/sh


ORCHESTRATOR_OPTIONS+=" --no-retry"
ORCHESTRATOR_OPTIONS+=" -e x86_partition:/home/esrocos/esrocos-ws-pus/pus/include/"
ORCHESTRATOR_OPTIONS+=" -e x86_partition:/home/esrocos/esrocos-ws-pus/pus/debug/asn1/generated/"

ORCHESTRATOR_OPTIONS+=" -l x86_partition:/home/esrocos/esrocos-ws-pus/pus/debug/src/libesrocos_pus_nothreads.a"
ORCHESTRATOR_OPTIONS+=" -l x86_partition:/home/esrocos/esrocos-ws-pus/pus/debug/mission/test_01/libesrocos_pus_mission_test_01.a"



echo "ORCHESTRATOR_OPTIONS=$ORCHESTRATOR_OPTIONS"
