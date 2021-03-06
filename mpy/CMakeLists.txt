# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

# This script creates a Micropython library combining:
#  - the Micropython implementation that is provided with TASTE
#  - the configuration and marcos specific to the PUS library
#  - user-defined functions


#Check if TASTE is installed
execute_process ( 
    COMMAND bash -c "taste-config --prefix"
    RESULT_VARIABLE TASTE_INSTALLED
)
if(NOT (TASTE_INSTALLED EQUAL 0))
    MESSAGE( FATAL_ERROR "TASTE IS NOT INSTALLED" )
endif(NOT (TASTE_INSTALLED EQUAL 0))


execute_process ( 
    COMMAND bash -c "echo -n $(taste-config --prefix)"
    OUTPUT_VARIABLE TASTE_PREFIX
)

SET( TASTE_UPY ${TASTE_PREFIX}/../tool-src/upython-taste)
SET( TASTE_UPY_ESA_PORT ${TASTE_UPY}/ports/esa-taste)

#Copying OWN files 
set(SRC_FILES
    mpcontext.c
    pus_testmodule.c
    pus_obcp_libFunctions.c
)
set(HDR_FILES
    mpcontext.h
    mpconfigport.h
)
foreach(file ${SRC_FILES} ${HDR_FILES})
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/${file} ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
endforeach(file $(SRC_FILES))


