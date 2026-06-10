#pragma once
#include <cstdint>
namespace kivo::playback::device { struct RecoveryAttemptBudget { uint32_t max_attempts{0}; uint32_t attempts_made{0}; }; }
