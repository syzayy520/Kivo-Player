#pragma once
#include "../event/diagnostic_event_id.h"
#include "diagnostic_submission_status.h"
namespace kivo::playback::diagnostics {
struct DiagnosticSubmissionResult {
    DiagnosticEventId event_id{};
    DiagnosticSubmissionStatus status{DiagnosticSubmissionStatus::Unknown};
};
}
