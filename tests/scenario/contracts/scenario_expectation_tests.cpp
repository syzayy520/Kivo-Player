#include <cassert>
#include <iostream>
#include "scenario/contracts/expectation/scenario_expectation_id.h"
#include "scenario/contracts/expectation/scenario_timing_expectation.h"
#include "scenario/contracts/expectation/scenario_presentation_expectation.h"
#include "scenario/contracts/expectation/scenario_recovery_expectation.h"

namespace kivo::playback::scenario {
void run_scenario_expectation_tests() {
    ScenarioExpectationId eid1;
    assert(eid1.value == 0);
    ScenarioExpectationId eid2{999};
    assert(eid2.value == 999);

    ScenarioTimingExpectation timing1;
    assert(timing1.expectation_id.value == 0);
    assert(timing1.expected_position.value == 0);
    assert(timing1.deadline.deadline_us == 0);
    ScenarioTimingExpectation timing2{
        .expectation_id{100},
        .expected_position{kivo::playback::timeline::MediaTimestamp{{}, 50000}},
        .deadline{kivo::playback::presentation::PresentationDeadline{33333, 1000}}
    };
    assert(timing2.expected_position.value == 50000);
    assert(timing2.deadline.deadline_us == 33333);

    ScenarioPresentationExpectation pres1;
    assert(pres1.expectation_id.value == 0);
    assert(pres1.expected_decision == kivo::playback::presentation::PresentationDecision::Unknown);
    ScenarioPresentationExpectation pres2{.expectation_id{200}, .expected_decision{kivo::playback::presentation::PresentationDecision::Present}};
    assert(pres2.expected_decision == kivo::playback::presentation::PresentationDecision::Present);

    ScenarioRecoveryExpectation rec1;
    assert(rec1.expectation_id.value == 0);
    assert(rec1.recovery_expected == false);
    ScenarioRecoveryExpectation rec2{.expectation_id{300}, .recovery_expected{true}};
    assert(rec2.recovery_expected == true);

    std::cout << "  scenario_expectation_tests: ALL PASSED\n";
}
}
