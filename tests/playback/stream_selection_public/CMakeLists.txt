add_executable(kivo_playback_stream_selection_public_tests
    stream_selection_public_identity_tests.cpp
    stream_selection_public_anchor_tests.cpp
    stream_selection_public_classification_tests.cpp
    stream_selection_public_selection_tests.cpp
    stream_selection_public_outcome_tests.cpp
    stream_selection_public_boundary_tests.cpp
)

target_compile_features(kivo_playback_stream_selection_public_tests
    PRIVATE cxx_std_23
)

target_link_libraries(kivo_playback_stream_selection_public_tests
    PRIVATE
    kivo_playback_stream_selection_public
)

add_test(
    NAME kivo_playback_stream_selection_public_tests
    COMMAND kivo_playback_stream_selection_public_tests
)