#Coping userFunctions.c (from mission or src(default))
if(EXISTS "${CMAKE_SOURCE_DIR}/mission/${MISSION}/pus_obcp_userFunctions.c")
    message( STATUS "Using pus_obcp_userFunctions.c in mission, ${CMAKE_CURRENT_BINARY_DIR}")
    configure_file(${CMAKE_SOURCE_DIR}/mission/${MISSION}/pus_obcp_userFunctions.c ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
else()
    message( STATUS "Not found pus_obcp_userFunctions.c in mission, ${CMAKE_CURRENT_BINARY_DIR}; using default")
    configure_file(${CMAKE_SOURCE_DIR}/${MISSION}/pus_obcp_userFunctions.c ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
endif()

#Copying configuration files from TASTE ESA port
configure_file(${TASTE_UPY_ESA_PORT}/mphalport_taste_x86.h ${CMAKE_CURRENT_BINARY_DIR}/mphalport.h COPYONLY)
configure_file(${TASTE_UPY_ESA_PORT}/mphalport_taste_x86.c ${CMAKE_CURRENT_BINARY_DIR}/mphalport.c COPYONLY)
configure_file(${TASTE_UPY_ESA_PORT}/mputil.h ${CMAKE_CURRENT_BINARY_DIR}/mputil.h COPYONLY)
configure_file(${TASTE_UPY_ESA_PORT}/mputil.c ${CMAKE_CURRENT_BINARY_DIR}/mputil.c COPYONLY)

#Copy .c files from core uPython
file(GLOB UPY_CORE_SRC ${TASTE_UPY}/py/*.c)
    
foreach(file ${UPY_CORE_SRC})
    file(RELATIVE_PATH file_name "${TASTE_UPY}/py/" ${file} )
    configure_file(${file} ${CMAKE_CURRENT_BINARY_DIR}/py_${file_name} COPYONLY)
endforeach(file $(UPY_CORE_SRC))

#Copy .h files from core uPython
file(GLOB UPY_CORE_HEADERS ${TASTE_UPY}/py/*.h )

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/py/)

foreach(file ${UPY_CORE_HEADERS})
    file(RELATIVE_PATH file_name "${TASTE_UPY}/py/" ${file} )
    configure_file(${file} ${CMAKE_CURRENT_BINARY_DIR}/py/${file_name} COPYONLY)
endforeach(file $(UPY_CORE_HEADERS))

#Generate QSTR files

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/genhdr/)

set(COMMAND_GENERATE_MPVERSION "python ${TASTE_UPY}/py/makeversionhdr.py  ${CMAKE_CURRENT_BINARY_DIR}/genhdr/mpversion.h")

file(GLOB_RECURSE QSTR_SRC ${CMAKE_CURRENT_BINARY_DIR}/*.c )

foreach(file ${QSTR_SRC})
    set(QSTR_SRC_STR "${QSTR_SRC_STR} ${file}")
endforeach(file $(QSTR_SRC))

#g++ -E -DNO_QSTR -I . -DSTATIC="" -g  py_*.c mymodule.c > ./genhdr/qstr.i.last -I/home/esrocos/esrocos-ws-pus/tools-libpus/include/ -I/home/esrocos/esrocos-ws-pus/tools-libpus/debug/asn1/generated/ -I/home/esrocos/esrocos-ws-pus/tools-libpus/debug/mission/test_01/generated/include/ 
set(COMMAND_GENERATE_QSTRLAST "${CMAKE_CXX_COMPILER} -E -DNO_QSTR -I${CMAKE_CURRENT_BINARY_DIR} -DSTATIC=\"\" ${QSTR_SRC_STR}  -I${CMAKE_SOURCE_DIR}/include/ -I${CMAKE_SOURCE_DIR}/mission/${MISSION}/ -I${CMAKE_BINARY_DIR}/mission/${MISSION}/asn1/esrocos_pustypes_${MISSION} >${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstr.i.last")
#python $(taste-config --prefix)/../tool-src/upython-taste/py/makeqstrdefs.py split ./genhdr/qstr.i.last ./genhdr/qstr ./genhdr/qstrdefs.collected.h
set(COMMAND_GENERATE_QSTRDEFS_COLLECTED1 "python ${TASTE_UPY}/py/makeqstrdefs.py split ${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstr.i.last ${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstr ${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstrdefs.collected.h")
#python $(taste-config --prefix)/../tool-src/upython-taste/py/makeqstrdefs.py cat ./genhdr/qstr.i.last ./genhdr/qstr ./genhdr/qstrdefs.collected.h
set(COMMAND_GENERATE_QSTRDEFS_COLLECTED2 "python ${TASTE_UPY}/py/makeqstrdefs.py cat ${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstr.i.last ${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstr ${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstrdefs.collected.h")
#cat ./py/qstrdefs.h ./genhdr/qstrdefs.collected.h | sed 's/^Q(.*)/"&"/' | g++ -E -I. -DSTATIC="" -g - | sed 's/^"\(Q(.*)\)"/\1/' > ./genhdr/qstrdefs.preprocessed.h
set(COMMAND_GENERATE_QSTRDEFS_PRE "cat ${CMAKE_CURRENT_BINARY_DIR}/py/qstrdefs.h ${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstrdefs.collected.h | sed 's/^Q(.*)/\"&\"/' | g++ -E -I${CMAKE_CURRENT_BINARY_DIR} -DSTATIC=\"\" - | sed 's/^\"\\(Q(.*)\\)\"/\\1/' > ${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstrdefs.preprocessed.h")
#python $(taste-config --prefix)/../tool-src/upython-taste/py/makeqstrdata.py ./genhdr/qstrdefs.preprocessed.h > ./genhdr/qstrdefs.generated.h
set(COMMAND_GENERATE_QSTRDEFS_GEN "python ${TASTE_UPY}/py/makeqstrdata.py ${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstrdefs.preprocessed.h >${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstrdefs.generated.h")

# Execute QSTR files generation at configure time
execute_process ( COMMAND bash -c "${COMMAND_GENERATE_MPVERSION}")
execute_process ( COMMAND bash -c "${COMMAND_GENERATE_QSTRLAST}")
execute_process ( COMMAND bash -c "${COMMAND_GENERATE_QSTRDEFS_COLLECTED1}")
execute_process ( COMMAND bash -c "${COMMAND_GENERATE_QSTRDEFS_COLLECTED2}")
execute_process ( COMMAND bash -c "${COMMAND_GENERATE_QSTRDEFS_PRE}")
execute_process ( COMMAND bash -c "${COMMAND_GENERATE_QSTRDEFS_GEN}")

file(GLOB QSTR_HDR ${CMAKE_CURRENT_BINARY_DIR}/genhdr/*.h)


set(COMMAND_GENERATE_QSTRDEFS_PRE2 "cat ${CMAKE_CURRENT_BINARY_DIR}/py/qstrdefs.h ${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstrdefs.collected.h \\|sed 's/^Q\\(.*\\)/\"&\"/' \\|g++ -E -I${CMAKE_CURRENT_BINARY_DIR} -DSTATIC=\"\" - \\|sed 's/^\"\\\\(Q(.*)\\\\)\"/\\\\1/' >${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstrdefs.preprocessed.h")

add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstrdefs.generated.h
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/mission/${MISSION}/pus_obcp_userFunctions.c ${CMAKE_CURRENT_BINARY_DIR}pus_obcp_userFunctions.c
    COMMAND bash -c "rm -rf ${CMAKE_CURRENT_BINARY_DIR}/genhdr/*"
    COMMAND bash -c "${COMMAND_GENERATE_MPVERSION}"
    COMMAND bash -c "${COMMAND_GENERATE_QSTRLAST}"
    COMMAND bash -c "${COMMAND_GENERATE_QSTRDEFS_COLLECTED1}"
    COMMAND bash -c "${COMMAND_GENERATE_QSTRDEFS_COLLECTED2}"
    COMMAND bash -c "${COMMAND_GENERATE_QSTRDEFS_PRE2}"
    COMMAND bash -c "${COMMAND_GENERATE_QSTRDEFS_GEN}"
    DEPENDS ${CMAKE_SOURCE_DIR}/mission/${MISSION}/pus_obcp_userFunctions.c
    COMMENT "Generating12 ${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstrdefs.generated.h"
)
ADD_CUSTOM_TARGET(qstrdefs.generated_${MISSION} DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstrdefs.generated.h")
    
#gcc -c -DSTATIC="" -g  -I. -std=c99 -Wno-switch -Wno-override-init -Wno-jump-misses-init -DPOSIX -D_POSIX_SOURCE -D_GNU_SOURCE -g -Wall -Wextra -fdiagnostics-show-option -Wcast-align *.c
file(GLOB UPY_CORE_SRC ${CMAKE_CURRENT_BINARY_DIR}/*.c )



#
# Create esrocos_mpy libraary
#

#${CMAKE_BINARY_DIR}/mission/${MISSION}/asn1/esrocos_pustypes_${MISSION}

# Static
add_library(esrocos_mpy_static_core_${MISSION} STATIC ${UPY_CORE_SRC})
set_target_properties(esrocos_mpy_static_core_${MISSION} PROPERTIES OUTPUT_NAME esrocos_mpy_core_${MISSION})
target_link_libraries(esrocos_mpy_static_core_${MISSION} m)
set_target_properties(esrocos_mpy_static_core_${MISSION} PROPERTIES 
    LINKER_LANGUAGE C
    POSITION_INDEPENDENT_CODE TRUE
)
target_include_directories(esrocos_mpy_static_core_${MISSION} PUBLIC ${esrocos_pustypes_${MISSION}_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_SOURCE_DIR}/mission/${MISSION}/)

# Shared
if(NOT CMAKE_CROSSCOMPILING)
    add_library(esrocos_mpy_core_${MISSION} SHARED ${UPY_CORE_SRC})
    target_link_libraries(esrocos_mpy_core_${MISSION} m)
    set_target_properties(esrocos_mpy_core_${MISSION} PROPERTIES 
        LINKER_LANGUAGE C
        POSITION_INDEPENDENT_CODE TRUE
    )
    target_include_directories(esrocos_mpy_core_${MISSION} PUBLIC ${esrocos_pustypes_${MISSION}_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_SOURCE_DIR}/mission/${MISSION}/)
endif()


#
# Installation
#

if(CMAKE_CROSSCOMPILING)
    set(TARGET_INSTALL_PREFIX "${RTEMS_TARGET}/")
    set(TARGETS_TO_INSTALL esrocos_mpy_static_core_${MISSION})
else()
    set(TARGET_INSTALL_PREFIX "")
    set(TARGETS_TO_INSTALL esrocos_mpy_core_${MISSION} esrocos_mpy_static_core_${MISSION})
endif()

install(TARGETS ${TARGETS_TO_INSTALL}
    RUNTIME DESTINATION "${TARGET_INSTALL_PREFIX}bin"
    LIBRARY DESTINATION "${TARGET_INSTALL_PREFIX}lib"
    ARCHIVE DESTINATION "${TARGET_INSTALL_PREFIX}lib"
)

install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/ DESTINATION include/pus/mission/${MISSION}/mpy)


#TODO TASTE INCLUDES
file(GLOB TASTE_INCLUDES
    ${CMAKE_CURRENT_BINARY_DIR}/*.h )

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/)
foreach(file ${TASTE_INCLUDES})
    #configure_file(${file} ${CMAKE_CURRENT_BINARY_DIR}/include/ COPYONLY)
    file(COPY ${file} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/include/)
endforeach(file $(TASTE_INCLUDES))

file(GLOB TASTE_INCLUDES
    ${CMAKE_CURRENT_BINARY_DIR}/py/*.h )
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/py)
foreach(file ${TASTE_INCLUDES})
    #configure_file(${file} ${CMAKE_CURRENT_BINARY_DIR}/include/py/ COPYONLY)
    file(COPY ${file} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/include/py/)
endforeach(file $(TASTE_INCLUDES))

file(GLOB TASTE_INCLUDES
    ${CMAKE_CURRENT_BINARY_DIR}/genhdr/*.h )
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/genhdr)
foreach(file ${TASTE_INCLUDES})
    #configure_file(${file} ${CMAKE_CURRENT_BINARY_DIR}/include/genhdr/ COPYONLY)
    file(COPY ${file} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/include/genhdr/)
endforeach(file $(TASTE_INCLUDES))


