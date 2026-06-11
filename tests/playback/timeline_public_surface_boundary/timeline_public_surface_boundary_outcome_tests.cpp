#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/timeline_public_surface_boundary/outcome/timeline_public_surface_boundary_outcome.h"
#include "playback/timeline_public_surface_boundary/outcome/timeline_public_surface_boundary_rejection_reason.h"
#include "playback/timeline_public_surface_boundary/outcome/timeline_public_surface_boundary_drop_reason.h"

using namespace kivo::playback::timeline_public_surface_boundary;

void test_surface_boundary_outcome_default_construction() {
    {
        assert(static_cast<std::uint8_t>(TimelinePublicSurfaceBoundaryStatus::Recorded) == 0);
        assert(static_cast<std::uint8_t>(TimelinePublicSurfaceBoundaryStatus::Rejected) == 1);
        assert(static_cast<std::uint8_t>(TimelinePublicSurfaceBoundaryStatus::Dropped) == 2);
        assert(static_cast<std::uint8_t>(TimelinePublicSurfaceBoundaryStatus::Unknown) == 3);
        std::cout << "PASS: test_surface_boundary_status_enum_values" << std::endl;
    }

    {
        assert(static_cast<std::uint8_t>(TimelinePublicSurfaceBoundaryRejectionReason::ResponseAnchorMissing) == 0);
        assert(static_cast<std::uint8_t>(TimelinePublicSurfaceBoundaryRejectionReason::ClassificationInvalid) == 1);
        assert(static_cast<std::uint8_t>(TimelinePublicSurfaceBoundaryRejectionReason::BoundaryIdentityMissing) == 2);
        assert(static_cast<std::uint8_t>(TimelinePublicSurfaceBoundaryRejectionReason::Unknown) == 3);
        std::cout << "PASS: test_surface_boundary_rejection_reason_enum_values" << std::endl;
    }

    {
        assert(static_cast<std::uint8_t>(TimelinePublicSurfaceBoundaryDropReason::Superseded) == 0);
        assert(static_cast<std::uint8_t>(TimelinePublicSurfaceBoundaryDropReason::LowerPriority) == 1);
        assert(static_cast<std::uint8_t>(TimelinePublicSurfaceBoundaryDropReason::Unknown) == 2);
        std::cout << "PASS: test_surface_boundary_drop_reason_enum_values" << std::endl;
    }

    TimelinePublicSurfaceBoundaryOutcome outcome{};
    assert(outcome.identity.boundary_id.value == 0);
    assert(outcome.status == TimelinePublicSurfaceBoundaryStatus::Unknown);

    TimelinePublicSurfaceBoundaryOutcome outcome2{
        .identity = TimelinePublicSurfaceBoundaryIdentity{
            .boundary_id = TimelinePublicSurfaceBoundaryId{1}
        },
        .status = TimelinePublicSurfaceBoundaryStatus::Recorded
    };
    assert(outcome2.identity.boundary_id.value == 1);
    assert(outcome2.status == TimelinePublicSurfaceBoundaryStatus::Recorded);

    assert(outcome == outcome);
    assert(!(outcome == outcome2));

    std::cout << "PASS: test_surface_boundary_outcome_default_construction" << std::endl;

    outcome.identity.boundary_id = TimelinePublicSurfaceBoundaryId{999};
    outcome.status = TimelinePublicSurfaceBoundaryStatus::Rejected;

    assert(outcome.identity.boundary_id.value == 999);
    assert(outcome.status == TimelinePublicSurfaceBoundaryStatus::Rejected);

    std::cout << "PASS: test_surface_boundary_outcome_field_modification" << std::endl;
}
