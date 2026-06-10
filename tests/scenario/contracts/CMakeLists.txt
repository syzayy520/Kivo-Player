# Copyright (c) 2026 Kivo Project. All rights reserved.
add_executable(kivo_scenario_contracts_tests
    scenario_identity_tests.cpp
    media_case_tests.cpp
    stress_scenario_tests.cpp
    scenario_expectation_tests.cpp
    scenario_risk_tests.cpp
    scenario_outcome_tests.cpp
)
target_link_libraries(kivo_scenario_contracts_tests PRIVATE kivo_scenario_contracts)
target_compile_features(kivo_scenario_contracts_tests PRIVATE cxx_std_23)
add_test(NAME kivo_scenario_contracts_tests COMMAND kivo_scenario_contracts_tests)
