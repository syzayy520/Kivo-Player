#pragma once
#include <string>
#include "subtitle_cue_id.h"
#include "subtitle_cue_payload_kind.h"
namespace kivo::playback::subtitle {
struct SubtitleCuePayload {
    SubtitleCueId cue_id{};
    SubtitleCuePayloadKind kind{SubtitleCuePayloadKind::Unknown};
    std::string text{};
};
}
