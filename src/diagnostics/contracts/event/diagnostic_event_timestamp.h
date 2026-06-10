#pragma once
#include "core/clock/snapshot/system_clock_snapshot.h"
#include "core/timeline/timestamp/media_timestamp.h"
namespace kivo::playback::diagnostics {
struct DiagnosticEventTimestamp {
    kivo::playback::clock::SystemClockSnapshot system{};
    kivo::playback::timeline::MediaTimestamp media{};
};
}
