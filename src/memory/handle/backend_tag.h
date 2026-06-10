// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
#include <cstdint>
namespace kivo::playback::memory {
enum class BackendKind { CpuOwned, GpuOwned, ExternalOwned, AdapterOwned, Unknown };
struct BackendTag { BackendKind kind{BackendKind::Unknown}; uint32_t family_id{0}; uint32_t version{0}; };
}
