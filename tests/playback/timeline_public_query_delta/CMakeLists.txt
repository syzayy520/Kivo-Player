add_executable(kivo_playback_timeline_public_query_delta_tests
    timeline_public_query_delta_identity_tests.cpp
    timeline_public_query_delta_anchor_tests.cpp
    timeline_public_query_delta_classification_tests.cpp
    timeline_public_query_delta_query_delta_tests.cpp
    timeline_public_query_delta_outcome_tests.cpp
    timeline_public_query_delta_boundary_tests.cpp
)

target_compile_features(kivo_playback_timeline_public_query_delta_tests
    PRIVATE cxx_std_23
)

target_link_libraries(kivo_playback_timeline_public_query_delta_tests
    PRIVATE
    kivo_playback_timeline_public_query_delta
)

add_test(
    NAME kivo_playback_timeline_public_query_delta_tests
    COMMAND kivo_playback_timeline_public_query_delta_tests
)
