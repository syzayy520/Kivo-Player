// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/contracts/queue/contract.h - Packet queue contract (config/status/watermark only).
// Depends on: pipeline_result.h, pipeline_error.h, standard library.
// Does NOT depend on: real queue implementation, mutex, thread, packet storage.

#pragma once
#include "../pipeline_result.h"
#include "../pipeline_error.h"
#include <cstdint>

namespace kivo::pipeline::queue {

// QueueCapacityPolicy - policy for queue capacity management.
enum class QueueCapacityPolicy {
    PacketsOnly,      // limit by packet count
    BytesOnly,         // limit by byte size
    PacketsAndBytes,   // limit by both
};

// PacketQueueConfig - configuration for packet queue (contract only).
struct PacketQueueConfig {
    int64_t max_packets{1000};
    int64_t max_bytes{50 * 1024 * 1024};
    QueueCapacityPolicy policy{QueueCapacityPolicy::PacketsAndBytes};
    bool enable_backpressure{true};
};

// QueueWatermark - watermark levels for backpressure.
struct QueueWatermark {
    int64_t low_packets{200};
    int64_t high_packets{800};
    int64_t low_bytes{10 * 1024 * 1024};
    int64_t high_bytes{40 * 1024 * 1024};
};

// PacketQueueStatus - status of packet queue (contract only).
// BackpressureLevel reference: see flow/backpressure.h for canonical definition.
// Queue contract does NOT define or duplicate BackpressureLevel here.
struct PacketQueueStatus {
    int64_t current_packets{0};
    int64_t current_bytes{0};
    bool is_full{false};
};

// queue_configure - contract for queue configuration (no implementation here).
// Returns PipelineResult<PacketQueueConfig> or PipelineError.
struct QueueConfigureContract {
    // This is a contract-only struct.
    // Actual implementation will be in P0-004 (Packet Flow Contracts).
};

} // namespace kivo::pipeline::queue
