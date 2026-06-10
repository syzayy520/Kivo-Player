#pragma once
#include "renderer_id.h"
#include "renderer_role.h"
namespace kivo::playback::render {
struct RendererIdentity {
    RendererId id{};
    RendererRole role{RendererRole::Unknown};
};
}
