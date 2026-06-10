#include <cassert>
#include <iostream>
#include "diagnostics/contracts/severity/diagnostic_severity.h"
#include "diagnostics/contracts/severity/diagnostic_category.h"
#include "diagnostics/contracts/severity/diagnostic_event_level.h"
#include "diagnostics/contracts/severity/diagnostic_confidence.h"

namespace kivo::playback::diagnostics {
void run_diagnostic_severity_tests() {
    DiagnosticSeverity s1 = DiagnosticSeverity::Trace;
    DiagnosticSeverity s2 = DiagnosticSeverity::Debug;
    DiagnosticSeverity s3 = DiagnosticSeverity::Info;
    DiagnosticSeverity s4 = DiagnosticSeverity::Warning;
    DiagnosticSeverity s5 = DiagnosticSeverity::Error;
    DiagnosticSeverity s6 = DiagnosticSeverity::Critical;
    assert(s1 != s2); assert(s2 != s3); assert(s3 != s4);
    assert(s4 != s5); assert(s5 != s6);

    DiagnosticCategory c1 = DiagnosticCategory::Lifecycle;
    DiagnosticCategory c2 = DiagnosticCategory::Performance;
    DiagnosticCategory c3 = DiagnosticCategory::Error;
    DiagnosticCategory c4 = DiagnosticCategory::Protocol;
    DiagnosticCategory c5 = DiagnosticCategory::Boundary;
    assert(c1 != c2); assert(c2 != c3); assert(c3 != c4); assert(c4 != c5);

    DiagnosticEventLevel l1 = DiagnosticEventLevel::Atomic;
    DiagnosticEventLevel l2 = DiagnosticEventLevel::Boundary;
    DiagnosticEventLevel l3 = DiagnosticEventLevel::Aggregate;
    assert(l1 != l2); assert(l2 != l3);

    DiagnosticConfidence conf1 = DiagnosticConfidence::Certain;
    DiagnosticConfidence conf2 = DiagnosticConfidence::High;
    DiagnosticConfidence conf3 = DiagnosticConfidence::Medium;
    DiagnosticConfidence conf4 = DiagnosticConfidence::Low;
    assert(conf1 != conf2); assert(conf2 != conf3); assert(conf3 != conf4);

    std::cout << "  diagnostic_severity_tests: ALL PASSED\n";
}
}
