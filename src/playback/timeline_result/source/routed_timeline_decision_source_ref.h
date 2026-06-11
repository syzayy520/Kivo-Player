#pragma once
#include "playback/timeline_decision/routing/routed_timeline_decision.h"
namespace kivo::playback::timeline_result {
struct RoutedTimelineDecisionSourceRef {
    kivo::playback::timeline_decision::RoutedTimelineDecision routed_decision{};
};
}
