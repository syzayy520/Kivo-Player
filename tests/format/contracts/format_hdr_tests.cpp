// Copyright (c) 2026 Kivo Project. All rights reserved.
#include "format/contracts/hdr/mastering_display_metadata.h"
#include "format/contracts/hdr/content_light_metadata.h"
#include "format/contracts/hdr/hdr_static_metadata.h"
#include "format/contracts/hdr/hdr_dynamic_metadata_envelope.h"
#include <cassert>

int run_format_hdr_tests() {
    using namespace kivo::playback::format;
    MasteringDisplayMetadata mdm;
    mdm.max_luminance = 1000.0f;
    mdm.present = true;
    assert(mdm.present);
    ContentLightMetadata clm;
    clm.max_content_light_level = 400.0f;
    clm.present = true;
    HdrStaticMetadata sm{mdm, clm};
    assert(sm.content_light.max_content_light_level == 400.0f);
    HdrDynamicMetadataEnvelope dme{HdrDynamicMetadataType::ST2094_10, 1, true};
    assert(dme.type == HdrDynamicMetadataType::ST2094_10);
    assert(dme.version == 1);
    assert(dme.present);
    return 0;
}
