#pragma once
#include "playback/timeline_request/identity/timeline_request_identity.h"
namespace kivo::playback::timeline_chain_integrity {
struct TimelineRequestChainAnchor { kivo::playback::timeline_request::TimelineRequestIdentity request_identity{}; };
}
