# Copyright (c) 2026 Kivo Project. All rights reserved.
# src/pipeline/model/probe/CMakeLists.txt - Media Probe Model (header-only interface library).

add_library(kivo_pipeline_probe_model INTERFACE)
target_include_directories(kivo_pipeline_probe_model INTERFACE
    ${PROJECT_SOURCE_DIR}/src
)
target_link_libraries(kivo_pipeline_probe_model INTERFACE
    kivo_pipeline_contracts
)
target_compile_features(kivo_pipeline_probe_model INTERFACE cxx_std_23)
