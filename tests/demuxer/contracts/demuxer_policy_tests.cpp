// Copyright (c) 2026 Kivo Project. All rights reserved.
// SPDX-License-Identifier: MIT
#include "demuxer/contracts/policy/stream_policy.h"
#include "demuxer/contracts/policy/media_health_policy.h"
#include <cassert>

using namespace kivo::playback::demuxer;

int run_demuxer_policy_tests() {
    // SparseStreamPolicy
    SparseStreamPolicy sp = SparseStreamPolicy::Include;
    assert(sp == SparseStreamPolicy::Include);
    sp = SparseStreamPolicy::Exclude;
    assert(sp == SparseStreamPolicy::Exclude);
    sp = SparseStreamPolicy::Conditional;
    assert(sp == SparseStreamPolicy::Conditional);

    // AttachmentPolicy
    AttachmentPolicy ap = AttachmentPolicy::Include;
    assert(ap == AttachmentPolicy::Include);
    ap = AttachmentPolicy::Exclude;
    assert(ap == AttachmentPolicy::Exclude);
    ap = AttachmentPolicy::ParseInlineOnly;
    assert(ap == AttachmentPolicy::ParseInlineOnly);

    // ChapterPolicy
    ChapterPolicy cp = ChapterPolicy::Skip;
    assert(cp == ChapterPolicy::Skip);
    cp = ChapterPolicy::Forward;
    assert(cp == ChapterPolicy::Forward);
    cp = ChapterPolicy::ParseAndExpose;
    assert(cp == ChapterPolicy::ParseAndExpose);

    // MultiProgramPolicy
    MultiProgramPolicy mp = MultiProgramPolicy::AutoSelectFirst;
    assert(mp == MultiProgramPolicy::AutoSelectFirst);
    mp = MultiProgramPolicy::ManualSelect;
    assert(mp == MultiProgramPolicy::ManualSelect);
    mp = MultiProgramPolicy::ExposeAll;
    assert(mp == MultiProgramPolicy::ExposeAll);

    // DamagedMediaPolicy
    DamagedMediaPolicy dmp = DamagedMediaPolicy::FailFast;
    assert(dmp == DamagedMediaPolicy::FailFast);
    dmp = DamagedMediaPolicy::SkipDamagedUnits;
    assert(dmp == DamagedMediaPolicy::SkipDamagedUnits);
    dmp = DamagedMediaPolicy::BestEffort;
    assert(dmp == DamagedMediaPolicy::BestEffort);

    // TruncatedMediaPolicy
    TruncatedMediaPolicy tmp = TruncatedMediaPolicy::FailFast;
    assert(tmp == TruncatedMediaPolicy::FailFast);
    tmp = TruncatedMediaPolicy::ReadAvailable;
    assert(tmp == TruncatedMediaPolicy::ReadAvailable);
    tmp = TruncatedMediaPolicy::UseAvailableIndex;
    assert(tmp == TruncatedMediaPolicy::UseAvailableIndex);

    return 0;
}
