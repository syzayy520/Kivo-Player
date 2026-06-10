#pragma once
#include "../../../core/timeline/reset/timeline_reset.h"
namespace kivo::playback::device { enum class RecoveryTimelineImpactKind { TimelinePaused, TimelineReset, TimelineContinued, Unknown }; struct RecoveryTimelineImpact { RecoveryTimelineImpactKind kind{RecoveryTimelineImpactKind::Unknown}; kivo::playback::timeline::TimelineResetReason reset_reason{kivo::playback::timeline::TimelineResetReason::Seek}; }; }
