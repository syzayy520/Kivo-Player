#pragma once
#include "../submission/execution_submission_id.h"
#include "execution_outcome_status.h"
namespace kivo::playback::execution {
struct ExecutionOutcome {
    ExecutionSubmissionId submission_id{};
    ExecutionOutcomeStatus status{ExecutionOutcomeStatus::Unknown};
};
}
