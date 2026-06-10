#pragma once
#include "diagnostic_event_id.h"
#include "diagnostic_event_code.h"
#include "diagnostic_event_timestamp.h"
#include "../identity/diagnostic_source_identity.h"
#include "../severity/diagnostic_severity.h"
#include "../severity/diagnostic_category.h"
namespace kivo::playback::diagnostics {
struct DiagnosticEventRecord {
    DiagnosticEventId event_id{};
    DiagnosticSourceIdentity source{};
    DiagnosticSeverity severity{DiagnosticSeverity::Unknown};
    DiagnosticCategory category{DiagnosticCategory::Unknown};
    DiagnosticEventCode code{};
    DiagnosticEventTimestamp timestamp{};
};
}
