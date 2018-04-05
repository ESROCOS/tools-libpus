#mpy (python core things)

#MESSAGE(STATUS "CXX: $ENV{CXX}")

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
	mpcontext.h
	pus_testmodule.c
	pus_obcpFunctions.c
	mpconfigport.h
)
foreach(file ${SRC_FILES})
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/../src/${file} ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
endforeach(file $(SRC_FILES))


#Coping userFunctions.c (from mission or src(default))
SET(MISSION_NAME "test_01")
if(EXISTS "${CMAKE_SOURCE_DIR}/mission/${MISSION_NAME}/obcp_userFunctions.c")
   MESSAGE( STATUS "EXISTS obcp_UserFunctions.c in mission")
   configure_file(${CMAKE_SOURCE_DIR}/mission/${MISSION_NAME}/obcp_userFunctions.c ${CMAKE_CURRENT_BINARY_DIR}/pus_userFunctions.c COPYONLY)
else()
	MESSAGE( STATUS "DOESNT EXIST obcp_UserFunctions.c in mission")
   configure_file(${CMAKE_CURRENT_SOURCE_DIR}/../src/pus_userFunctions.c ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
endif()


#Copying configuration files from TASTE ESA port
configure_file(${TASTE_UPY_ESA_PORT}/mphalport_taste_x86.h ${CMAKE_CURRENT_BINARY_DIR}/mphalport.h COPYONLY)
configure_file(${TASTE_UPY_ESA_PORT}/mphalport_taste_x86.c ${CMAKE_CURRENT_BINARY_DIR}/mphalport.c COPYONLY)
configure_file(${TASTE_UPY_ESA_PORT}/mputil.h ${CMAKE_CURRENT_BINARY_DIR}/mputil.h COPYONLY)
configure_file(${TASTE_UPY_ESA_PORT}/mputil.c ${CMAKE_CURRENT_BINARY_DIR}/mputil.c COPYONLY)

#Copy .c files from core uPython
file(GLOB_RECURSE UPY_CORE_SRC
	${TASTE_UPY}/py/*.c )
	
foreach(file ${UPY_CORE_SRC})
	file(RELATIVE_PATH file_name "${TASTE_UPY}/py/" ${file} )
	configure_file(${file} ${CMAKE_CURRENT_BINARY_DIR}/py_${file_name} COPYONLY)
endforeach(file $(UPY_CORE_SRC))

#Copy .h files from core uPython
file(GLOB_RECURSE UPY_CORE_HEADERS
	${TASTE_UPY}/py/*.h )

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/py/)

foreach(file ${UPY_CORE_HEADERS})
	file(RELATIVE_PATH file_name "${TASTE_UPY}/py/" ${file} )
	configure_file(${file} ${CMAKE_CURRENT_BINARY_DIR}/py/${file_name} COPYONLY)
endforeach(file $(UPY_CORE_HEADERS))

#Generate QSTR //TODO

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/genhdr/)

SET( COMMAND_GENERATE_MPVERSION "python ${TASTE_UPY}/py/makeversionhdr.py  ${CMAKE_CURRENT_BINARY_DIR}/genhdr/mpversion.h")
execute_process ( COMMAND bash -c "${COMMAND_GENERATE_MPVERSION}")

file(GLOB_RECURSE UPY_CORE_SRC ${CMAKE_CURRENT_BINARY_DIR}/*.c )
	
foreach(file ${UPY_CORE_SRC})
	SET(FILES "${FILES} ${file}")
endforeach(file $(UPY_CORE_SRC))
#MESSAGE(STATUS ${FILES})

#g++ -E -DNO_QSTR -I . -DSTATIC="" -g  py_*.c mymodule.c > ./genhdr/qstr.i.last -I/home/esrocos/esrocos-ws-pus/tools-libpus/include/ -I/home/esrocos/esrocos-ws-pus/tools-libpus/debug/asn1/generated/ -I/home/esrocos/esrocos-ws-pus/tools-libpus/debug/mission/test_01/generated/include/ 
SET( COMMAND_GENERATE_QSTRLAST "$ENV{CXX} -E -DNO_QSTR -I${CMAKE_CURRENT_BINARY_DIR} -DSTATIC=\"\" ${FILES}  -I/home/esrocos/esrocos-ws-pus/tools-libpus/include/ -I/home/esrocos/esrocos-ws-pus/tools-libpus/debug/asn1/generated/ > ${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstr.i.last")
#MESSAGE(STATUS ${COMMAND_GENERATE_QSTRLAST})
execute_process ( COMMAND bash -c "${COMMAND_GENERATE_QSTRLAST}")

# Process the output from the C preprocessor and extracts all qstr. Each qstr is transformed into a qstr definition of the form 'Q(...)'
#python $(taste-config --prefix)/../tool-src/upython-taste/py/makeqstrdefs.py split ./genhdr/qstr.i.last ./genhdr/qstr ./genhdr/qstrdefs.collected.h
SET( COMMAND_GENERATE_QSTRDEFS_COLLECTED1 "python ${TASTE_UPY}/py/makeqstrdefs.py split ${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstr.i.last ${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstr ${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstrdefs.collected.h")
#MESSAGE(STATUS ${COMMAND_GENERATE_QSTRDEFS_COLLECTED1})
execute_process ( COMMAND bash -c "${COMMAND_GENERATE_QSTRDEFS_COLLECTED1}")

#python $(taste-config --prefix)/../tool-src/upython-taste/py/makeqstrdefs.py cat ./genhdr/qstr.i.last ./genhdr/qstr ./genhdr/qstrdefs.collected.h
SET( COMMAND_GENERATE_QSTRDEFS_COLLECTED2 "python ${TASTE_UPY}/py/makeqstrdefs.py cat ${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstr.i.last ${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstr ${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstrdefs.collected.h")
#MESSAGE(STATUS ${COMMAND_GENERATE_QSTRDEFS_COLLECTED2})
execute_process ( COMMAND bash -c "${COMMAND_GENERATE_QSTRDEFS_COLLECTED2}")

# From qstrdefs.collected to qstrdefs.preprocessed
#cat ./py/qstrdefs.h ./genhdr/qstrdefs.collected.h | sed 's/^Q(.*)/"&"/' | g++ -E -I. -DSTATIC="" -g - | sed 's/^"\(Q(.*)\)"/\1/' > ./genhdr/qstrdefs.preprocessed.h
SET( COMMAND_GENERATE_QSTRDEFS_PRE "cat ${CMAKE_CURRENT_BINARY_DIR}/py/qstrdefs.h ${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstrdefs.collected.h | sed 's/^Q(.*)/\"&\"/' | g++ -E -I${CMAKE_CURRENT_BINARY_DIR} -DSTATIC=\"\" - | sed 's/^\"\\(Q(.*)\\)\"/\\1/' > ${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstrdefs.preprocessed.h")
#MESSAGE(STATUS ${COMMAND_GENERATE_QSTRDEFS_PRE})
execute_process ( COMMAND bash -c "${COMMAND_GENERATE_QSTRDEFS_PRE}")

# From qstrdefs.preprocessed to qstrdefs.generated (hex code)
#python $(taste-config --prefix)/../tool-src/upython-taste/py/makeqstrdata.py ./genhdr/qstrdefs.preprocessed.h > ./genhdr/qstrdefs.generated.h
SET( COMMAND_GENERATE_QSTRDEFS_GEN "python ${TASTE_UPY}/py/makeqstrdata.py ${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstrdefs.preprocessed.h > ${CMAKE_CURRENT_BINARY_DIR}/genhdr/qstrdefs.generated.h")
#MESSAGE(STATUS ${COMMAND_GENERATE_QSTRDEFS_GEN})
execute_process ( COMMAND bash -c "${COMMAND_GENERATE_QSTRDEFS_GEN}")

#gcc -c -DSTATIC="" -g  -I. -std=c99 -Wno-switch -Wno-override-init -Wno-jump-misses-init -DPOSIX -D_POSIX_SOURCE -D_GNU_SOURCE -g -Wall -Wextra -fdiagnostics-show-option -Wcast-align *.c
file(GLOB_RECURSE UPY_CORE_SRC
	${CMAKE_CURRENT_BINARY_DIR}/*.c )
	
include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_library(esrocos_mpy SHARED ${UPY_CORE_SRC})
set_target_properties(esrocos_mpy PROPERTIES LINKER_LANGUAGE C)
set_target_properties(esrocos_mpy PROPERTIES POSITION_INDEPENDENT_CODE TRUE)
add_dependencies(esrocos_mpy esrocos_pus)

#TODO TASTE INCLUDES
file(GLOB TASTE_INCLUDES
	${CMAKE_CURRENT_BINARY_DIR}/*.h )

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/)
foreach(file ${TASTE_INCLUDES})
	configure_file(${file} ${CMAKE_CURRENT_BINARY_DIR}/include/ COPYONLY)
endforeach(file $(TASTE_INCLUDES))

file(GLOB TASTE_INCLUDES
	${CMAKE_CURRENT_BINARY_DIR}/py/*.h )
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/py)
foreach(file ${TASTE_INCLUDES})
	configure_file(${file} ${CMAKE_CURRENT_BINARY_DIR}/include/py/ COPYONLY)
endforeach(file $(TASTE_INCLUDES))

file(GLOB TASTE_INCLUDES
	${CMAKE_CURRENT_BINARY_DIR}/genhdr/*.h )
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/genhdr)
foreach(file ${TASTE_INCLUDES})
	configure_file(${file} ${CMAKE_CURRENT_BINARY_DIR}/include/genhdr/ COPYONLY)
endforeach(file $(TASTE_INCLUDES))


