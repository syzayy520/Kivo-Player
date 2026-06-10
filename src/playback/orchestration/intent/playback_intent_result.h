#pragma once
#include "playback_intent_id.h"
#include "../outcome/playback_orchestration_status.h"
namespace kivo::playback::orchestration {
struct PlaybackIntentResult {
    PlaybackIntentId intent_id{};
    PlaybackOrchestrationStatus status{PlaybackOrchestrationStatus::Unknown};
};
}
