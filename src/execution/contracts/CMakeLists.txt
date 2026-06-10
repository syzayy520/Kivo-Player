# Copyright (c) 2026 Kivo Project. All rights reserved.
add_library(kivo_execution_contracts INTERFACE)
target_include_directories(kivo_execution_contracts INTERFACE ${PROJECT_SOURCE_DIR}/src)
target_compile_features(kivo_execution_contracts INTERFACE cxx_std_23)
