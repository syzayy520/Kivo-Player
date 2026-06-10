#pragma once
#include "execution_task_id.h"
#include "execution_task_kind.h"
namespace kivo::playback::execution {
struct ExecutionTaskDescriptor {
    ExecutionTaskId task_id{};
    ExecutionTaskKind kind{ExecutionTaskKind::Unknown};
};
}
