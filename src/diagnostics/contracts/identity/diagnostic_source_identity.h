#pragma once
#include "diagnostic_source_id.h"
#include "diagnostic_source_kind.h"
namespace kivo::playback::diagnostics {
struct DiagnosticSourceIdentity {
    DiagnosticSourceId source_id{};
    DiagnosticSourceKind kind{DiagnosticSourceKind::Unknown};
};
}
