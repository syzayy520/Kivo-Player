#pragma once
#include "timeline_public_read_model_id.h"
#include "timeline_public_read_model_sequence_id.h"
#include "timeline_public_read_model_generation.h"
namespace kivo::playback::timeline_public_read_model {
struct TimelinePublicReadModelIdentity {
    TimelinePublicReadModelId read_model_id{};
    TimelinePublicReadModelSequenceId sequence_id{};
    TimelinePublicReadModelGeneration generation{};
};
}
