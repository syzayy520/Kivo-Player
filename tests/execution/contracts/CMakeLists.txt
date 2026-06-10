# Copyright (c) 2026 Kivo Project. All rights reserved.
add_executable(kivo_execution_contracts_tests
    execution_context_tests.cpp
    execution_lane_tests.cpp
    execution_task_tests.cpp
    execution_submission_tests.cpp
    execution_policy_tests.cpp
    execution_outcome_tests.cpp
)
target_link_libraries(kivo_execution_contracts_tests PRIVATE kivo_execution_contracts)
target_compile_features(kivo_execution_contracts_tests PRIVATE cxx_std_23)
add_test(NAME kivo_execution_contracts_tests COMMAND kivo_execution_contracts_tests)
