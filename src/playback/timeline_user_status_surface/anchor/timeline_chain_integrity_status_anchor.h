#pragma once
#include "playback/timeline_chain_integrity/identity/timeline_chain_integrity_identity.h"
namespace kivo::playback::timeline_user_status_surface {
struct TimelineChainIntegrityStatusAnchor {
    kivo::playback::timeline_chain_integrity::TimelineChainIntegrityIdentity chain_integrity_identity{};
};
}
