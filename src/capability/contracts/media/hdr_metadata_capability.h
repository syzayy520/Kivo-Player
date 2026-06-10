#pragma once
#include <vector>
#include "../../../format/contracts/hdr/hdr_dynamic_metadata_envelope.h"
#include "../scope/capability_level.h"
namespace kivo::playback::capability {
struct HdrMetadataCapability { bool static_metadata_readable{false}; bool dynamic_metadata_readable{false}; std::vector<kivo::playback::format::HdrDynamicMetadataType> dynamic_types; CapabilityLevel level{CapabilityLevel::Unknown}; };
}
