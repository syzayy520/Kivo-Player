#pragma once
#include "core/timeline/timestamp/media_timestamp.h"
namespace kivo::playback::timeline_request {
struct TimelinePositionTarget {
    kivo::playback::timeline::MediaTimestamp position{};
};
}
