# Copyright (c) 2026 Kivo Project. All rights reserved.
add_executable(kivo_audio_contracts_tests
    audio_endpoint_tests.cpp
    audio_renderer_tests.cpp
    audio_clock_tests.cpp
    audio_submission_tests.cpp
    audio_passthrough_tests.cpp
    audio_outcome_tests.cpp
)
target_link_libraries(kivo_audio_contracts_tests PRIVATE kivo_audio_contracts)
target_compile_features(kivo_audio_contracts_tests PRIVATE cxx_std_23)
add_test(NAME kivo_audio_contracts_tests COMMAND kivo_audio_contracts_tests)
