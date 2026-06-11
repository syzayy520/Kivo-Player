add_library(kivo_playback_session_public INTERFACE)

target_include_directories(kivo_playback_session_public
    INTERFACE
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(kivo_playback_session_public
    INTERFACE
    kivo_playback_lifecycle_phase
)
