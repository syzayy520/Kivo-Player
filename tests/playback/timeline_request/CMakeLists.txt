# Copyright (c) 2026 Kivo Project. All rights reserved.
add_executable(kivo_playback_timeline_request_tests
    timeline_request_identity_tests.cpp
    timeline_request_source_tests.cpp
    timeline_request_target_tests.cpp
    timeline_request_policy_tests.cpp
    timeline_request_normalization_tests.cpp
    timeline_request_outcome_tests.cpp
)
target_link_libraries(kivo_playback_timeline_request_tests PRIVATE kivo_playback_timeline_request)
target_compile_features(kivo_playback_timeline_request_tests PRIVATE cxx_std_23)
add_test(NAME kivo_playback_timeline_request_tests COMMAND kivo_playback_timeline_request_tests)
