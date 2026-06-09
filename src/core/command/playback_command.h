// src/core/command/playback_command.h - User playback intent and payload validation.
// Depends on: core/id, core/time, core/result, core/error, standard library.
// Does NOT depend on: engine, pipeline, decoder, output, FFmpeg, D3D11, WASAPI, UI.
#pragma once
#include "../id/playback_id.h"
#include "../time/playback_time.h"
#include "../result/playback_result.h"
#include <string>
#include <variant>

namespace kivo::playback {

struct CmdOpenMedia { std::string source; };
struct CmdPlay {};
struct CmdPause {};
struct CmdTogglePause {};
struct CmdSeek { MediaTime target; };
struct CmdStop {};
struct CmdClose {};
struct CmdSetPlaybackRate { double rate; };
struct CmdSelectAudioTrack { TrackId track_id; };
struct CmdSelectSubtitleTrack { TrackId track_id; };
struct CmdSetVolume { double volume; };
struct CmdMute {};
struct CmdUnmute {};

using PlaybackCommand = std::variant<
    CmdOpenMedia, CmdPlay, CmdPause, CmdTogglePause,
    CmdSeek, CmdStop, CmdClose,
    CmdSetPlaybackRate, CmdSelectAudioTrack, CmdSelectSubtitleTrack,
    CmdSetVolume, CmdMute, CmdUnmute
>;

auto validate_command(PlaybackCommand const& cmd) -> PlaybackResult;
auto command_type_string(PlaybackCommand const& cmd) -> std::string;

} // namespace kivo::playback
