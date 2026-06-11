add_executable(kivo_playback_media_open_public_tests
    media_open_public_identity_tests.cpp
    media_open_public_anchor_tests.cpp
    media_open_public_classification_tests.cpp
    media_open_public_open_tests.cpp
    media_open_public_outcome_tests.cpp
    media_open_public_boundary_tests.cpp
)

target_compile_features(kivo_playback_media_open_public_tests
    PRIVATE cxx_std_23
)

target_link_libraries(kivo_playback_media_open_public_tests
    PRIVATE
    kivo_playback_media_open_public
)

add_test(
    NAME kivo_playback_media_open_public_tests
    COMMAND kivo_playback_media_open_public_tests
)
