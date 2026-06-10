#pragma once
namespace kivo::playback::execution {
enum class ExecutionFailureReason { TaskInvalid, LaneUnavailable, DeadlineExceeded, ResourceExhaustion, Unknown };
}
