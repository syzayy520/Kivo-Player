#pragma once
#include <cstdint>
namespace kivo::playback::diagnostics {
struct DiagnosticEventCode {
    uint32_t domain{0};
    uint32_t code{0};
};
}
