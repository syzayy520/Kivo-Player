// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/pipeline/contracts/packet_contract_tests.cpp - Packet contract tests.

#include "pipeline/contracts/packet/contract.h"
#include <iostream>
#include <cstdint>

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

void test_packet_info() {
    kivo::pipeline::packet::PacketInfo info;
    info.pts_ms = 1000;
    info.dts_ms = 1000;
    info.duration_ms = 40;
    info.size_bytes = 1024;
    info.type = kivo::pipeline::packet::PacketType::Video;
    info.flags.is_keyframe = true;
    CHECK(info.pts_ms == 1000);
    CHECK(info.type == kivo::pipeline::packet::PacketType::Video);
    CHECK(info.flags.is_keyframe);
}

void test_packet_buffer() {
    uint8_t dummy_data[16] = {0};
    kivo::pipeline::packet::PacketBuffer buf;
    buf.data = dummy_data;
    buf.size_bytes = 16;
    CHECK(buf.data != nullptr);
    CHECK(buf.size_bytes == 16);
}
