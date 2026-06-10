#include <cassert>
#include <iostream>
#include "diagnostics/contracts/event/diagnostic_event_id.h"
#include "diagnostics/contracts/event/diagnostic_event_code.h"
#include "diagnostics/contracts/event/diagnostic_event_timestamp.h"
#include "diagnostics/contracts/event/diagnostic_event_record.h"

namespace kivo::playback::diagnostics {
void run_diagnostic_event_tests() {
    DiagnosticEventId eid1;
    assert(eid1.value == 0);
    DiagnosticEventId eid2{999};
    assert(eid2.value == 999);

    DiagnosticEventCode code1;
    assert(code1.domain == 0); assert(code1.code == 0);
    DiagnosticEventCode code2{100, 42};
    assert(code2.domain == 100); assert(code2.code == 42);

    DiagnosticEventTimestamp ts1;
    assert(ts1.system.valid == false);
    assert(ts1.media.value == 0);
    DiagnosticEventTimestamp ts2{
        .system{.monotonic_ticks{5000}, .tick_frequency{10000000}, .capture_generation{1}, .valid{true}},
        .media{kivo::playback::timeline::MediaTimestamp{{}, 30000}}
    };
    assert(ts2.system.monotonic_ticks == 5000);
    assert(ts2.media.value == 30000);

    DiagnosticEventRecord rec1;
    assert(rec1.event_id.value == 0);
    assert(rec1.source.source_id.value == 0);
    assert(rec1.severity == DiagnosticSeverity::Unknown);
    assert(rec1.category == DiagnosticCategory::Unknown);
    assert(rec1.code.code == 0);
    assert(rec1.timestamp.system.valid == false);
    DiagnosticEventRecord rec2{
        .event_id{77},
        .source{.source_id{1}, .kind{DiagnosticSourceKind::Core}},
        .severity{DiagnosticSeverity::Info},
        .category{DiagnosticCategory::Lifecycle},
        .code{.domain{10}, .code{1}},
        .timestamp{.system{.valid{true}}, .media{kivo::playback::timeline::MediaTimestamp{{}, 1000}}}
    };
    assert(rec2.event_id.value == 77);
    assert(rec2.severity == DiagnosticSeverity::Info);
    assert(rec2.code.domain == 10);

    std::cout << "  diagnostic_event_tests: ALL PASSED\n";
}
}
