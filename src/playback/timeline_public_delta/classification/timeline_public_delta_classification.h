#pragma once
#include "timeline_public_delta_kind.h"
#include "timeline_public_delta_scope.h"
namespace kivo::playback::timeline_public_delta {
struct TimelinePublicDeltaClassification {
    TimelinePublicDeltaKind kind{TimelinePublicDeltaKind::Unknown};
    TimelinePublicDeltaScope scope{TimelinePublicDeltaScope::Unknown};
};
}
