add_executable(kivo_playback_p2_public_readback_tests
    p2_public_readback_identity_tests.cpp
    p2_public_readback_anchor_tests.cpp
    p2_public_readback_classification_tests.cpp
    p2_public_readback_readback_tests.cpp
    p2_public_readback_outcome_tests.cpp
    p2_public_readback_boundary_tests.cpp
)

target_link_libraries(kivo_playback_p2_public_readback_tests PRIVATE kivo_playback_p2_public_readback)
add_test(NAME kivo_playback_p2_public_readback_tests COMMAND kivo_playback_p2_public_readback_tests)
