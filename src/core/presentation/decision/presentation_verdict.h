// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
namespace kivo::playback::presentation {
enum class PresentationTimingVerdict { Unknown, OnTime, Early, Late, TooLate };
enum class PresentationReadiness { Ready, NotReady, Stale, Superseded };
}
