add_executable(kivo_playback_buffering_public_tests
    buffering_public_identity_tests.cpp
    buffering_public_anchor_tests.cpp
    buffering_public_classification_tests.cpp
    buffering_public_buffering_tests.cpp
    buffering_public_outcome_tests.cpp
    buffering_public_boundary_tests.cpp
)

target_link_libraries(kivo_playback_buffering_public_tests PRIVATE kivo_playback_buffering_public)
add_test(NAME kivo_playback_buffering_public_tests COMMAND kivo_playback_buffering_public_tests)
