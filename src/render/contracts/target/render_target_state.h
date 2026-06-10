#pragma once
namespace kivo::playback::render {
enum class RenderTargetState {
    Active,
    Suspended,
    Lost,
    Closed
};
}
