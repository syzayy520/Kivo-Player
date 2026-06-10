// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
namespace kivo::playback::memory {
enum class MemoryDomain { CpuLocal, GpuLocal, GpuShared, UnifiedAccess, ExternalOwned, OpaqueAdapterOwned, Unknown };
}
