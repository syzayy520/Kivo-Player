#pragma once
#include "timeline_error_category.h"
#include "timeline_error_severity.h"
#include "timeline_error_recoverability.h"
#include "timeline_error_phase.h"
namespace kivo::playback::timeline_error_surface {
struct TimelineErrorClassification {
    TimelineErrorCategory category{TimelineErrorCategory::Unknown};
    TimelineErrorSeverity severity{TimelineErrorSeverity::Unknown};
    TimelineErrorRecoverability recoverability{TimelineErrorRecoverability::Unknown};
    TimelineErrorPhase phase{TimelineErrorPhase::Unknown};
};
}
