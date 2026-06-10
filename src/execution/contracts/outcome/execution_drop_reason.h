#pragma once
namespace kivo::playback::execution {
enum class ExecutionDropReason { Overdue, QueuePressure, Preempted, Unknown };
}
