# CMakeLists.txt has to be located in the project folder and cmake has to be
# executed from 'project/build' with 'cmake ../'.

cmake_minimum_required(VERSION 3.3)
# required version 3.3: provides "IN_LIST" operator in if()

### Autoproj and SARGON stuff commented ###

# Check autoproj environment
#if (NOT DEFINED ENV{AUTOPROJ_CURRENT_ROOT})
#    message(FATAL_ERROR "Environment variable AUTOPROJ_CURRENT_ROOT not set. Run env.sh.")
#endif()

#find_package(Sargon)

#set(SARGON_USE_CXX11 TRUE)
#set(CMAKE_BUILD_TYPE $ENV{CMAKE_BUILD_TYPE})
#set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#sargon_init(asn1_types 1.0)
#sargon_standard_layout()

###########################################


project(ESROCOS_PUS LANGUAGES C CXX)

#
# CMake modules
#

# Local directory with CMake modules
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules;${CMAKE_MODULE_PATH}")
set(pybind11_DIR ${CMAKE_SOURCE_DIR}/cmake/PyBind11)
# codecov module
find_package(codecov REQUIRED)
if (NOT ENABLE_COVERAGE)
	message(STATUS "Configure with -DENABLE_COVERAGE=On to collect coverage metrics")
endif()

# Include for tests automation
include(CTest)

# Find libpthread
find_package(Threads REQUIRED)
find_package(pybind11 CONFIG)

add_compile_options(-Wall -Wextra)

# Location of the generated ASN.1 headers
include_directories(include ${CMAKE_BINARY_DIR}/asn1/generated)

add_subdirectory(asn1)
add_subdirectory(doc)
add_subdirectory(python)
add_subdirectory(mission)
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(pylib)

### Install stuff commented ###

#install(DIRECTORY ${CMAKE_SOURCE_DIR}/asn/base DESTINATION share/taste/asn1_types)
#install(DIRECTORY ${CMAKE_SOURCE_DIR}/asn/drivers DESTINATION share/taste/asn1_types)
#install(DIRECTORY ${CMAKE_SOURCE_DIR}/asn/sargon DESTINATION share/taste/asn1_types)

###############################

# The project version number.
set(VERSION_MAJOR   0   CACHE STRING "Project major version number.")
set(VERSION_MINOR   1   CACHE STRING "Project minor version number.")
set(VERSION_PATCH   0   CACHE STRING "Project patch version number.")
mark_as_advanced(VERSION_MAJOR VERSION_MINOR VERSION_PATCH)

coverage_evaluate()
