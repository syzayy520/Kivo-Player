add_executable(kivo_playback_session_public_tests
    playback_session_public_identity_tests.cpp
    playback_session_public_anchor_tests.cpp
    playback_session_public_classification_tests.cpp
    playback_session_public_session_tests.cpp
    playback_session_public_outcome_tests.cpp
    playback_session_public_boundary_tests.cpp
)

target_compile_features(kivo_playback_session_public_tests
    PRIVATE cxx_std_23
)

target_link_libraries(kivo_playback_session_public_tests
    PRIVATE
    kivo_playback_session_public
)

add_test(
    NAME kivo_playback_session_public_tests
    COMMAND kivo_playback_session_public_tests
)
