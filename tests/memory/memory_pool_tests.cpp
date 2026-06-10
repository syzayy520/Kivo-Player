// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/memory/memory_pool_tests.cpp
#include "memory/pool/pool_lease.h"
#include "memory/pool/pool_budget.h"
#include "memory/pool/pool_pressure.h"
#include "memory/pool/allocation_policy.h"
#include "memory/pool/backpressure_by_allocation.h"
#include <iostream>
extern int g_pass; extern int g_fail;
#define CHK(c) do { if (!(c)) { ++g_fail; std::cerr << "FAIL:" << __LINE__ << ":" << #c << std::endl; } else { ++g_pass; } } while(0)
static void test_pool_lease() { using namespace kivo::playback::memory; PoolLease l; l.lease_id = 10; CHK(l.lease_id == 10); }
static void test_pool_budget() { using namespace kivo::playback::memory; PoolBudget b; b.max_handles = 8; CHK(b.max_handles == 8); }
static void test_pool_pressure() { using namespace kivo::playback::memory; CHK(PoolPressure::Low != PoolPressure::Critical); }
static void test_allocation_policy() { using namespace kivo::playback::memory; CHK(AllocationPolicy::Lazy != AllocationPolicy::Preallocated); }
static void test_backpressure() { using namespace kivo::playback::memory; CHK(AllocationBackpressureDecision::None != AllocationBackpressureDecision::RejectNewLease); }
int run_memory_pool_tests() { test_pool_lease(); test_pool_budget(); test_pool_pressure(); test_allocation_policy(); test_backpressure(); return 0; }
