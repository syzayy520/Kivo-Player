#pragma once
#include "timeline_public_read_model_scope.h"
#include "timeline_public_read_model_freshness.h"
#include "timeline_public_read_model_attention.h"
namespace kivo::playback::timeline_public_read_model {
struct TimelinePublicReadModelClassification {
    TimelinePublicReadModelScope scope{TimelinePublicReadModelScope::Unknown};
    TimelinePublicReadModelFreshness freshness{TimelinePublicReadModelFreshness::Unknown};
    TimelinePublicReadModelAttention attention{TimelinePublicReadModelAttention::Unknown};
};
}
