# Copyright (c) 2026 Kivo Project. All rights reserved.
add_executable(kivo_device_contracts_tests
    device_identity_tests.cpp
    device_state_tests.cpp
    device_event_tests.cpp
    device_recovery_tests.cpp
    device_policy_tests.cpp
)
target_link_libraries(kivo_device_contracts_tests PRIVATE kivo_device_contracts)
target_compile_features(kivo_device_contracts_tests PRIVATE cxx_std_23)
add_test(NAME kivo_device_contracts_tests COMMAND kivo_device_contracts_tests)
