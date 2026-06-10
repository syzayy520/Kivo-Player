#pragma once
#include "execution_context_id.h"
#include "execution_context_role.h"
namespace kivo::playback::execution {
struct ExecutionContextIdentity {
    ExecutionContextId id{};
    ExecutionContextRole role{ExecutionContextRole::Unknown};
};
}
