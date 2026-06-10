# Copyright (c) 2026 Kivo Project. All rights reserved.
add_executable(kivo_format_contracts_tests
    format_identity_tests.cpp
    format_video_audio_tests.cpp
    format_color_tests.cpp
    format_hdr_tests.cpp
    format_compatibility_tests.cpp
)
target_link_libraries(kivo_format_contracts_tests PRIVATE kivo_format_contracts)
target_compile_features(kivo_format_contracts_tests PRIVATE cxx_std_23)
add_test(NAME kivo_format_contracts_tests COMMAND kivo_format_contracts_tests)
