#!/bin/sh

#./update_data_view.sh
#FORCE=1 taste-generate-skeletons

ORCHESTRATOR_OPTIONS+=" --no-retry "
ORCHESTRATOR_OPTIONS+=" -e x86_partition:$AUTOPROJ_CURRENT_ROOT/install/include/pus"
ORCHESTRATOR_OPTIONS+=" -e x86_partition:$AUTOPROJ_CURRENT_ROOT/install/include/pus/mission/test_01"
ORCHESTRATOR_OPTIONS+=" -e x86_partition:$AUTOPROJ_CURRENT_ROOT/install/include/pus/mission/test_01/mpy"

ORCHESTRATOR_OPTIONS+=" -l x86_partition:$AUTOPROJ_CURRENT_ROOT/install/lib/libesrocos_pus_core_test_01.so"
ORCHESTRATOR_OPTIONS+=" -l x86_partition:$AUTOPROJ_CURRENT_ROOT/install/lib/libesrocos_pus_test_01.so"

# Native Python needed for interface with the PUS Console GUI
ORCHESTRATOR_OPTIONS+=" -e x86_partition:/usr/include/python3.6m"
ORCHESTRATOR_OPTIONS+=" -l x86_partition:/usr/lib/x86_64-linux-gnu/libpython3.6m.so"

echo "ORCHESTRATOR_OPTIONS=$ORCHESTRATOR_OPTIONS" 
