add_library(kivo_playback_p2_public_surface_snapshot INTERFACE)

target_include_directories(kivo_playback_p2_public_surface_snapshot
    INTERFACE
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(kivo_playback_p2_public_surface_snapshot
    INTERFACE
    kivo_playback_p2_public_surface_observation
)
