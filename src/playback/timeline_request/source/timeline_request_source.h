#pragma once
#include "timeline_request_source_kind.h"
#include "timeline_control_source_ref.h"
#include "timeline_session_source_ref.h"
namespace kivo::playback::timeline_request {
struct TimelineRequestSource {
    TimelineRequestSourceKind kind{TimelineRequestSourceKind::Unknown};
    TimelineControlSourceRef control_source{};
    TimelineSessionSourceRef session_source{};
};
}
