# Copyright (c) 2026 Kivo Project. All rights reserved.
add_executable(kivo_playback_timeline_error_surface_tests
    timeline_error_identity_tests.cpp
    timeline_error_anchor_tests.cpp
    timeline_error_classification_tests.cpp
    timeline_error_surface_tests.cpp
    timeline_error_outcome_tests.cpp
    timeline_error_boundary_tests.cpp
)
target_link_libraries(kivo_playback_timeline_error_surface_tests PRIVATE kivo_playback_timeline_error_surface)
target_compile_features(kivo_playback_timeline_error_surface_tests PRIVATE cxx_std_23)
add_test(NAME kivo_playback_timeline_error_surface_tests COMMAND kivo_playback_timeline_error_surface_tests)
