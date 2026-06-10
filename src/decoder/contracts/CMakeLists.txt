# Copyright (c) 2026 Kivo Project. All rights reserved.
# src/decoder/contracts/CMakeLists.txt - Decode Contracts (header-only interface library).

add_library(kivo_decoder_contracts INTERFACE)
target_include_directories(kivo_decoder_contracts INTERFACE
    ${PROJECT_SOURCE_DIR}/src
)
target_compile_features(kivo_decoder_contracts INTERFACE cxx_std_23)
