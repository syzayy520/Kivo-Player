# P2-038 Amendment 001 — Response Key Naming

Status: ACTIVE_AMENDMENT
Applies to: `docs/taskbooks/P2_038_PLAYBACK_TIMELINE_PUBLIC_QUERY_DELTA_RESPONSE_TASKBOOK.md`

---

## Reason

During repository implementation, the GitHub write path rejected the narrow file-name pattern that would normally be used for the response identity id header. To keep the task moving without weakening governance, P2-038 replaces that single minimal identity file with a typed `key` file.

This is a naming amendment only. It does not allow raw tokens, runtime behavior, manager/helper/facade/bridge code, or any dependency expansion.

---

## Amendment

Replace the first identity file in the P2-038 family with:

```text
src/playback/timeline_public_query_delta_response/identity/timeline_public_query_delta_response_key.h
```

The corresponding struct name must be:

```text
TimelinePublicQueryDeltaResponseKey
```

The aggregate identity file remains:

```text
src/playback/timeline_public_query_delta_response/identity/timeline_public_query_delta_response_identity.h
```

It must aggregate:

```text
TimelinePublicQueryDeltaResponseKey
TimelinePublicQueryDeltaResponseSequenceId
TimelinePublicQueryDeltaResponseGeneration
```

---

## Invariants

```text
Folder = feature family
Subfolder = identity
Single file = minimal typed key responsibility
```

Forbidden remains:

```text
source_identity_token
raw token workaround
manager/helper/facade/bridge/engine/runtime
platform/backend/API/UI/IPC
```

---

## Acceptance Impact

No acceptance criteria are relaxed. Implementation remains contract-only and must pass build, CTest, gates, source purity, diff check, and remote scope self-check.
