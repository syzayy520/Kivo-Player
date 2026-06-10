#pragma once
namespace kivo::playback::execution {
enum class ExecutionBlockingPolicy { NonBlockingRequired, BoundedBlockingAllowed, BlockingAllowed, Unknown };
}
