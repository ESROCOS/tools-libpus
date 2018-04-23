# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

# CMakeLists.txt has to be located in the project folder and cmake has to be
# executed from 'project/build' with 'cmake ../'.

cmake_minimum_required(VERSION 3.3)
# required version 3.3: provides "IN_LIST" operator in if()


project(pus LANGUAGES C CXX)

include($ENV{ESROCOS_CMAKE})
esrocos_init()

# The project version number (for pkg-config)
set(VERSION_MAJOR   0   CACHE STRING "Project major version number.")
set(VERSION_MINOR   1   CACHE STRING "Project minor version number.")
set(VERSION_PATCH   0   CACHE STRING "Project patch version number.")
mark_as_advanced(VERSION_MAJOR VERSION_MINOR VERSION_PATCH)



#
# Required packages
#

# Code coverage
find_package(codecov REQUIRED)
if (NOT ENABLE_COVERAGE)
	message(STATUS "Configure with -DENABLE_COVERAGE=On to collect coverage metrics")
endif()

# Tests automation
include(CTest)

# POSIX threads
find_package(Threads REQUIRED)

# PyBind11 library for Python-C++ binding (for PUS console)
set(pybind11_DIR "${CMAKE_INSTALL_PREFIX}/cmake_modules/pybind11")
find_package(pybind11 CONFIG)


#
# Global compile settings
#

add_compile_options(-Wall -Wextra)
include_directories(${CMAKE_SOURCE_DIR}/include)


#
# Package components
#

# The PUS library is missionized with the definitions of parameters, events, etc. needed 
# for the application. The PUS library depends on generated code, created from the 
# configurations defined in the mission directory. For this reason, one instance of the
# PUS library is created for each of the mission configurations. In order to do this, 
# the directories src, mpy and pylib are added from the CMakeLists.txt in the mission 
# directory.

add_subdirectory(asn1)
add_subdirectory(doc)
add_subdirectory(python)
add_subdirectory(mission)
add_subdirectory(test)
add_subdirectory(taste)

### Install stuff commented ###

#install(DIRECTORY ${CMAKE_SOURCE_DIR}/asn/base DESTINATION share/taste/asn1_types)
#install(DIRECTORY ${CMAKE_SOURCE_DIR}/asn/drivers DESTINATION share/taste/asn1_types)
#install(DIRECTORY ${CMAKE_SOURCE_DIR}/asn/sargon DESTINATION share/taste/asn1_types)

###############################


coverage_evaluate()



