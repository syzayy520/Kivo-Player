#pragma once
namespace kivo::playback::audio {
enum class AudioPassthroughStatus {
    Disabled,
    Allowed,
    Required,
    Rejected,
    Unknown
};
}
