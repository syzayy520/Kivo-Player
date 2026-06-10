// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
#include <cstdint>
#include "../lifetime/lifetime_token.h"
namespace kivo::playback::memory {
struct PoolLease { uint64_t lease_id{0}; uint64_t handle_id{0}; LifetimeToken lifetime{}; };
}
