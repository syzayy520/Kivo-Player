# Copyright (c) 2026 Kivo Project. All rights reserved.
add_executable(kivo_playback_control_tests
    control_identity_tests.cpp
    control_source_tests.cpp
    playback_control_command_tests.cpp
    playback_control_target_tests.cpp
    control_normalization_tests.cpp
    control_outcome_tests.cpp
)
target_link_libraries(kivo_playback_control_tests PRIVATE kivo_playback_control)
target_compile_features(kivo_playback_control_tests PRIVATE cxx_std_23)
add_test(NAME kivo_playback_control_tests COMMAND kivo_playback_control_tests)
