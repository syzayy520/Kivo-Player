add_executable(kivo_playback_seek_public_tests
    seek_public_identity_tests.cpp
    seek_public_anchor_tests.cpp
    seek_public_classification_tests.cpp
    seek_public_seek_tests.cpp
    seek_public_outcome_tests.cpp
    seek_public_boundary_tests.cpp
)

target_link_libraries(kivo_playback_seek_public_tests PRIVATE kivo_playback_seek_public)
add_test(NAME kivo_playback_seek_public_tests COMMAND kivo_playback_seek_public_tests)
