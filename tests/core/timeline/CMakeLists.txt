# Copyright (c) 2026 Kivo Project. All rights reserved.
# tests/core/timeline/CMakeLists.txt - Timeline contracts tests.

add_executable(kivo_core_timeline_tests
    timeline_core_tests.cpp
    timeline_seek_tests.cpp
    timeline_compensation_rate_tests.cpp
)

target_link_libraries(kivo_core_timeline_tests PRIVATE
    kivo_core_timeline
)

add_test(NAME kivo_core_timeline_tests COMMAND kivo_core_timeline_tests)

target_compile_options(kivo_core_timeline_tests PRIVATE
    /W4 /WX
)
