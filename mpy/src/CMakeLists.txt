#src (our part of the port)

MESSAGE ("HELLO FROM SRC!! copying")

set(SOURCES
	mpcontext.c
	testmodule.c
)

set(HEADERS
	mpconfigport.h
	mpcontext.h
)


#foreach(file ${SOURCES})
#	configure_file(${CMAKE_SOURCE_DIR}/src/${file} ${CMAKE_BINARY_DIR}/mpy/ COPYONLY)
#endforeach(file $(SOURCES))

#foreach(file ${HEADERS})
#	configure_file(${CMAKE_SOURCE_DIR}/src/${file} ${CMAKE_BINARY_DIR}/mpy/ COPYONLY)
#endforeach(file $(HEADERS))
