#pragma once
#include "execution_submission_id.h"
#include "../task/execution_task_id.h"
#include "../task/execution_task_deadline.h"
#include "../lane/execution_lane_id.h"
namespace kivo::playback::execution {
struct ExecutionSubmissionRequest {
    ExecutionSubmissionId submission_id{};
    ExecutionTaskId task_id{};
    ExecutionLaneId lane_id{};
    ExecutionTaskDeadline task_deadline{};
};
}
