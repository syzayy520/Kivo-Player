#pragma once
#include "playback/timeline_chain_integrity/identity/timeline_chain_integrity_identity.h"
namespace kivo::playback::timeline_error_surface {
struct TimelineChainIntegrityErrorAnchor {
    kivo::playback::timeline_chain_integrity::TimelineChainIntegrityIdentity chain_integrity_identity{};
};
}
