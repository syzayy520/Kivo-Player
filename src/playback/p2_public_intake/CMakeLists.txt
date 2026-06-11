add_library(kivo_playback_p2_public_intake INTERFACE)

target_include_directories(kivo_playback_p2_public_intake
    INTERFACE
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(kivo_playback_p2_public_intake
    INTERFACE
    kivo_playback_p1_public_surface_closure_audit
)
