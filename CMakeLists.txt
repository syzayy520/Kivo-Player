cmake_minimum_required(VERSION 3.25)
project(kivo-video-ultimate LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Strict warnings function (will be applied to targets in implementation step)
function(kivo_apply_strict_warnings target_name)
  if(MSVC)
    target_compile_options(${target_name} PRIVATE /W4 /WX /permissive-)
  endif()
endfunction()

# Enable testing
enable_testing()

# Core library
add_library(kivo_playback_core
    src/core/error/playback_error.cpp
    src/core/state/playback_state_machine.cpp
    src/core/command/playback_command.cpp
    src/core/engine/playback_engine.cpp
    src/core/session/playback_session.cpp
)
kivo_apply_strict_warnings(kivo_playback_core)
target_include_directories(kivo_playback_core PUBLIC src)

# Test: state_machine_tests
add_executable(kivo_playback_state_machine_tests
    tests/unit/core/playback_state_machine_tests.cpp
)
kivo_apply_strict_warnings(kivo_playback_state_machine_tests)
target_link_libraries(kivo_playback_state_machine_tests PRIVATE kivo_playback_core)
add_test(NAME state_machine_tests COMMAND kivo_playback_state_machine_tests)

# Test: command_tests
add_executable(kivo_playback_command_tests
    tests/unit/core/playback_command_tests.cpp
)
kivo_apply_strict_warnings(kivo_playback_command_tests)
target_link_libraries(kivo_playback_command_tests PRIVATE kivo_playback_core)
add_test(NAME command_tests COMMAND kivo_playback_command_tests)

# Test: engine_tests
add_executable(kivo_playback_engine_tests
    tests/unit/core/playback_engine_tests.cpp
)
kivo_apply_strict_warnings(kivo_playback_engine_tests)
target_link_libraries(kivo_playback_engine_tests PRIVATE kivo_playback_core)
add_test(NAME engine_tests COMMAND kivo_playback_engine_tests)

# Test: contract_compile_tests (header self-contained smoke)
# Generated sources will be added at configure time
# For now, a placeholder target
add_executable(kivo_playback_contract_compile_tests
    tests/unit/core/playback_contract_compile_tests.cpp
)
kivo_apply_strict_warnings(kivo_playback_contract_compile_tests)
target_link_libraries(kivo_playback_contract_compile_tests PRIVATE kivo_playback_core)
add_test(NAME contract_compile_tests COMMAND kivo_playback_contract_compile_tests)

message(STATUS "Kivo Video Ultimate - Playback Core Foundation P0-001")

# Pipeline Contracts (P0-002)
add_subdirectory(src/pipeline/contracts)
add_subdirectory(tests/pipeline/contracts)

# Media Probe Model (P0-003)
add_subdirectory(src/pipeline/model/probe)
add_subdirectory(tests/pipeline/model/probe)

# Packet Flow Contracts (P0-004)
add_subdirectory(src/pipeline/model/packet_flow)
add_subdirectory(tests/pipeline/model/packet_flow)

# Decode Contracts (P0-005)
add_subdirectory(src/decoder/contracts)
add_subdirectory(tests/decoder/contracts)

# Timeline / Timestamp / Segment Contracts (P0-006)
add_subdirectory(src/core/timeline)
add_subdirectory(tests/core/timeline)

# Clock Domain / A-V Sync Contracts (P0-007)
add_subdirectory(src/core/clock)
add_subdirectory(tests/core/clock)

# Presentation Decision / Queue Policy / Contracts (P0-008)
add_subdirectory(src/core/presentation)
add_subdirectory(tests/core/presentation)

# Memory / Surface / Opaque Handle / Pool Lifetime Contracts (P0-009)
add_subdirectory(src/memory)
add_subdirectory(tests/memory)

# Demuxer / Media Source Contracts (P0-010)
add_subdirectory(src/demuxer/contracts)
add_subdirectory(tests/demuxer/contracts)

# Media Format / Color / HDR Metadata Contracts (P0-011)
add_subdirectory(src/format/contracts)
add_subdirectory(tests/format/contracts)

# Capability / Negotiation Contracts (P0-012)
add_subdirectory(src/capability/contracts)
add_subdirectory(tests/capability/contracts)

# Device / Recovery Contracts (P0-013)
add_subdirectory(src/device/contracts)
add_subdirectory(tests/device/contracts)

# Video Renderer Contracts (P0-014)
add_subdirectory(src/render/contracts)
add_subdirectory(tests/render/contracts)

# Audio Endpoint / Renderer / Clock / Passthrough Contracts (P0-015)
add_subdirectory(src/audio/contracts)
add_subdirectory(tests/audio/contracts)

# Subtitle / Overlay Contracts (P0-016)
add_subdirectory(src/subtitle/contracts)
add_subdirectory(tests/subtitle/contracts)

# Execution / Concurrency / Task Contracts (P0-017)
add_subdirectory(src/execution/contracts)
add_subdirectory(tests/execution/contracts)

# Diagnostics / Telemetry / Trace Contracts (P0-018)
add_subdirectory(src/diagnostics/contracts)
add_subdirectory(tests/diagnostics/contracts)

# Media Case / Stress Scenario Contracts (P0-019)
add_subdirectory(src/scenario/contracts)
add_subdirectory(tests/scenario/contracts)

# Minimal Playback Orchestration Skeleton (P1-020)
add_subdirectory(src/playback/orchestration)
add_subdirectory(tests/playback/orchestration)

# Playback Command / Intent Normalization Skeleton (P1-021)
add_subdirectory(src/playback/control)
add_subdirectory(tests/playback/control)

# Playback Timeline Request Normalization Skeleton (P1-022)
add_subdirectory(src/playback/timeline_request)
add_subdirectory(tests/playback/timeline_request)

# Playback Timeline Decision Routing Skeleton (P1-023)
add_subdirectory(src/playback/timeline_decision)
add_subdirectory(tests/playback/timeline_decision)

# Playback Timeline Result Reporting Skeleton (P1-024)
add_subdirectory(src/playback/timeline_result)
add_subdirectory(tests/playback/timeline_result)

# Playback Timeline Snapshot Observation Skeleton (P1-025)
add_subdirectory(src/playback/timeline_snapshot_observation)
add_subdirectory(tests/playback/timeline_snapshot_observation)

# Playback Timeline State Summary Skeleton (P1-026)
add_subdirectory(src/playback/timeline_state_summary)
add_subdirectory(tests/playback/timeline_state_summary)

# Playback Timeline Chain Integrity Skeleton (P1-027)
add_subdirectory(src/playback/timeline_chain_integrity)
add_subdirectory(tests/playback/timeline_chain_integrity)

add_subdirectory(src/playback/timeline_error_surface)
add_subdirectory(tests/playback/timeline_error_surface)

add_subdirectory(src/playback/timeline_user_status_surface)
add_subdirectory(tests/playback/timeline_user_status_surface)

add_subdirectory(src/playback/timeline_public_read_model)
add_subdirectory(tests/playback/timeline_public_read_model)

add_subdirectory(src/playback/timeline_public_snapshot)
add_subdirectory(tests/playback/timeline_public_snapshot)
