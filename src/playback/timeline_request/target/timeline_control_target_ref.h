#pragma once
#include "playback/control/target/playback_control_target.h"
namespace kivo::playback::timeline_request {
struct TimelineControlTargetRef {
    kivo::playback::control::PlaybackControlTarget target{};
};
}
