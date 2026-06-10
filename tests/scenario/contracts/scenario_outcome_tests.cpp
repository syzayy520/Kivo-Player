#include <cassert>
#include <iostream>
#include "scenario/contracts/outcome/scenario_outcome_status.h"
#include "scenario/contracts/outcome/scenario_outcome.h"
#include "scenario/contracts/outcome/scenario_failure_reason.h"
#include "scenario/contracts/outcome/scenario_drop_reason.h"

namespace kivo::playback::scenario {
void run_scenario_outcome_tests() {
    ScenarioOutcomeStatus s1 = ScenarioOutcomeStatus::Passed;
    ScenarioOutcomeStatus s2 = ScenarioOutcomeStatus::Failed;
    ScenarioOutcomeStatus s3 = ScenarioOutcomeStatus::Dropped;
    assert(s1 != s2); assert(s2 != s3);

    ScenarioOutcome outcome1;
    assert(outcome1.scenario_id.value == 0);
    assert(outcome1.status == ScenarioOutcomeStatus::Unknown);
    ScenarioOutcome outcome2{.scenario_id{ScenarioId{777}}, .status{ScenarioOutcomeStatus::Passed}};
    assert(outcome2.scenario_id.value == 777);
    assert(outcome2.status == ScenarioOutcomeStatus::Passed);

    ScenarioFailureReason f1 = ScenarioFailureReason::ExpectationUnmet;
    ScenarioFailureReason f2 = ScenarioFailureReason::DeadlineMissed;
    ScenarioFailureReason f3 = ScenarioFailureReason::ResourceLimitExceeded;
    assert(f1 != f2); assert(f2 != f3);

    ScenarioDropReason d1 = ScenarioDropReason::Preempted;
    ScenarioDropReason d2 = ScenarioDropReason::PriorityOverridden;
    assert(d1 != d2);

    std::cout << "  scenario_outcome_tests: ALL PASSED\n";
}
}
