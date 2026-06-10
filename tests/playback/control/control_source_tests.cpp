#include <cassert>
#include <iostream>
#include "playback/control/source/control_source_id.h"
#include "playback/control/source/control_source_kind.h"
#include "playback/control/source/control_origin_kind.h"
#include "playback/control/source/control_source_identity.h"
namespace kivo::playback::control {
void run_control_source_tests() {
    ControlSourceId sid1; assert(sid1.value == 0); ControlSourceId sid2{10}; assert(sid2.value == 10);
    ControlSourceKind k1 = ControlSourceKind::User; ControlSourceKind k2 = ControlSourceKind::System;
    ControlSourceKind k3 = ControlSourceKind::Synthetic; ControlSourceKind k4 = ControlSourceKind::Internal;
    assert(k1 != k2); assert(k2 != k3); assert(k3 != k4);
    ControlOriginKind o1 = ControlOriginKind::Local; ControlOriginKind o2 = ControlOriginKind::Remote; ControlOriginKind o3 = ControlOriginKind::Restored;
    assert(o1 != o2); assert(o2 != o3);
    ControlSourceIdentity ident1;
    assert(ident1.source_id.value == 0); assert(ident1.kind == ControlSourceKind::Unknown); assert(ident1.origin == ControlOriginKind::Unknown);
    ControlSourceIdentity ident2{.source_id{5}, .kind{ControlSourceKind::Synthetic}, .origin{ControlOriginKind::Local}};
    assert(ident2.kind == ControlSourceKind::Synthetic);
    std::cout << "  control_source_tests: ALL PASSED\n";
}
}
