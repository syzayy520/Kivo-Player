#pragma once
#include "execution_task_id.h"
#include "core/timeline/timestamp/media_timestamp.h"
#include "core/presentation/timing/presentation_deadline.h"
namespace kivo::playback::execution {
struct ExecutionTaskDeadline {
    ExecutionTaskId task_id{};
    kivo::playback::timeline::MediaTimestamp earliest_start{};
    kivo::playback::presentation::PresentationDeadline deadline{};
};
}
