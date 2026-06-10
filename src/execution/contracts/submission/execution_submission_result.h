#pragma once
#include <cstdint>
#include "execution_submission_id.h"
#include "execution_submission_status.h"
namespace kivo::playback::execution {
struct ExecutionSubmissionResult {
    ExecutionSubmissionId submission_id{};
    ExecutionSubmissionStatus status{ExecutionSubmissionStatus::Unknown};
    uint64_t tasks_accepted{0};
    uint64_t tasks_rejected{0};
};
}
