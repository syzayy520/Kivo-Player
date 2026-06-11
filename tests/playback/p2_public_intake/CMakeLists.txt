add_executable(kivo_playback_p2_public_intake_tests
    p2_public_intake_identity_tests.cpp
    p2_public_intake_anchor_tests.cpp
    p2_public_intake_classification_tests.cpp
    p2_public_intake_intake_tests.cpp
    p2_public_intake_outcome_tests.cpp
    p2_public_intake_boundary_tests.cpp
)

target_link_libraries(kivo_playback_p2_public_intake_tests PRIVATE kivo_playback_p2_public_intake)
add_test(NAME kivo_playback_p2_public_intake_tests COMMAND kivo_playback_p2_public_intake_tests)
