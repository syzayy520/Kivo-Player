add_executable(kivo_playback_timeline_public_surface_boundary_tests
    timeline_public_surface_boundary_identity_tests.cpp
    timeline_public_surface_boundary_anchor_tests.cpp
    timeline_public_surface_boundary_classification_tests.cpp
    timeline_public_surface_boundary_boundary_tests.cpp
    timeline_public_surface_boundary_outcome_tests.cpp
    timeline_public_surface_boundary_boundary_contract_tests.cpp
)

target_compile_features(kivo_playback_timeline_public_surface_boundary_tests
    PRIVATE cxx_std_23
)

target_link_libraries(kivo_playback_timeline_public_surface_boundary_tests
    PRIVATE
    kivo_playback_timeline_public_surface_boundary
)

add_test(
    NAME kivo_playback_timeline_public_surface_boundary_tests
    COMMAND kivo_playback_timeline_public_surface_boundary_tests
)
