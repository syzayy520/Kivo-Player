// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
namespace kivo::playback::memory {
enum class SurfaceInvalidationReason { BackendInvalidated, DimensionsChanged, FormatChanged, PoolRecycled, GenerationExpired, UserReleased, ExternalInvalidation };
}
