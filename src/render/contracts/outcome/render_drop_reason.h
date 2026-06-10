#pragma once
namespace kivo::playback::render {
enum class RenderDropReason {
    LateFrame,
    DuplicateFrame,
    Backpressure,
    PolicySkip
};
}
