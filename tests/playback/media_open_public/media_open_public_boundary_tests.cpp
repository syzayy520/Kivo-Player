#include <cassert>
#include <iostream>

#include "playback/media_open_public/identity/media_open_public_identity.h"
#include "playback/media_open_public/anchor/playback_session_public_media_open_anchor.h"
#include "playback/media_open_public/open/playback_media_open_public.h"
#include "playback/media_open_public/outcome/media_open_public_outcome.h"

using namespace kivo::playback::media_open_public;

void test_media_open_public_boundary_cross_family() {
    {
        PlaybackSessionPublicMediaOpenAnchor anchor{};
        assert(anchor.session_identity.session_id.value == 0);
        assert(anchor.session_identity.sequence_id.value == 0);
        assert(anchor.session_identity.generation.value == 0);

        anchor.session_identity.session_id = kivo::playback::session_public::PlaybackSessionPublicId{123};
        assert(anchor.session_identity.session_id.value == 123);

        std::cout << "PASS: test_media_open_public_boundary_session_anchor" << std::endl;
    }

    {
        PlaybackMediaOpenPublic open{
            .identity = MediaOpenPublicIdentity{
                .open_id = MediaOpenPublicId{1},
                .sequence_id = MediaOpenPublicSequenceId{2},
                .generation = MediaOpenPublicGeneration{3}
            },
            .anchors = MediaOpenPublicAnchorSet{
                .session_anchor = PlaybackSessionPublicMediaOpenAnchor{
                    .session_identity = kivo::playback::session_public::PlaybackSessionPublicIdentity{
                        .session_id = kivo::playback::session_public::PlaybackSessionPublicId{10}
                    }
                }
            },
            .classification = MediaOpenPublicClassification{
                .kind = MediaOpenPublicKind::Local,
                .scope = MediaOpenPublicScope::Media
            }
        };

        assert(open.identity.open_id.value == 1);
        assert(open.identity.sequence_id.value == 2);
        assert(open.identity.generation.value == 3);
        assert(open.anchors.session_anchor.session_identity.session_id.value == 10);
        assert(open.classification.kind == MediaOpenPublicKind::Local);
        assert(open.classification.scope == MediaOpenPublicScope::Media);

        std::cout << "PASS: test_media_open_public_boundary_structural_completeness" << std::endl;
    }

    {
        MediaOpenPublicOutcome outcome{
            .identity = MediaOpenPublicIdentity{
                .open_id = MediaOpenPublicId{42}
            },
            .status = MediaOpenPublicStatus::Recorded
        };

        assert(outcome.identity.open_id.value == 42);
        assert(outcome.status == MediaOpenPublicStatus::Recorded);
        assert(outcome.identity.sequence_id.value == 0);
        assert(outcome.identity.generation.value == 0);

        std::cout << "PASS: test_media_open_public_boundary_outcome" << std::endl;
    }
}
