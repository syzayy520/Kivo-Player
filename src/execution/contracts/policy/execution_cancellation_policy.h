#pragma once
namespace kivo::playback::execution {
enum class ExecutionCancellationPolicy { NotCancellable, Cooperative, DeadlineOnly, Unknown };
}
