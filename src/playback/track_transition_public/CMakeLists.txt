add_library(kivo_playback_track_transition_public INTERFACE)

target_include_directories(kivo_playback_track_transition_public
    INTERFACE
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(kivo_playback_track_transition_public
    INTERFACE
    kivo_playback_buffering_public
)
