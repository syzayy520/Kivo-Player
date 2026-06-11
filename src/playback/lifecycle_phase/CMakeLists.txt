add_library(kivo_playback_lifecycle_phase INTERFACE)

target_include_directories(kivo_playback_lifecycle_phase
    INTERFACE
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(kivo_playback_lifecycle_phase
    INTERFACE
    kivo_playback_timeline_public_surface_boundary
)
