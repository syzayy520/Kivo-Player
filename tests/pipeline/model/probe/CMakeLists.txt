# Copyright (c) 2026 Kivo Project. All rights reserved.
# tests/pipeline/model/probe/CMakeLists.txt - Media Probe Model tests.

add_executable(kivo_pipeline_probe_model_tests
    probe_model_tests.cpp
)

target_link_libraries(kivo_pipeline_probe_model_tests PRIVATE
    kivo_pipeline_probe_model
)

add_test(NAME kivo_pipeline_probe_model_tests COMMAND kivo_pipeline_probe_model_tests)

target_compile_options(kivo_pipeline_probe_model_tests PRIVATE
    /W4 /WX
)
