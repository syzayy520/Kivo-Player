# Copyright (c) 2026 Kivo Project. All rights reserved.
# tests/pipeline/model/packet_flow/CMakeLists.txt - Packet Flow Model tests.

add_executable(kivo_pipeline_packet_flow_tests
    packet_sequence_flow_tests.cpp
    lifecycle_control_flow_tests.cpp
    pressure_generation_flow_tests.cpp
)

target_link_libraries(kivo_pipeline_packet_flow_tests PRIVATE
    kivo_pipeline_packet_flow
)

add_test(NAME kivo_pipeline_packet_flow_tests COMMAND kivo_pipeline_packet_flow_tests)

target_compile_options(kivo_pipeline_packet_flow_tests PRIVATE
    /W4 /WX
)
