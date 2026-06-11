# Copyright (c) 2026 Kivo Project. All rights reserved.
add_executable(kivo_playback_timeline_result_tests
    timeline_result_identity_tests.cpp
    timeline_result_source_tests.cpp
    timeline_result_input_tests.cpp
    timeline_result_policy_tests.cpp
    timeline_result_report_tests.cpp
    timeline_result_outcome_tests.cpp
)
target_link_libraries(kivo_playback_timeline_result_tests PRIVATE kivo_playback_timeline_result)
target_compile_features(kivo_playback_timeline_result_tests PRIVATE cxx_std_23)
add_test(NAME kivo_playback_timeline_result_tests COMMAND kivo_playback_timeline_result_tests)
