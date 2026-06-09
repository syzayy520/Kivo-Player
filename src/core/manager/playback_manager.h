// src/core/manager/playback_manager.h - Playback manager coordination layer.
// Manager is the formal coordination layer in Command → Manager → Engine architecture chain.
// Receives PlaybackCommand, coordinates PlaybackEngine, manages PlaybackSession.
#pragma once
#include "../command/playback_command.h"
#include "../engine/playback_engine.h"
#include "../session/playback_session.h"
#include "../event/playback_event_sink.h"
#include <memory>

namespace kivo::playback {

class PlaybackManager {
public:
    explicit PlaybackManager(IPlaybackEventSink* sink);
    ~PlaybackManager();

    auto execute(PlaybackCommand const& cmd) -> PlaybackResult;
    auto current_state() const noexcept -> PlaybackState;

private:
    std::unique_ptr<PlaybackEngine> engine_;
    std::unique_ptr<PlaybackSession> session_;
};

} // namespace kivo::playback
