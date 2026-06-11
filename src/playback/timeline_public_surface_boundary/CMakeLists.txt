add_library(kivo_playback_timeline_public_surface_boundary INTERFACE)

target_include_directories(kivo_playback_timeline_public_surface_boundary
    INTERFACE
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(kivo_playback_timeline_public_surface_boundary
    INTERFACE
    kivo_playback_timeline_public_response
)
