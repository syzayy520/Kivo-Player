#pragma once
namespace kivo::playback::render {
enum class RenderColorIntent {
    PassthroughColor,
    MatchTargetColor,
    Unknown
};

struct RenderColorPolicy {
    RenderColorIntent intent{RenderColorIntent::Unknown};
};
}
