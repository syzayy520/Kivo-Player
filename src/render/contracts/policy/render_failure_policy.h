#pragma once
namespace kivo::playback::render {
enum class RenderFailurePolicy {
    Abort,
    SkipFrame,
    BlackFrame,
    LastGoodFrame
};
}
