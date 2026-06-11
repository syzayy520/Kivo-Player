add_library(kivo_playback_p2_public_command_admission INTERFACE)

target_include_directories(kivo_playback_p2_public_command_admission
    INTERFACE
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(kivo_playback_p2_public_command_admission
    INTERFACE
    kivo_playback_p2_public_intake
)
