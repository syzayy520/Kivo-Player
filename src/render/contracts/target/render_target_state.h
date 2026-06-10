#pragma once
namespace kivo::playback::render {
enum class RenderTargetState {
    Uninitialized,
    Active,
    Suspended,
    Resized,
    Inactive,
    Unknown
};
}
