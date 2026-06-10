#pragma once
#include "control_command_id.h"
#include "control_sequence_id.h"
#include "control_request_id.h"
namespace kivo::playback::control {
struct ControlIdentity {
    ControlCommandId command_id{};
    ControlSequenceId sequence_id{};
    ControlRequestId request_id{};
};
}
