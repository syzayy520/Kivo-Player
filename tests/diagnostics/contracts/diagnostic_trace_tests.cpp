#include <cassert>
#include <iostream>
#include "diagnostics/contracts/trace/diagnostic_trace_id.h"
#include "diagnostics/contracts/trace/diagnostic_span_id.h"
#include "diagnostics/contracts/trace/diagnostic_trace_context.h"
#include "diagnostics/contracts/trace/diagnostic_span_status.h"

namespace kivo::playback::diagnostics {
void run_diagnostic_trace_tests() {
    DiagnosticTraceId tid1;
    assert(tid1.value == 0);
    DiagnosticTraceId tid2{111222};
    assert(tid2.value == 111222);

    DiagnosticSpanId sid1;
    assert(sid1.value == 0);
    DiagnosticSpanId sid2{333444};
    assert(sid2.value == 333444);

    DiagnosticTraceContext ctx1;
    assert(ctx1.trace_id.value == 0);
    assert(ctx1.span_id.value == 0);
    DiagnosticTraceContext ctx2{.trace_id{555}, .span_id{666}};
    assert(ctx2.trace_id.value == 555);
    assert(ctx2.span_id.value == 666);

    DiagnosticSpanStatus stat1 = DiagnosticSpanStatus::Pending;
    DiagnosticSpanStatus stat2 = DiagnosticSpanStatus::InProgress;
    DiagnosticSpanStatus stat3 = DiagnosticSpanStatus::Completed;
    DiagnosticSpanStatus stat4 = DiagnosticSpanStatus::Abandoned;
    assert(stat1 != stat2); assert(stat2 != stat3); assert(stat3 != stat4);

    std::cout << "  diagnostic_trace_tests: ALL PASSED\n";
}
}
