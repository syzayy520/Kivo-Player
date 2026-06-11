# Copyright (c) 2026 Kivo Project. All rights reserved.
add_executable(kivo_playback_timeline_state_summary_tests
    timeline_state_identity_tests.cpp
    timeline_state_source_tests.cpp
    timeline_state_input_tests.cpp
    timeline_state_policy_tests.cpp
    timeline_state_summary_tests.cpp
    timeline_state_outcome_tests.cpp
)
target_link_libraries(kivo_playback_timeline_state_summary_tests PRIVATE kivo_playback_timeline_state_summary)
target_compile_features(kivo_playback_timeline_state_summary_tests PRIVATE cxx_std_23)
add_test(NAME kivo_playback_timeline_state_summary_tests COMMAND kivo_playback_timeline_state_summary_tests)
