# src/core/manager - Playback Manager

## Responsibility

Manager is the formal coordination layer in Command → Manager → Engine architecture chain.

- Receives `PlaybackCommand` from external callers (UI, IPC, script)
- Coordinates `PlaybackEngine` to execute commands
- Manages `PlaybackSession` lifecycle
- Emits `PlaybackEvent` to `IPlaybackEventSink`

## Files

- `playback_manager.h` - `PlaybackManager` class definition

## Rules

- Manager is NOT a bucket directory
- Manager is a formal coordination layer
- Manager must NOT be deleted
