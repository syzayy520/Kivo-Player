#pragma once
#include "timeline_user_status_kind.h"
#include "timeline_user_status_readiness.h"
#include "timeline_user_status_attention.h"
namespace kivo::playback::timeline_user_status_surface {
struct TimelineUserStatusClassification {
    TimelineUserStatusKind kind{TimelineUserStatusKind::Unknown};
    TimelineUserStatusReadiness readiness{TimelineUserStatusReadiness::Unknown};
    TimelineUserStatusAttention attention{TimelineUserStatusAttention::Unknown};
};
}
