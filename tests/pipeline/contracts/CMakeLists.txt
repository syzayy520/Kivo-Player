# Copyright (c) 2026 Kivo Project. All rights reserved.
# tests/pipeline/contracts/CMakeLists.txt - Pipeline Contracts tests.

# Pipeline Contracts - compile tests (lightweight self-check style, no Google Test)
add_executable(kivo_pipeline_contract_tests
    pipeline_root_contract_tests.cpp
    probe_contract_tests.cpp
    demux_contract_tests.cpp
    stream_contract_tests.cpp
    packet_contract_tests.cpp
    queue_contract_tests.cpp
    lifecycle_contract_tests.cpp
    flow_contract_tests.cpp
)

target_link_libraries(kivo_pipeline_contract_tests PRIVATE
    kivo_pipeline_contracts
)

add_test(NAME kivo_pipeline_contract_tests COMMAND kivo_pipeline_contract_tests)

# Strict warnings (inherit from P0-001)
target_compile_options(kivo_pipeline_contract_tests PRIVATE
    /W4 /WX
)
