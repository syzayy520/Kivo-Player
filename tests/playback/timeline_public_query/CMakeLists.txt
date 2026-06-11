add_executable(kivo_playback_timeline_public_query_tests
    timeline_public_query_identity_tests.cpp
    timeline_public_query_anchor_tests.cpp
    timeline_public_query_classification_tests.cpp
    timeline_public_query_query_tests.cpp
    timeline_public_query_outcome_tests.cpp
    timeline_public_query_boundary_tests.cpp
)

target_compile_features(kivo_playback_timeline_public_query_tests
    PRIVATE cxx_std_23
)

target_link_libraries(kivo_playback_timeline_public_query_tests
    PRIVATE
    kivo_playback_timeline_public_query
)

add_test(
    NAME kivo_playback_timeline_public_query_tests
    COMMAND kivo_playback_timeline_public_query_tests
)
