# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

# CMake modules
find_package(CUnit REQUIRED)

# Test executables
add_executable(test_integration_01 test_integration_01.c)
target_link_libraries(test_integration_01 esrocos_pus esrocos_pus_asn1 esrocos_pus_asn1common esrocos_pus_mission_test_01 ${CUNIT_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(test_integration_01 PUBLIC ${CUNIT_INCLUDE_DIRS})
add_coverage(test_integration_01)

# Add tests
enable_testing() # once
add_test(integration_01 test_integration_01)

