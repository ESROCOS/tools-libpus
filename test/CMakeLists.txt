# CUnit library
find_package(CUnit REQUIRED)

# Test executables
add_executable(test_pus_01 test_pus_01.c)
target_link_libraries(test_pus_01 esrocos_pus esrocos_pus_asn1 esrocos_pus_asn1common ${CUNIT_LIBRARIES})
target_include_directories(test_pus_01 PUBLIC ${CUNIT_INCLUDE_DIRS})

# Add tests
enable_testing() # once
add_test(pus_01 test_pus_01)

