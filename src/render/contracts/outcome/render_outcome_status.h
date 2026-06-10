#pragma once
namespace kivo::playback::render {
enum class RenderOutcomeStatus {
    Pending,
    Presented,
    Dropped,
    Failed,
    Cancelled
};
}
