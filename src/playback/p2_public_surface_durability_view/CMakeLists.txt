add_library(kivo_playback_p2_public_surface_durability_view INTERFACE)

target_include_directories(kivo_playback_p2_public_surface_durability_view
    INTERFACE
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(kivo_playback_p2_public_surface_durability_view
    INTERFACE
    kivo_playback_p2_public_surface_continuity_view
)
