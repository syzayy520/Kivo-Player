# Copyright (c) 2026 Kivo Project. All rights reserved.
add_executable(kivo_playback_timeline_chain_integrity_tests
    timeline_chain_identity_tests.cpp
    timeline_chain_anchor_tests.cpp
    timeline_chain_policy_tests.cpp
    timeline_chain_integrity_tests.cpp
    timeline_chain_outcome_tests.cpp
    timeline_chain_boundary_tests.cpp
)
target_link_libraries(kivo_playback_timeline_chain_integrity_tests PRIVATE kivo_playback_timeline_chain_integrity)
target_compile_features(kivo_playback_timeline_chain_integrity_tests PRIVATE cxx_std_23)
add_test(NAME kivo_playback_timeline_chain_integrity_tests COMMAND kivo_playback_timeline_chain_integrity_tests)
