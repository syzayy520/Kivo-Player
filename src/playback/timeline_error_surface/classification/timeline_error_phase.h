#pragma once
namespace kivo::playback::timeline_error_surface {
enum class TimelineErrorPhase { BeforeDecision, DuringDecision, AfterResult, DuringSnapshot, DuringSummary, DuringChainIntegrity, Unknown };
}
