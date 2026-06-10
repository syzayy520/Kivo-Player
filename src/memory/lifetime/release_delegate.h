// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
#include <cstdint>
#include "lifetime_token.h"
namespace kivo::playback::memory {
enum class ReleaseResponsibility { Owner, Borrower, Adapter, Pool };
struct ReleaseDelegateToken { uint64_t id{0}; ReleaseResponsibility responsibility{ReleaseResponsibility::Owner}; LifetimeToken lifetime{}; };
}
