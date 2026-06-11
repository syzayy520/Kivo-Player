add_library(kivo_playback_timeline_public_query_delta INTERFACE)

target_include_directories(kivo_playback_timeline_public_query_delta
    INTERFACE
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(kivo_playback_timeline_public_query_delta
    INTERFACE
    kivo_playback_timeline_public_query
    kivo_playback_timeline_public_delta
    kivo_playback_p2_public_surface_final_audit
)

target_compile_features(kivo_playback_timeline_public_query_delta INTERFACE cxx_std_23)
