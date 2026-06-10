#pragma once
namespace kivo::playback::render {
enum class RenderFailureReason {
    DeviceLost,
    OutOfMemory,
    FormatUnsupported,
    Timeout,
    InternalError
};
}
