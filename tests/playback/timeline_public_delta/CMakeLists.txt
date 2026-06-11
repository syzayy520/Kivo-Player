# Copyright (c) 2026 Kivo Project. All rights reserved.
add_executable(kivo_playback_timeline_public_delta_tests
    timeline_public_delta_identity_tests.cpp
    timeline_public_delta_anchor_tests.cpp
    timeline_public_delta_classification_tests.cpp
    timeline_public_delta_delta_tests.cpp
    timeline_public_delta_outcome_tests.cpp
    timeline_public_delta_boundary_tests.cpp
)
target_link_libraries(kivo_playback_timeline_public_delta_tests PRIVATE kivo_playback_timeline_public_delta)
target_compile_features(kivo_playback_timeline_public_delta_tests PRIVATE cxx_std_23)
add_test(NAME kivo_playback_timeline_public_delta_tests COMMAND kivo_playback_timeline_public_delta_tests)
