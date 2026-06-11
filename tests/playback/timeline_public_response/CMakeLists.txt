add_executable(kivo_playback_timeline_public_response_tests
    timeline_public_response_identity_tests.cpp
    timeline_public_response_anchor_tests.cpp
    timeline_public_response_classification_tests.cpp
    timeline_public_response_response_tests.cpp
    timeline_public_response_outcome_tests.cpp
    timeline_public_response_boundary_tests.cpp
)

target_compile_features(kivo_playback_timeline_public_response_tests
    PRIVATE cxx_std_23
)

target_link_libraries(kivo_playback_timeline_public_response_tests
    PRIVATE
    kivo_playback_timeline_public_response
)

add_test(
    NAME kivo_playback_timeline_public_response_tests
    COMMAND kivo_playback_timeline_public_response_tests
)
