#pragma once
#include "playback/timeline_result/identity/timeline_result_report_identity.h"
namespace kivo::playback::timeline_chain_integrity {
struct TimelineResultChainAnchor { kivo::playback::timeline_result::TimelineResultReportIdentity result_report_identity{}; };
}
