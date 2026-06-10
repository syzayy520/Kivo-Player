// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/pipeline/contracts/queue_contract_tests.cpp - Queue contract tests.

#include "pipeline/contracts/queue/contract.h"
#include <iostream>

extern int g_passed_checks;
extern int g_failed_checks;

#define CHECK(cond) \
    do { \
        if (!(cond)) { \
            ++g_failed_checks; \
            std::cerr << "FAILED: " << __FILE__ << ":" << __LINE__ << ": " << #cond << std::endl; \
        } else { \
            ++g_passed_checks; \
        } \
    } while(0)

void test_queue_config() {
    kivo::pipeline::queue::PacketQueueConfig cfg;
    cfg.max_packets = 1000;
    cfg.max_bytes = 50 * 1024 * 1024;
    cfg.policy = kivo::pipeline::queue::QueueCapacityPolicy::PacketsAndBytes;
    CHECK(cfg.max_packets == 1000);
    CHECK(cfg.policy == kivo::pipeline::queue::QueueCapacityPolicy::PacketsAndBytes);
}

void test_queue_status() {
    kivo::pipeline::queue::PacketQueueStatus status;
    status.current_packets = 100;
    status.current_bytes = 5 * 1024 * 1024;
    status.is_full = false;
    CHECK(status.current_packets == 100);
    CHECK(status.current_bytes == 5 * 1024 * 1024);
    CHECK(!status.is_full);
}
