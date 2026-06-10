#pragma once
#include "diagnostic_trace_id.h"
#include "diagnostic_span_id.h"
namespace kivo::playback::diagnostics {
struct DiagnosticTraceContext {
    DiagnosticTraceId trace_id{};
    DiagnosticSpanId span_id{};
};
}
