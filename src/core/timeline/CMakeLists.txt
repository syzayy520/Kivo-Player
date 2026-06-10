# Copyright (c) 2026 Kivo Project. All rights reserved.
# src/core/timeline/CMakeLists.txt - Timeline contracts (header-only interface library).

add_library(kivo_core_timeline INTERFACE)
target_include_directories(kivo_core_timeline INTERFACE
    ${PROJECT_SOURCE_DIR}/src
)
target_compile_features(kivo_core_timeline INTERFACE cxx_std_23)
