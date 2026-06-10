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
