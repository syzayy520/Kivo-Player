add_library(kivo_playback_p2_public_surface_commitment_view INTERFACE)

target_include_directories(kivo_playback_p2_public_surface_commitment_view
    INTERFACE
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(kivo_playback_p2_public_surface_commitment_view
    INTERFACE
    kivo_playback_p2_public_surface_activation_audit
)
