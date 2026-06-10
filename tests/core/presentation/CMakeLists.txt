# Copyright (c) 2026 Kivo Project. All rights reserved.
add_executable(kivo_core_presentation_tests
    presentation_core_tests.cpp
    presentation_queue_tests.cpp
    presentation_policy_tests.cpp
)
target_link_libraries(kivo_core_presentation_tests PRIVATE kivo_core_presentation)
add_test(NAME kivo_core_presentation_tests COMMAND kivo_core_presentation_tests)
target_compile_options(kivo_core_presentation_tests PRIVATE /W4 /WX)
