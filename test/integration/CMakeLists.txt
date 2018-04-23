# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

# CMake modules
find_package(CUnit REQUIRED)

# Library of ASN.1 types
# The library esrocos_pus depends on integration_test_types. In the executables below, we must include both in the 
# target_link_libraries for the executables so that the correct library link order is used.
add_library(integration_test_types STATIC ${esrocos_pustypes_C_SOURCES})

# Test executables
add_executable(test_integration_01 test_integration_01.c)
target_link_libraries(test_integration_01 esrocos_pus_test_01 esrocos_pus integration_test_types ${CUNIT_LIBRARIES})
target_include_directories(test_integration_01 PUBLIC ${CUNIT_INCLUDE_DIRS})
add_coverage(test_integration_01)

# Add tests
enable_testing() # once
add_test(integration_01 test_integration_01)

