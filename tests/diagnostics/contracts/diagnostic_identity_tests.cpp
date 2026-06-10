#include <cassert>
#include <iostream>
#include "diagnostics/contracts/identity/diagnostic_source_id.h"
#include "diagnostics/contracts/identity/diagnostic_source_kind.h"
#include "diagnostics/contracts/identity/diagnostic_source_identity.h"
#include "diagnostics/contracts/identity/diagnostic_capture_point.h"

namespace kivo::playback::diagnostics {
void run_diagnostic_identity_tests() {
    DiagnosticSourceId id1;
    assert(id1.value == 0);
    DiagnosticSourceId id2{42};
    assert(id2.value == 42);

    DiagnosticSourceKind k1 = DiagnosticSourceKind::Core;
    DiagnosticSourceKind k2 = DiagnosticSourceKind::Memory;
    DiagnosticSourceKind k3 = DiagnosticSourceKind::Format;
    DiagnosticSourceKind k4 = DiagnosticSourceKind::Capability;
    DiagnosticSourceKind k5 = DiagnosticSourceKind::Device;
    DiagnosticSourceKind k6 = DiagnosticSourceKind::Diagnostics;
    assert(k1 != k2); assert(k2 != k3); assert(k3 != k4);
    assert(k4 != k5); assert(k5 != k6);

    DiagnosticSourceIdentity ident1;
    assert(ident1.source_id.value == 0);
    assert(ident1.kind == DiagnosticSourceKind::Unknown);
    DiagnosticSourceIdentity ident2{.source_id{100}, .kind{DiagnosticSourceKind::Core}};
    assert(ident2.source_id.value == 100);

    DiagnosticCapturePoint cp1;
    assert(cp1.source_id.value == 0);
    assert(cp1.point_id == 0);
    DiagnosticCapturePoint cp2{.source_id{200}, .point_id{77}};
    assert(cp2.point_id == 77);

    std::cout << "  diagnostic_identity_tests: ALL PASSED\n";
}
void run_diagnostic_severity_tests();
void run_diagnostic_event_tests();
void run_diagnostic_trace_tests();
void run_telemetry_sample_tests();
void run_diagnostic_outcome_tests();
}

int main() {
    using namespace kivo::playback::diagnostics;
    run_diagnostic_identity_tests();
    run_diagnostic_severity_tests();
    run_diagnostic_event_tests();
    run_diagnostic_trace_tests();
    run_telemetry_sample_tests();
    run_diagnostic_outcome_tests();
    std::cout << "  ALL diagnostics contracts tests PASSED\n";
    return 0;
}
