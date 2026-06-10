# Copyright (c) 2026 Kivo Project. All rights reserved.
# SPDX-License-Identifier: MIT
add_executable(kivo_demuxer_contracts_tests
    demuxer_core_tests.cpp
    demuxer_seek_tests.cpp
    demuxer_policy_tests.cpp
)
target_link_libraries(kivo_demuxer_contracts_tests PRIVATE kivo_demuxer_contracts)
target_compile_features(kivo_demuxer_contracts_tests PRIVATE cxx_std_23)
add_test(NAME kivo_demuxer_contracts_tests COMMAND kivo_demuxer_contracts_tests)
