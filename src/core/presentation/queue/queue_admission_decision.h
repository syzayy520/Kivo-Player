// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
namespace kivo::playback::presentation {
enum class QueueAdmissionDecision { Unknown, Admit, Reject, RejectStaleGeneration, HoldUntilSpace };
}
