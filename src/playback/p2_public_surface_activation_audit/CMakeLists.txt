add_library(kivo_playback_p2_public_surface_activation_audit INTERFACE)

target_include_directories(kivo_playback_p2_public_surface_activation_audit
    INTERFACE
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(kivo_playback_p2_public_surface_activation_audit
    INTERFACE
    kivo_playback_p2_public_surface_activation_view
)
