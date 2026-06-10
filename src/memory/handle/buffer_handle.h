// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
#include <cstdint>
#include "../memory_domain.h"
#include "../lifetime/lifetime_token.h"
#include "backend_tag.h"
namespace kivo::playback::memory {
struct BufferHandle { uint64_t id{0}; MemoryDomain domain{MemoryDomain::Unknown}; BackendTag backend{}; LifetimeToken lifetime{}; };
}
