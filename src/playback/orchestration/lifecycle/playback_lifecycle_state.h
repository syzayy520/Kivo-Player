#pragma once
namespace kivo::playback::orchestration {
enum class PlaybackLifecycleState { Idle, Opening, Ready, Playing, Paused, Stopping, Stopped, Failed, Unknown };
}
