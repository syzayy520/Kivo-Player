#pragma once
namespace kivo::playback::audio {
enum class AudioRendererRole {
    PrimaryAudio,
    SecondaryAudio,
    PassthroughOnly,
    Unknown
};
}
