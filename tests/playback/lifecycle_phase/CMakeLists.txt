add_executable(kivo_playback_lifecycle_phase_tests
    playback_lifecycle_phase_identity_tests.cpp
    playback_lifecycle_phase_anchor_tests.cpp
    playback_lifecycle_phase_classification_tests.cpp
    playback_lifecycle_phase_phase_tests.cpp
    playback_lifecycle_phase_outcome_tests.cpp
    playback_lifecycle_phase_boundary_tests.cpp
)

target_compile_features(kivo_playback_lifecycle_phase_tests
    PRIVATE cxx_std_23
)

target_link_libraries(kivo_playback_lifecycle_phase_tests
    PRIVATE
    kivo_playback_lifecycle_phase
)

add_test(
    NAME kivo_playback_lifecycle_phase_tests
    COMMAND kivo_playback_lifecycle_phase_tests
)
