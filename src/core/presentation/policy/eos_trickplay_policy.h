// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
namespace kivo::playback::presentation {
enum class EosPresentationPolicy { Unknown, DrainAllThenStop, StopImmediately, HoldLast };
enum class TrickplayPolicy { Unknown, AnchorUnitsOnly, DecimateUnits, SparseUnits, AllUnits };
}
