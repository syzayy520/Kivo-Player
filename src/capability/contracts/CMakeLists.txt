# Copyright (c) 2026 Kivo Project. All rights reserved.
add_library(kivo_capability_contracts INTERFACE)
target_include_directories(kivo_capability_contracts INTERFACE ${PROJECT_SOURCE_DIR}/src)
target_compile_features(kivo_capability_contracts INTERFACE cxx_std_23)
