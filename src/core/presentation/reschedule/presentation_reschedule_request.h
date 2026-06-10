// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
#include "../../timeline/timestamp/media_timestamp.h"
namespace kivo::playback::presentation {
enum class PresentationRescheduleReason { Unknown, ClockCorrectionRequested, ReferenceHeld, ReferenceLost, PolicyChanged, QueuePressure, EosCoordination };
enum class PresentationRescheduleIntent { Unknown, ReevaluateDecision, AdjustDeadline, HoldAdmission, RequestResync };
struct PresentationRescheduleRequest { PresentationRescheduleReason reason{PresentationRescheduleReason::Unknown}; PresentationRescheduleIntent intent{PresentationRescheduleIntent::Unknown}; kivo::playback::timeline::MediaTimestamp reference_time{{},0}; };
}
