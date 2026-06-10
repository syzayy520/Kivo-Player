# Copyright (c) 2026 Kivo Project. All rights reserved.
add_executable(kivo_playback_memory_tests memory_handle_tests.cpp memory_lifetime_tests.cpp memory_pool_tests.cpp)
target_link_libraries(kivo_playback_memory_tests PRIVATE kivo_playback_memory)
add_test(NAME kivo_playback_memory_tests COMMAND kivo_playback_memory_tests)
target_compile_options(kivo_playback_memory_tests PRIVATE /W4 /WX)
