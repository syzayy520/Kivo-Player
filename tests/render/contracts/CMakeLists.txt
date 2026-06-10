# Copyright (c) 2026 Kivo Project. All rights reserved.
add_executable(kivo_render_contracts_tests
    render_identity_tests.cpp
    render_frame_tests.cpp
    render_target_tests.cpp
    render_submission_tests.cpp
    render_policy_tests.cpp
    render_outcome_tests.cpp
)
target_link_libraries(kivo_render_contracts_tests PRIVATE kivo_render_contracts)
target_compile_features(kivo_render_contracts_tests PRIVATE cxx_std_23)
add_test(NAME kivo_render_contracts_tests COMMAND kivo_render_contracts_tests)
