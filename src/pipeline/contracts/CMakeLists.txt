# Copyright (c) 2026 Kivo Project. All rights reserved.
# src/pipeline/contracts/CMakeLists.txt - Pipeline Contracts (header-only interface library).

# Pipeline Contracts - header-only interface library
add_library(kivo_pipeline_contracts INTERFACE)
target_include_directories(kivo_pipeline_contracts INTERFACE
    ${PROJECT_SOURCE_DIR}/src
)
target_compile_features(kivo_pipeline_contracts INTERFACE cxx_std_23)

# No add_subdirectory(tests) here - tests are added from root CMakeLists.txt
# This CMakeLists.txt only defines the interface library for pipeline contracts.
