#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_command_admission/classification/p2_public_command_admission_classification.h"

using namespace kivo::playback::p2_public_command_admission;

void test_p2_public_command_admission_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicCommandAdmissionKind::PlayIntent) == 0);
    assert(static_cast<std::uint8_t>(P2PublicCommandAdmissionKind::PauseIntent) == 1);
    assert(static_cast<std::uint8_t>(P2PublicCommandAdmissionKind::NavigationIntent) == 2);
    assert(static_cast<std::uint8_t>(P2PublicCommandAdmissionKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicCommandAdmissionScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicCommandAdmissionScope::IntakeBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicCommandAdmissionScope::CommandBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicCommandAdmissionScope::Unknown) == 3);
    P2PublicCommandAdmissionClassification classification{};
    assert(classification.kind == P2PublicCommandAdmissionKind::Unknown);
    assert(classification.scope == P2PublicCommandAdmissionScope::Unknown);
    std::cout << "PASS: test_p2_public_command_admission_classification_default_construction" << std::endl;
}
