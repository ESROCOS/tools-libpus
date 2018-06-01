# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

# CMake modules
find_package(CUnit REQUIRED)

# Test executables
add_executable(test_integration_01 test_integration_01.c)
target_link_libraries(test_integration_01 esrocos_pus_test_01_static esrocos_pus_static_core_test_01 esrocos_pus_test_01_types_static ${CUNIT_LIBRARIES})
target_include_directories(test_integration_01 PUBLIC ${CUNIT_INCLUDE_DIRS})
add_coverage(test_integration_01)

# Add tests
enable_testing() # once
add_test(integration_01 test_integration_01)

