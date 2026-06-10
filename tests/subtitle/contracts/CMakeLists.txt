# Copyright (c) 2026 Kivo Project. All rights reserved.
add_executable(kivo_subtitle_contracts_tests
    subtitle_track_tests.cpp
    subtitle_cue_tests.cpp
    subtitle_region_tests.cpp
    subtitle_overlay_tests.cpp
    subtitle_composition_tests.cpp
    subtitle_outcome_tests.cpp
)
target_link_libraries(kivo_subtitle_contracts_tests PRIVATE kivo_subtitle_contracts)
target_compile_features(kivo_subtitle_contracts_tests PRIVATE cxx_std_23)
add_test(NAME kivo_subtitle_contracts_tests COMMAND kivo_subtitle_contracts_tests)
