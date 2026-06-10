# Copyright (c) 2026 Kivo Project. All rights reserved.
# src/pipeline/model/packet_flow/CMakeLists.txt - Packet Flow Model (header-only interface library).

add_library(kivo_pipeline_packet_flow INTERFACE)
target_include_directories(kivo_pipeline_packet_flow INTERFACE
    ${PROJECT_SOURCE_DIR}/src
)
target_link_libraries(kivo_pipeline_packet_flow INTERFACE
    kivo_pipeline_contracts
)
target_compile_features(kivo_pipeline_packet_flow INTERFACE cxx_std_23)
