#pragma once
#include "timeline_public_delta_id.h"
#include "timeline_public_delta_sequence_id.h"
#include "timeline_public_delta_generation.h"
namespace kivo::playback::timeline_public_delta {
struct TimelinePublicDeltaIdentity {
    TimelinePublicDeltaId delta_id{};
    TimelinePublicDeltaSequenceId sequence_id{};
    TimelinePublicDeltaGeneration generation{};
};
}
