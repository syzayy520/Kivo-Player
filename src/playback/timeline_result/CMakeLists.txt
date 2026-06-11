# Copyright (c) 2026 Kivo Project. All rights reserved.
add_library(kivo_playback_timeline_result INTERFACE)
target_include_directories(kivo_playback_timeline_result INTERFACE ${PROJECT_SOURCE_DIR}/src)
target_compile_features(kivo_playback_timeline_result INTERFACE cxx_std_23)
