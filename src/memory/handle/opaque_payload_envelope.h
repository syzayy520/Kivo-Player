// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
#include <cstdint>
#include "../lifetime/lifetime_token.h"
#include "backend_tag.h"
namespace kivo::playback::memory {
enum class OpaquePayloadKind { Buffer, Surface, PoolLease, ExternalToken, AdapterOwned };
struct OpaquePayloadEnvelope { uint64_t id{0}; BackendTag backend{}; OpaquePayloadKind kind{OpaquePayloadKind::Buffer}; LifetimeToken lifetime{}; };
}
