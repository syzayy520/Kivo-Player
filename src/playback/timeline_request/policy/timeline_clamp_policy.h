#pragma once
namespace kivo::playback::timeline_request {
enum class TimelineClampPolicy {
    None,
    ClampToKnownRange,
    RejectOutOfRange,
    Unknown
};
}
