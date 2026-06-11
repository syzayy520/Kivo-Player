#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/public_error_recovery/classification/public_error_recovery_classification.h"

using namespace kivo::playback::public_error_recovery;

void test_public_error_recovery_classification_default_construction() {
    assert(static_cast<std::uint8_t>(PublicErrorRecoveryKind::EndReached) == 0);
    assert(static_cast<std::uint8_t>(PublicErrorRecoveryKind::Recoverable) == 1);
    assert(static_cast<std::uint8_t>(PublicErrorRecoveryKind::Terminal) == 2);
    assert(static_cast<std::uint8_t>(PublicErrorRecoveryKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(PublicErrorRecoveryScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(PublicErrorRecoveryScope::EndOfStream) == 1);
    assert(static_cast<std::uint8_t>(PublicErrorRecoveryScope::Timeline) == 2);
    assert(static_cast<std::uint8_t>(PublicErrorRecoveryScope::Unknown) == 3);
    PublicErrorRecoveryClassification cls{};
    assert(cls.kind == PublicErrorRecoveryKind::Unknown);
    assert(cls.scope == PublicErrorRecoveryScope::Unknown);
    std::cout << "PASS: test_public_error_recovery_classification_default_construction" << std::endl;
}
