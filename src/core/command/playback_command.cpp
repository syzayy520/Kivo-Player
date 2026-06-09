// src/core/command/playback_command.cpp - Command validation impl.
#include "playback_command.h"
#include "../time/playback_time.h"
#include "../result/playback_result.h"
#include <cmath>

namespace kivo::playback {

auto validate_command(PlaybackCommand const& cmd) -> PlaybackResult {
    if (std::holds_alternative<CmdOpenMedia>(cmd)) {
        auto const& c = std::get<CmdOpenMedia>(cmd);
        auto s = c.source;
        while (!s.empty() && std::isspace(static_cast<unsigned char>(s[0]))) s.erase(0, 1);
        while (!s.empty() && std::isspace(static_cast<unsigned char>(s.back()))) s.pop_back();
        if (s.empty()) return PlaybackResult::failure(PlaybackError{PlaybackErrorType::InvalidCommand});
        return PlaybackResult::success();
    }
    if (std::holds_alternative<CmdSeek>(cmd)) {
        auto t = std::get<CmdSeek>(cmd).target;
        if (t < 0) return PlaybackResult::failure(PlaybackError{PlaybackErrorType::InvalidCommand});
        return PlaybackResult::success();
    }
    if (std::holds_alternative<CmdSetPlaybackRate>(cmd)) {
        auto r = std::get<CmdSetPlaybackRate>(cmd).rate;
        if (r < 0.25 || r > 4.0 || !std::isfinite(r))
            return PlaybackResult::failure(PlaybackError{PlaybackErrorType::InvalidCommand});
        return PlaybackResult::success();
    }
    if (std::holds_alternative<CmdSetVolume>(cmd)) {
        auto v = std::get<CmdSetVolume>(cmd).volume;
        if (v < 0.0 || v > 1.0 || !std::isfinite(v))
            return PlaybackResult::failure(PlaybackError{PlaybackErrorType::InvalidCommand});
        return PlaybackResult::success();
    }
    if (std::holds_alternative<CmdSelectAudioTrack>(cmd)) {
        auto id = std::get<CmdSelectAudioTrack>(cmd).track_id;
        if (!id.is_valid()) return PlaybackResult::failure(PlaybackError{PlaybackErrorType::InvalidCommand});
        return PlaybackResult::success();
    }
    if (std::holds_alternative<CmdSelectSubtitleTrack>(cmd)) {
        auto id = std::get<CmdSelectSubtitleTrack>(cmd).track_id;
        if (!id.is_valid()) return PlaybackResult::failure(PlaybackError{PlaybackErrorType::InvalidCommand});
        return PlaybackResult::success();
    }
    return PlaybackResult::success();
}

auto command_type_string(PlaybackCommand const& cmd) -> std::string {
    if (std::holds_alternative<CmdOpenMedia>(cmd)) return "OpenMedia";
    if (std::holds_alternative<CmdPlay>(cmd)) return "Play";
    if (std::holds_alternative<CmdPause>(cmd)) return "Pause";
    if (std::holds_alternative<CmdTogglePause>(cmd)) return "TogglePause";
    if (std::holds_alternative<CmdSeek>(cmd)) return "Seek";
    if (std::holds_alternative<CmdStop>(cmd)) return "Stop";
    if (std::holds_alternative<CmdClose>(cmd)) return "Close";
    if (std::holds_alternative<CmdSetPlaybackRate>(cmd)) return "SetPlaybackRate";
    if (std::holds_alternative<CmdSelectAudioTrack>(cmd)) return "SelectAudioTrack";
    if (std::holds_alternative<CmdSelectSubtitleTrack>(cmd)) return "SelectSubtitleTrack";
    if (std::holds_alternative<CmdSetVolume>(cmd)) return "SetVolume";
    if (std::holds_alternative<CmdMute>(cmd)) return "Mute";
    if (std::holds_alternative<CmdUnmute>(cmd)) return "Unmute";
    return "Unknown";
}

} // namespace kivo::playback
