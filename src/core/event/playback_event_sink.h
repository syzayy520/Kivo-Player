// src/core/event/playback_event_sink.h - Event sink contract.
#pragma once
#include "playback_event.h"

namespace kivo::playback {
struct IPlaybackEventSink {
    virtual ~IPlaybackEventSink() = default;
    virtual auto on_event(PlaybackEvent const&) -> void = 0;
};
} // namespace kivo::playback
