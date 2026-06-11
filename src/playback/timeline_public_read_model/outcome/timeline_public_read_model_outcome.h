#pragma once
#include "../identity/timeline_public_read_model_identity.h"
#include "timeline_public_read_model_status.h"
namespace kivo::playback::timeline_public_read_model {
struct TimelinePublicReadModelOutcome {
    TimelinePublicReadModelIdentity identity{};
    TimelinePublicReadModelStatus status{TimelinePublicReadModelStatus::Unknown};
};
}
