# Copyright (c) 2026 Kivo Project. All rights reserved.
add_executable(kivo_capability_contracts_tests
    capability_scope_tests.cpp
    capability_media_tests.cpp
    capability_memory_tests.cpp
    capability_requirement_tests.cpp
    capability_negotiation_tests.cpp
)
target_link_libraries(kivo_capability_contracts_tests PRIVATE kivo_capability_contracts)
target_compile_features(kivo_capability_contracts_tests PRIVATE cxx_std_23)
add_test(NAME kivo_capability_contracts_tests COMMAND kivo_capability_contracts_tests)
