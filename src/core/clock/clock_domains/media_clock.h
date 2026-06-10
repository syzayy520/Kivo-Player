// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/core/clock/clock_domains/media_clock.h - Media clock contract.
// Depends on: clock_domain.h, core/timeline, standard library.
// Does NOT depend on: pipeline, runtime

#pragma once
#include "clock_domain.h"
#include "../../timeline/timestamp/media_timestamp.h"
#include <cstdint>

namespace kivo::playback::clock {

// MediaClockRelation - relationship of a media clock.
enum class MediaClockRelation {
    Unknown,
    MasterRef,
    SlaveRef,
    Independent,
};

// MediaClock - clock tracking media playback position.
struct MediaClock {
    ClockDomain domain{ClockDomain::PresentationReference};
    MediaClockRelation relation{MediaClockRelation::Independent};
    int master_ref_id{0};
    kivo::playback::timeline::MediaTimestamp current{{}, 0};
    double rate{1.0};
};

} // namespace kivo::playback::clock
