# Copyright (c) 2026 Kivo Project. All rights reserved.
# src/core/clock/CMakeLists.txt - Clock Domain contracts (header-only interface library).

add_library(kivo_core_clock INTERFACE)
target_include_directories(kivo_core_clock INTERFACE
    ${PROJECT_SOURCE_DIR}/src
)
target_compile_features(kivo_core_clock INTERFACE cxx_std_23)
