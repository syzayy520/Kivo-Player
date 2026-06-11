add_library(kivo_playback_seek_public INTERFACE)

target_include_directories(kivo_playback_seek_public
    INTERFACE
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(kivo_playback_seek_public
    INTERFACE
    kivo_playback_stream_selection_public
)
