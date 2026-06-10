// Copyright (c) 2026 Kivo Project. All rights reserved.
#include "format/contracts/identity/codec_family.h"
#include "format/contracts/identity/codec_profile.h"
#include "format/contracts/identity/media_stream_kind.h"
#include "format/contracts/identity/media_format_identity.h"
#include <cassert>

int run_format_video_audio_tests();
int run_format_color_tests();
int run_format_hdr_tests();
int run_format_compatibility_tests();

int main() {
    assert(static_cast<int>(kivo::playback::format::CodecFamily::Unknown) == 0);
    assert(static_cast<int>(kivo::playback::format::MediaStreamKind::Unknown) == 0);
    kivo::playback::format::CodecProfile cp{kivo::playback::format::CodecFamily::H264, 100, 40};
    assert(cp.family == kivo::playback::format::CodecFamily::H264);
    assert(cp.profile_idc == 100);
    assert(cp.level_idc == 40);
    kivo::playback::format::MediaFormatIdentity id{cp, 0, kivo::playback::format::MediaStreamKind::Video};
    assert(id.stream_kind == kivo::playback::format::MediaStreamKind::Video);
    assert(run_format_video_audio_tests() == 0);
    assert(run_format_color_tests() == 0);
    assert(run_format_hdr_tests() == 0);
    assert(run_format_compatibility_tests() == 0);
    return 0;
}
