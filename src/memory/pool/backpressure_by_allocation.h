// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
namespace kivo::playback::memory {
enum class AllocationBackpressureDecision { None, HoldAdmission, RejectNewLease, RequestRelease, EscalatePressure };
}
