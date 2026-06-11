#pragma once
#include "playback/timeline_public_read_model/identity/timeline_public_read_model_identity.h"
namespace kivo::playback::timeline_public_snapshot {
struct TimelinePublicReadModelSnapshotAnchor {
    kivo::playback::timeline_public_read_model::TimelinePublicReadModelIdentity read_model_identity{};
};
}
