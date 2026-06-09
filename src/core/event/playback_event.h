// src/core/event/playback_event.h - Engine output events.
// Depends on: core/state, core/error, core/capability, core/time, core/timeline.
#pragma once
#include "../state/playback_state.h"
#include "../error/playback_error.h"
#include "../id/playback_id.h"
#include "../time/playback_time.h"

namespace kivo::playback {

struct EvStateChanged { PlaybackState from; PlaybackState to; };
struct EvMediaOpened { SessionId session_id; };
struct EvMediaReady { SessionId session_id; MediaTime duration; };
struct EvPlaybackStarted {};
struct EvPlaybackPaused {};
struct EvSeekStarted { MediaTime target; };
struct EvSeekCompleted { MediaTime position; };
struct EvPlaybackEnded {};
struct EvErrorRaised { PlaybackError error; };
struct EvCapabilityChanged {};
struct EvClockUpdated { MediaTime position; };
struct EvTimelineUpdated {};

using PlaybackEvent = std::variant<
    EvStateChanged, EvMediaOpened, EvMediaReady,
    EvPlaybackStarted, EvPlaybackPaused,
    EvSeekStarted, EvSeekCompleted,
    EvPlaybackEnded, EvErrorRaised,
    EvCapabilityChanged, EvClockUpdated, EvTimelineUpdated
>;

} // namespace kivo::playback
