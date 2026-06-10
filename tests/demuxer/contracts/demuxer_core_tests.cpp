// Copyright (c) 2026 Kivo Project. All rights reserved.
// SPDX-License-Identifier: MIT
#include "demuxer/contracts/source/media_source_identity.h"
#include "demuxer/contracts/source/media_source.h"
#include "demuxer/contracts/session/demuxer_session.h"
#include "demuxer/contracts/selection/stream_selector.h"
#include "demuxer/contracts/selection/stream_selection_result.h"
#include "demuxer/contracts/seek/demux_seek.h"
#include "demuxer/contracts/packet/demux_packet_descriptor.h"
#include "demuxer/contracts/packet/packet_read_result.h"
#include "demuxer/contracts/policy/stream_policy.h"
#include "demuxer/contracts/policy/media_health_policy.h"
#include <cassert>
#include <cstdint>
#include <string>
#include <vector>

using namespace kivo::playback::demuxer;

// --- Declarations ---
int run_demuxer_seek_tests();
int run_demuxer_policy_tests();

// --- Source tests ---
static void test_media_source_identity() {
    MediaSourceIdentity id{};
    assert(id.source_id == 0);
    assert(id.locator_kind == MediaSourceLocatorKind::Unknown);
    assert(id.source_hint.empty());

    MediaSourceIdentity id2{42, MediaSourceLocatorKind::UserProvided, "hint"};
    assert(id2.source_id == 42);
    assert(id2.locator_kind == MediaSourceLocatorKind::UserProvided);
    assert(id2.source_hint == "hint");
}

static void test_media_source() {
    MediaSource src{};
    assert(src.identity.source_id == 0);
    assert(src.duration_us == 0);
    assert(src.stream_count == 0);
    assert(src.container_hint.family_id == 0);

    MediaSourceIdentity id{1, MediaSourceLocatorKind::OpaqueHint, ""};
    MediaSource src2{id, 10000000, 3, {1, 0}};
    assert(src2.identity.source_id == 1);
    assert(src2.duration_us == 10000000);
    assert(src2.stream_count == 3);
    assert(src2.container_hint.family_id == 1);
}

// --- Session tests ---
static void test_demuxer_session() {
    DemuxerSession s{};
    assert(s.state == DemuxerSessionState::Uninitialized);
    assert(s.source_id == 0);

    DemuxerSession s2{{42}, 1, DemuxerSessionState::Active};
    assert(s2.session_id.value == 42);
    assert(s2.source_id == 1);
    assert(s2.state == DemuxerSessionState::Active);
}

// --- Selection tests ---
static void test_stream_selector() {
    StreamSelector sel{};
    assert(sel.stream_id.value == 0);
    assert(sel.kind == DemuxStreamKind::Unknown);
    assert(sel.program_id.present == false);
    assert(sel.intent == StreamSelectionIntent::Auto);

    StreamSelector sel2{{0}, DemuxStreamKind::Video, {1, true}, StreamSelectionIntent::Select};
    assert(sel2.kind == DemuxStreamKind::Video);
    assert(sel2.program_id.value == 1);
    assert(sel2.program_id.present == true);
    assert(sel2.intent == StreamSelectionIntent::Select);
}

static void test_stream_selection_result() {
    StreamSelectionResult result{};
    assert(result.streams.empty());
    assert(result.program_count == 0);

    SelectedStream s{{1}, DemuxStreamKind::Audio, {0, false}, StreamSelectionStatus::Selected};
    result.streams.push_back(s);
    assert(result.streams.size() == 1);
    assert(result.streams[0].status == StreamSelectionStatus::Selected);
    assert(result.streams[0].kind == DemuxStreamKind::Audio);
}

// --- Seek tests are in demuxer_seek_tests.cpp ---

// --- Packet descriptor tests ---
static void test_demux_packet_descriptor() {
    DemuxPacketDescriptor pkt{};
    assert(pkt.packet_id == 0);
    assert(pkt.stream_id.value == 0);
    assert(pkt.kind == DemuxPacketKind::Media);
    assert(pkt.has_payload == false);
}

static void test_packet_read_result() {
    PacketReadResult r{};
    assert(r.status == PacketReadStatus::SourceUnavailable);
    assert(r.packet_presence == PacketDescriptorPresence::Absent);
    assert(r.error == DemuxerError::None);

    PacketReadResult r2{
        PacketReadStatus::PacketAvailable,
        PacketDescriptorPresence::Present,
        DemuxPacketDescriptor{},
        DemuxerError::None,
    };
    assert(r2.status == PacketReadStatus::PacketAvailable);
    assert(r2.packet_presence == PacketDescriptorPresence::Present);
}

// --- Policy tests are in demuxer_policy_tests.cpp ---

// --- Main ---
int main() {
    test_media_source_identity();
    test_media_source();
    test_demuxer_session();
    test_stream_selector();
    test_stream_selection_result();
    test_demux_packet_descriptor();
    test_packet_read_result();

    int seek_result = run_demuxer_seek_tests();
    assert(seek_result == 0);

    int policy_result = run_demuxer_policy_tests();
    assert(policy_result == 0);

    return 0;
}
