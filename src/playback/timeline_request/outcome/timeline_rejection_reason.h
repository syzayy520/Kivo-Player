#pragma once
namespace kivo::playback::timeline_request {
enum class TimelineRejectionReason {
    TargetInvalid,
    DeadlineInvalid,
    SessionInvalid,
    Unknown
};
}
