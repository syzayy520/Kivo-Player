#pragma once
#include <cstdint>
#include "diagnostic_source_id.h"
namespace kivo::playback::diagnostics {
struct DiagnosticCapturePoint {
    DiagnosticSourceId source_id{};
    uint32_t point_id{0};
};
}
