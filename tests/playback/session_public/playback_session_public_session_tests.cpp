#include <cassert>
#include <iostream>

#include "playback/session_public/session/playback_session_public.h"
#include "playback/session_public/session/playback_session_public_candidate.h"
#include "playback/session_public/session/playback_session_public_envelope.h"
#include "playback/session_public/session/playback_session_public_record.h"

using namespace kivo::playback::session_public;

void test_session_public_session_default_construction() {
    PlaybackSessionPublicCandidate candidate{};
    assert(candidate.identity.session_id.value == 0);
    assert(candidate.anchors.phase_anchor.phase_identity.phase_id.value == 0);
    assert(candidate.classification.kind == PlaybackSessionPublicKind::Unknown);

    PlaybackSessionPublicCandidate candidate2{
        .identity = PlaybackSessionPublicIdentity{
            .session_id = PlaybackSessionPublicId{1}
        }
    };
    assert(candidate2.identity.session_id.value == 1);

    std::cout << "PASS: test_session_public_candidate_default_construction" << std::endl;

    PlaybackSessionPublic session{};
    assert(session.identity.session_id.value == 0);
    assert(session.classification.kind == PlaybackSessionPublicKind::Unknown);

    PlaybackSessionPublic session2{
        .identity = PlaybackSessionPublicIdentity{
            .session_id = PlaybackSessionPublicId{10}
        },
        .classification = PlaybackSessionPublicClassification{
            .kind = PlaybackSessionPublicKind::Created
        }
    };
    assert(session2.identity.session_id.value == 10);
    assert(session2.classification.kind == PlaybackSessionPublicKind::Created);

    std::cout << "PASS: test_session_public_default_construction" << std::endl;

    PlaybackSessionPublicEnvelope envelope{};
    assert(envelope.identity.session_id.value == 0);

    PlaybackSessionPublicEnvelope envelope2{
        .identity = PlaybackSessionPublicIdentity{
            .session_id = PlaybackSessionPublicId{20}
        }
    };
    assert(envelope2.identity.session_id.value == 20);

    std::cout << "PASS: test_session_public_envelope_default_construction" << std::endl;

    PlaybackSessionPublicRecord record{};
    assert(record.envelope.identity.session_id.value == 0);
    assert(record.session.identity.session_id.value == 0);

    PlaybackSessionPublicRecord record2{
        .envelope = PlaybackSessionPublicEnvelope{
            .identity = PlaybackSessionPublicIdentity{
                .session_id = PlaybackSessionPublicId{30}
            }
        },
        .session = PlaybackSessionPublic{
            .identity = PlaybackSessionPublicIdentity{
                .session_id = PlaybackSessionPublicId{40}
            }
        }
    };
    assert(record2.envelope.identity.session_id.value == 30);
    assert(record2.session.identity.session_id.value == 40);

    std::cout << "PASS: test_session_public_record_default_construction" << std::endl;

    record.envelope.identity.session_id = PlaybackSessionPublicId{50};
    record.session.identity.session_id = PlaybackSessionPublicId{60};

    assert(record.envelope.identity.session_id.value == 50);
    assert(record.session.identity.session_id.value == 60);

    std::cout << "PASS: test_session_public_record_field_modification" << std::endl;
}
