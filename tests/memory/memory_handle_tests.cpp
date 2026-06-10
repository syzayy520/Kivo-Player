// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/memory/memory_handle_tests.cpp - main()
#include "memory/handle/backend_tag.h"
#include "memory/handle/buffer_handle.h"
#include "memory/handle/surface_handle.h"
#include "memory/handle/opaque_payload_envelope.h"
#include "memory/memory_domain.h"
#include <iostream>
int g_pass = 0; int g_fail = 0;
#define CHK(c) do { if (!(c)) { ++g_fail; std::cerr << "FAIL:" << __LINE__ << ":" << #c << std::endl; } else { ++g_pass; } } while(0)
static void test_memory_domain() { using namespace kivo::playback::memory; CHK(MemoryDomain::CpuLocal != MemoryDomain::GpuLocal); }
static void test_backend_tag() { using namespace kivo::playback::memory; BackendTag t; t.kind = BackendKind::GpuOwned; t.family_id = 1; CHK(t.family_id == 1); }
static void test_buffer_handle() { using namespace kivo::playback::memory; BufferHandle h; h.id = 42; h.domain = MemoryDomain::CpuLocal; CHK(h.id == 42); }
static void test_surface_handle() { using namespace kivo::playback::memory; SurfaceHandle h; h.id = 99; h.domain = MemoryDomain::GpuLocal; CHK(h.id == 99); }
static void test_opaque_payload() { using namespace kivo::playback::memory; OpaquePayloadEnvelope e; e.kind = OpaquePayloadKind::Surface; CHK(e.kind != OpaquePayloadKind::Buffer); }
extern int run_memory_lifetime_tests();
extern int run_memory_pool_tests();
int main() { test_memory_domain(); test_backend_tag(); test_buffer_handle(); test_surface_handle(); test_opaque_payload(); run_memory_lifetime_tests(); run_memory_pool_tests(); std::cout << "memory_tests: " << g_pass << " passed, " << g_fail << " failed" << std::endl; return g_fail > 0 ? 1 : 0; }
