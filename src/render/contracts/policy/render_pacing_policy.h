#pragma once
namespace kivo::playback::render {
enum class RenderPacingPolicy {
    Realtime,
    LowLatency,
    BestEffort,
    Offline
};
}
