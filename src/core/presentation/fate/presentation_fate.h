// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
namespace kivo::playback::presentation {
enum class PresentationDropReason { Unknown, TooLate, QueueOverflow, GenerationStale, TrickplayPolicy, ResyncRequired };
enum class PresentationRepeatReason { Unknown, ReferenceHeld, QueueUnderflow, PacingHold, ReschedulePending };
}
