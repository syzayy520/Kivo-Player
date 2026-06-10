# Copyright (c) 2026 Kivo Project. All rights reserved.
add_executable(kivo_playback_orchestration_tests
    playback_session_tests.cpp
    playback_lifecycle_tests.cpp
    playback_intent_tests.cpp
    playback_timeline_tests.cpp
    playback_binding_tests.cpp
    playback_outcome_tests.cpp
)
target_link_libraries(kivo_playback_orchestration_tests PRIVATE kivo_playback_orchestration)
target_compile_features(kivo_playback_orchestration_tests PRIVATE cxx_std_23)
add_test(NAME kivo_playback_orchestration_tests COMMAND kivo_playback_orchestration_tests)
