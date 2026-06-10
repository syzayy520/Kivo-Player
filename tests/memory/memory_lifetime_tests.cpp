// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/memory/memory_lifetime_tests.cpp
#include "memory/lifetime/lifetime_token.h"
#include "memory/lifetime/release_delegate.h"
#include "memory/lifetime/surface_invalidation_reason.h"
#include <iostream>
extern int g_pass; extern int g_fail;
#define CHK(c) do { if (!(c)) { ++g_fail; std::cerr << "FAIL:" << __LINE__ << ":" << #c << std::endl; } else { ++g_pass; } } while(0)
static void test_lifetime_token() { using namespace kivo::playback::memory; LifetimeToken t; t.id = 1; t.generation = 5; CHK(t.id == 1); CHK(t.generation == 5); }
static void test_release_delegate() { using namespace kivo::playback::memory; ReleaseDelegateToken r; r.responsibility = ReleaseResponsibility::Adapter; CHK(r.responsibility != ReleaseResponsibility::Owner); }
static void test_surface_invalidation() { using namespace kivo::playback::memory; CHK(SurfaceInvalidationReason::BackendInvalidated != SurfaceInvalidationReason::UserReleased); }
int run_memory_lifetime_tests() { test_lifetime_token(); test_release_delegate(); test_surface_invalidation(); return 0; }
