#pragma once
#include "playback/control/identity/control_request_id.h"
namespace kivo::playback::timeline_request {
struct TimelineControlSourceRef {
    kivo::playback::control::ControlRequestId request_id{};
};
}
