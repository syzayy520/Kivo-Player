#pragma once
#include "playback_control_command_kind.h"
#include "playback_control_priority.h"
#include "playback_control_ordering.h"
#include "../identity/control_identity.h"
namespace kivo::playback::control {
struct PlaybackControlCommand {
    ControlIdentity identity{};
    PlaybackControlCommandKind kind{PlaybackControlCommandKind::Unknown};
    PlaybackControlPriority priority{PlaybackControlPriority::Unknown};
    PlaybackControlOrdering ordering{PlaybackControlOrdering::Unknown};
};
}
