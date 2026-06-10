# Copyright (c) 2026 Kivo Project. All rights reserved.
# tests/decoder/contracts/CMakeLists.txt - Decode Contracts tests.

add_executable(kivo_decoder_contract_tests
    decode_frame_sample_tests.cpp
    decode_control_tests.cpp
    decode_result_error_tests.cpp
)

target_link_libraries(kivo_decoder_contract_tests PRIVATE
    kivo_decoder_contracts
)

add_test(NAME kivo_decoder_contract_tests COMMAND kivo_decoder_contract_tests)

target_compile_options(kivo_decoder_contract_tests PRIVATE
    /W4 /WX
)
