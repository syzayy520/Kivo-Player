add_library(kivo_playback_public_error_recovery INTERFACE)

target_include_directories(kivo_playback_public_error_recovery
    INTERFACE
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(kivo_playback_public_error_recovery
    INTERFACE
    kivo_playback_end_of_stream_public
)
