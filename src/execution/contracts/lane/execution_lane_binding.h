#pragma once
#include "execution_lane_id.h"
#include "../context/execution_context_id.h"
namespace kivo::playback::execution {
struct ExecutionLaneBinding {
    ExecutionLaneId lane_id{};
    ExecutionContextId context_id{};
};
}
