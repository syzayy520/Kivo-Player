#pragma once
namespace kivo::playback::audio {
enum class AudioEndpointRole {
    PrimaryPlayback,
    SecondaryPlayback,
    DiagnosticPlayback,
    Unknown
};
}
