# CMakeLists.txt has to be located in the project folder and cmake has to be
# executed from 'project/build' with 'cmake ../'.
cmake_minimum_required(VERSION 2.6)

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



project(ESROCOS_PUS)

add_subdirectory(asn1)
add_subdirectory(src)


### Install stuff commenged ###

#install(DIRECTORY ${CMAKE_SOURCE_DIR}/asn/base DESTINATION share/taste/asn1_types)
#install(DIRECTORY ${CMAKE_SOURCE_DIR}/asn/drivers DESTINATION share/taste/asn1_types)
#install(DIRECTORY ${CMAKE_SOURCE_DIR}/asn/sargon DESTINATION share/taste/asn1_types)

###############################

