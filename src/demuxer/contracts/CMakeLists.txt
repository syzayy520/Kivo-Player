# Copyright (c) 2026 Kivo Project. All rights reserved.
# SPDX-License-Identifier: MIT
add_library(kivo_demuxer_contracts INTERFACE)
target_include_directories(kivo_demuxer_contracts INTERFACE ${PROJECT_SOURCE_DIR}/src)
target_compile_features(kivo_demuxer_contracts INTERFACE cxx_std_23)
