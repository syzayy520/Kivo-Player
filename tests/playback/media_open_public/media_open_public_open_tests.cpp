#include <cassert>
#include <iostream>

#include "playback/media_open_public/open/playback_media_open_public.h"
#include "playback/media_open_public/open/media_open_public_candidate.h"
#include "playback/media_open_public/open/media_open_public_envelope.h"
#include "playback/media_open_public/open/media_open_public_record.h"

using namespace kivo::playback::media_open_public;

void test_media_open_public_open_default_construction() {
    MediaOpenPublicCandidate candidate{};
    assert(candidate.identity.open_id.value == 0);
    assert(candidate.anchors.session_anchor.session_identity.session_id.value == 0);
    assert(candidate.classification.kind == MediaOpenPublicKind::Unknown);

    MediaOpenPublicCandidate candidate2{
        .identity = MediaOpenPublicIdentity{
            .open_id = MediaOpenPublicId{1}
        }
    };
    assert(candidate2.identity.open_id.value == 1);

    std::cout << "PASS: test_media_open_public_candidate_default_construction" << std::endl;

    PlaybackMediaOpenPublic open{};
    assert(open.identity.open_id.value == 0);
    assert(open.classification.kind == MediaOpenPublicKind::Unknown);

    PlaybackMediaOpenPublic open2{
        .identity = MediaOpenPublicIdentity{
            .open_id = MediaOpenPublicId{10}
        },
        .classification = MediaOpenPublicClassification{
            .kind = MediaOpenPublicKind::Local
        }
    };
    assert(open2.identity.open_id.value == 10);
    assert(open2.classification.kind == MediaOpenPublicKind::Local);

    std::cout << "PASS: test_media_open_public_default_construction" << std::endl;

    MediaOpenPublicEnvelope envelope{};
    assert(envelope.identity.open_id.value == 0);

    MediaOpenPublicEnvelope envelope2{
        .identity = MediaOpenPublicIdentity{
            .open_id = MediaOpenPublicId{20}
        }
    };
    assert(envelope2.identity.open_id.value == 20);

    std::cout << "PASS: test_media_open_public_envelope_default_construction" << std::endl;

    MediaOpenPublicRecord record{};
    assert(record.envelope.identity.open_id.value == 0);
    assert(record.open.identity.open_id.value == 0);

    MediaOpenPublicRecord record2{
        .envelope = MediaOpenPublicEnvelope{
            .identity = MediaOpenPublicIdentity{
                .open_id = MediaOpenPublicId{30}
            }
        },
        .open = PlaybackMediaOpenPublic{
            .identity = MediaOpenPublicIdentity{
                .open_id = MediaOpenPublicId{40}
            }
        }
    };
    assert(record2.envelope.identity.open_id.value == 30);
    assert(record2.open.identity.open_id.value == 40);

    std::cout << "PASS: test_media_open_public_record_default_construction" << std::endl;

    record.envelope.identity.open_id = MediaOpenPublicId{50};
    record.open.identity.open_id = MediaOpenPublicId{60};

    assert(record.envelope.identity.open_id.value == 50);
    assert(record.open.identity.open_id.value == 60);

    std::cout << "PASS: test_media_open_public_record_field_modification" << std::endl;
}
