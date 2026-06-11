add_library(kivo_playback_timeline_public_query_delta_response INTERFACE)

target_include_directories(kivo_playback_timeline_public_query_delta_response
    INTERFACE
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(kivo_playback_timeline_public_query_delta_response
    INTERFACE
    kivo_playback_timeline_public_query_delta
    kivo_playback_timeline_public_response
    kivo_playback_p2_public_surface_final_audit
)

target_compile_features(kivo_playback_timeline_public_query_delta_response INTERFACE cxx_std_23)
