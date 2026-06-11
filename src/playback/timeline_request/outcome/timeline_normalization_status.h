#pragma once
namespace kivo::playback::timeline_request {
enum class TimelineNormalizationStatus {
    Accepted,
    Rejected,
    Dropped,
    Unknown
};
}
