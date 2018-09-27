#!/bin/sh

#./update_data_view.sh
#FORCE=1 taste-generate-skeletons
sparc-rtems5-objcopy /home/esrocos/esrocos_workspace/install/gr740/lib/libesrocos_mpy_core_test_ur5_rtems.a --redefine-sym m_free=m_free_mp


ORCHESTRATOR_OPTIONS+=" --no-retry "
ORCHESTRATOR_OPTIONS+=" -e x86_partition:$AUTOPROJ_CURRENT_ROOT/install/include/pus"
ORCHESTRATOR_OPTIONS+=" -e x86_partition:$AUTOPROJ_CURRENT_ROOT/install/include/pus/mission/test_ur5_rtems"
ORCHESTRATOR_OPTIONS+=" -e x86_partition:$AUTOPROJ_CURRENT_ROOT/install/include/pus/mission/test_ur5_rtems/mpy"

ORCHESTRATOR_OPTIONS+=" -l x86_partition:$AUTOPROJ_CURRENT_ROOT/install/lib/libesrocos_pus_test_ur5_rtems.so"
ORCHESTRATOR_OPTIONS+=" -l x86_partition:$AUTOPROJ_CURRENT_ROOT/install/lib/libesrocos_pus_core_test_ur5_rtems.so"

# Native Python needed for interface with the PUS Console GUI
ORCHESTRATOR_OPTIONS+=" -e x86_partition:/usr/include/python3.5m"
ORCHESTRATOR_OPTIONS+=" -l x86_partition:/usr/lib/x86_64-linux-gnu/libpython3.5m.so"



# PUS test_ur5_rtems
ORCHESTRATOR_OPTIONS+=" -e gr740_partition:$AUTOPROJ_CURRENT_ROOT/install/include/pus"
ORCHESTRATOR_OPTIONS+=" -e gr740_partition:$AUTOPROJ_CURRENT_ROOT/install/include/pus/mission/test_ur5_rtems"
ORCHESTRATOR_OPTIONS+=" -e gr740_partition:$AUTOPROJ_CURRENT_ROOT/install/include/pus/mission/test_ur5_rtems/mpy"
ORCHESTRATOR_OPTIONS+=" -l gr740_partition:$AUTOPROJ_CURRENT_ROOT/install/gr740/lib/libesrocos_pus_core_test_ur5_rtems.a"
ORCHESTRATOR_OPTIONS+=" -l gr740_partition:$AUTOPROJ_CURRENT_ROOT/install/gr740/lib/libesrocos_pus_test_ur5_rtems.a"
ORCHESTRATOR_OPTIONS+=" -l gr740_partition:$AUTOPROJ_CURRENT_ROOT/install/gr740/lib/libesrocos_mpy_core_test_ur5_rtems.a"




echo "ORCHESTRATOR_OPTIONS=$ORCHESTRATOR_OPTIONS" 
