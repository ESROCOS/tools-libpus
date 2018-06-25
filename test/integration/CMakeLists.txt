# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

# Test executables
add_executable(test_integration_01 test_integration_01.c)
target_link_libraries(test_integration_01 esrocos_pus_test_01_static esrocos_pus_static_core_test_01 esrocos_pus_test_01_types_static)

if(CMAKE_CROSSCOMPILING)
    target_compile_definitions(test_integration_01 PUBLIC RTEMS_POSIX)
    target_compile_options(test_integration_01 PUBLIC "-pthread")
    target_link_libraries(test_integration_01 "-pthread")
else()
    add_coverage(test_integration_01)
endif()

# Add tests
enable_testing() # once
add_test(integration_01 test_integration_01)

