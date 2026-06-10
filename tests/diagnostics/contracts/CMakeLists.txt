# Copyright (c) 2026 Kivo Project. All rights reserved.
add_executable(kivo_diagnostics_contracts_tests
    diagnostic_identity_tests.cpp
    diagnostic_severity_tests.cpp
    diagnostic_event_tests.cpp
    diagnostic_trace_tests.cpp
    telemetry_sample_tests.cpp
    diagnostic_outcome_tests.cpp
)
target_link_libraries(kivo_diagnostics_contracts_tests PRIVATE kivo_diagnostics_contracts)
target_compile_features(kivo_diagnostics_contracts_tests PRIVATE cxx_std_23)
add_test(NAME kivo_diagnostics_contracts_tests COMMAND kivo_diagnostics_contracts_tests)
