#pragma once
#include "../identity/control_request_id.h"
#include "control_normalization_status.h"
namespace kivo::playback::control {
struct ControlNormalizationOutcome {
    ControlRequestId request_id{};
    ControlNormalizationStatus status{ControlNormalizationStatus::Unknown};
};
}
