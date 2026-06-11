# Copyright (c) 2026 Kivo Project. All rights reserved.
add_executable(kivo_playback_timeline_decision_tests
    timeline_decision_identity_tests.cpp
    timeline_decision_source_tests.cpp
    timeline_decision_input_tests.cpp
    timeline_decision_policy_tests.cpp
    timeline_decision_routing_tests.cpp
    timeline_decision_outcome_tests.cpp
)
target_link_libraries(kivo_playback_timeline_decision_tests PRIVATE kivo_playback_timeline_decision)
target_compile_features(kivo_playback_timeline_decision_tests PRIVATE cxx_std_23)
add_test(NAME kivo_playback_timeline_decision_tests COMMAND kivo_playback_timeline_decision_tests)
