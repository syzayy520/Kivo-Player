#pragma once
#include "../session/playback_session_id.h"
#include "core/presentation/decision/presentation_decision.h"
namespace kivo::playback::orchestration {
struct PlaybackTimelineDecision {
    PlaybackSessionId session_id{};
    kivo::playback::presentation::PresentationDecision decision{
        kivo::playback::presentation::PresentationDecision::Unknown
    };
};
}
