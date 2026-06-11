#pragma once
#include "../identity/timeline_public_delta_identity.h"
#include "timeline_public_delta_status.h"
namespace kivo::playback::timeline_public_delta {
struct TimelinePublicDeltaOutcome {
    TimelinePublicDeltaIdentity identity{};
    TimelinePublicDeltaStatus status{TimelinePublicDeltaStatus::Unknown};
};
}
