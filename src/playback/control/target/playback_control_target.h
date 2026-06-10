#pragma once
#include "playback_control_target_kind.h"
#include "playback_session_target.h"
#include "playback_seek_target.h"
namespace kivo::playback::control {
struct PlaybackControlTarget {
    PlaybackControlTargetKind kind{PlaybackControlTargetKind::Unknown};
    PlaybackSessionTarget session_target{};
    PlaybackSeekTarget seek_target{};
};
}
