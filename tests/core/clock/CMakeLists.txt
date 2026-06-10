# Copyright (c) 2026 Kivo Project. All rights reserved.
# tests/core/clock/CMakeLists.txt - Clock Domain contracts tests.

add_executable(kivo_core_clock_tests
    clock_domain_tests.cpp
    clock_sync_tests.cpp
    clock_control_tests.cpp
)

target_link_libraries(kivo_core_clock_tests PRIVATE
    kivo_core_clock
)

add_test(NAME kivo_core_clock_tests COMMAND kivo_core_clock_tests)

target_compile_options(kivo_core_clock_tests PRIVATE
    /W4 /WX
)
