#pragma once
#include "execution_context_id.h"
namespace kivo::playback::execution {
struct ExecutionContextSnapshot {
    ExecutionContextId context_id{};
    bool healthy{true};
};
}
