#pragma once
#include "control_source_id.h"
#include "control_source_kind.h"
#include "control_origin_kind.h"
namespace kivo::playback::control {
struct ControlSourceIdentity {
    ControlSourceId source_id{};
    ControlSourceKind kind{ControlSourceKind::Unknown};
    ControlOriginKind origin{ControlOriginKind::Unknown};
};
}
