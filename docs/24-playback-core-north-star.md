# Kivo Playback Core North Star

**Version**: V1.0  
**Date**: 2026-06-10  
**Status**: ACTIVE  
**Scope**: P0-002 to P0-028  

---

## 1. Kivo Playback Core North Star

Kivo Video 的播放核心最终目标不是"能播放一个文件"，而是建立一个长期可演进、可验证、可调试、可商业化的专业播放核心。

**最终方向**：

```
Kivo Playback Core =
Command-driven playback brain
+ Deterministic state machine
+ Session generation model
+ Media probe model
+ Pipeline graph
+ Packet flow
+ Decode contracts
+ A/V sync
+ Clock hierarchy
+ Output contracts
+ Capability model
+ Diagnostics
+ Quality gates
+ Adapter isolation
```

**Kivo Playback Core 必须成为产品的大脑**：

- UI 只能发命令
- Engine 决定状态
- Pipeline 管媒体流
- Decoder 只解码
- Output 只输出
- CapabilityModel 决定能不能宣称能力
- Diagnostics 负责定位问题
- Adapter 只接外部库，不反过来控制 Kivo

---

## 2. What We Are Building

Kivo 要做的是：

```
一个 Windows-first、C++23、自研播放核心的专业本地视频播放器。
```

**播放核心方向必须对齐**：

```
1. 自研 Engine
2. 自研 State Machine
3. 自研 Session lifecycle
4. 自研 Pipeline contracts
5. 自研 Clock / A/V sync policy
6. 自研 CapabilityModel
7. 自研 Error / Result / Event model
8. 自研 Diagnostics / Trace model
9. FFmpeg Adapter later
10. D3D11 Video Output Adapter later
11. WASAPI Audio Output Adapter later
12. HDR / Dolby policy later
13. Subtitle pipeline later
14. Sample matrix / stress gates later
```

- Kivo 可以使用 FFmpeg，但 FFmpeg 只能是 Adapter
- Kivo 可以参考 mpv / madVR，但它们不能成为 Kivo 的主脑
- Kivo 可以调用系统能力，但不能把系统能力包装成 Kivo 已完整支持

---

## 3. What We Are Not Building

**Kivo Playback Core 不是**：

```
mpv shell
libmpv backend wrapper
FFmpeg demo player
Qt multimedia player
Tauri / Electron / WebView player
播放器 UI 项目
资源聚合产品
下载器
磁力播放器
torrent 播放器
网盘转存工具
盗版内容入口
DRM 绕过工具
```

**也不是**：

```
一个 player.cpp 里什么都做
一个 engine.cpp 里什么都塞
一个 manager 变成 god object
一个 renderer 同时做解码、同步、输出、字幕、HDR
一个 utils/common/helper/types/stubs/domain 桶目录
```

---

## 4. Final Playback Core Shape

**最终播放核心应该长成以下结构**：

```
Product / UI
  ↓
PlaybackCommand
  ↓
PlaybackManager
  ↓
PlaybackEngine
  ↓
PlaybackSession
  ↓
MediaPipeline
  ↓
PacketFlow
  ↓
DecoderAdapter
  ↓
FrameQueue
  ↓
SyncController
  ↓
OutputAdapter
```

**旁路系统**：

```
CapabilityModel
Diagnostics / Trace
ErrorModel
ClockModel
TimelineModel
CancellationModel
QualityGateModel
```

**长期核心线程模型方向**：

```
UI thread:
- only sends commands
- receives events
- never blocks on decode/output

Engine serial executor:
- serializes command handling
- owns state transition
- owns session generation
- rejects stale command results

Pipeline worker:
- future probe/demux/packet flow
- cancellable
- generation-aware

Decoder workers:
- future video/audio/subtitle decode
- bounded queues
- flush/drain aware

Output coordination:
- future video present
- future audio render
- clock feedback
- underrun/late-frame reporting
```

- P0-001 不实现线程
- P0-002 到 P0-009 也主要建立 contracts
- 真实 backend 必须在后续 adapter ticket 中接入

---

## 5. State Machine Direction

State machine 是播放核心的骨架。

**长期状态**：

```
Idle
Opening
Probing
Ready
Playing
Paused
Seeking
Buffering
Ended
Error
Closing
Closed
```

**规则**：

```
1. UI 不直接改状态
2. Pipeline 不直接改状态
3. Decoder 不直接改状态
4. Output 不直接改状态
5. 只有 Engine 通过 StateMachine 迁移状态
6. 所有失败必须返回 PlaybackResult
7. 所有失败必须可转成 PlaybackError
8. 成功状态迁移必须先发 StateChanged，再发业务事件
9. 失败命令只能发 ErrorRaised，不允许偷偷改状态
10. Close 必须可确定，不允许析构时阻塞等待未知任务
```

---

## 6. Command Direction

Command 是用户意图，不是实现细节。

**Command 只能表达**：

```
OpenMedia
Play
Pause
TogglePause
Seek
Stop
Close
SetPlaybackRate
SelectAudioTrack
SelectSubtitleTrack
SetVolume
Mute
Unmute
```

**Command 禁止包含**：

```
FFmpeg 类型
D3D11 类型
DXGI 类型
WASAPI 类型
Win32 HWND
Qt 类型
UI 文案
文件 IO 细节
网络下载语义
资源搜索语义
```

**Command 必须先 validate，再进入 Engine 行为**。非法 command 不允许污染状态机。

---

## 7. Session / Generation Direction

Kivo 必须从第一天有 Session / Generation 思维。

**长期规则**：

```
1. 每次 OpenMedia 创建新的 SessionId
2. 每次新 session 增加 GenerationId
3. 旧 generation 的异步结果不得覆盖新 session
4. Seek / Close / Open 必须可取消
5. Closing / Closed 是正式状态，不是随手清理
6. Session 不等于文件路径
7. Session 不等于 FFmpeg context
8. Session 是 Kivo 自己的播放生命周期身份
```

**这能防止后续出现**：

```
旧 seek 回调覆盖新播放
旧 decoder 结果写入新 output
关闭时线程挂死
打开失败后状态错乱
快速切片导致崩溃
```

---

## 8. Pipeline Direction

Pipeline 不是 FFmpeg。

Pipeline 是 Kivo 自己的媒体流边界：

```
Probe
Demux
Stream selection
Packet source
Packet queue
Backpressure
Flush
Drain
Seek
Discontinuity
End of stream
Cancellation
Generation guard
```

- P0-002 必须先做 Pipeline contracts
- P0-003 做 Probe model
- P0-004 做 Packet flow contracts
- 真实 FFmpeg probe/demux 必须等 P0-010/P0-011

**禁止在 P0-002 到 P0-004 直接 include FFmpeg**。

---

## 9. Decode Direction

Decoder 不是播放核心的大脑。

Decoder 只负责：

```
Input packet
Decode
Flush
Drain
Reconfigure
Output video frame / audio frame / subtitle sample
Return decode result
Report decode error
```

**Decoder 禁止**：

```
控制 Engine 状态
知道 UI
直接控制 VideoOutput
直接控制 AudioOutput
直接决定 HDR badge
暴露 FFmpeg type 到 core public API
```

- P0-005 才做 Decode contracts
- 真实 FFmpeg decode adapter 必须等 P0-012

---

## 10. A/V Sync Direction

最强播放核心不能只"能解码"，必须有同步策略。

**长期 A/V sync 方向**：

```
Master clock
Audio clock
Video clock
External/system clock placeholder
Drift detection
Correction policy
Late frame policy
Frame drop policy
Audio underrun reporting
Seek discontinuity handling
Playback rate handling
Pause/resume clock freeze
End-of-stream coordination
```

- P0-006 只定义 contracts
- 真实 audio clock / video present feedback 后续再接

---

## 11. Output Direction

Output 是平台适配层，不是 core API。

**Video output 长期方向**：

```
Surface abstraction
Frame present contract
Color metadata
HDR metadata placeholder
Frame pacing result
Present result
Device lost error
Resize / fullscreen boundary
```

**Audio output 长期方向**：

```
Device abstraction
Audio format
Buffer model
Latency model
Underrun model
Shared mode
Exclusive mode
Passthrough placeholder
Clock feedback
```

- P0-007 做 Video Output contracts，不接 D3D11
- P0-008 做 Audio Output contracts，不接 WASAPI
- 真实 D3D11 在 P0-013
- 真实 WASAPI 在 P0-014

---

## 12. Capability Direction

CapabilityModel 是防止虚假宣传的核心。

**必须区分**：

```
DetectedCapability
ParsedCapability
SupportedCapability
OutputCapability
VerifiedCapability
DisplayableBadge
```

**规则**：

```
检测到 HDR metadata ≠ 支持 HDR 输出
检测到 Dolby Vision ≠ 支持 Dolby Vision
能 fallback 到 HDR10 ≠ 完整 Dolby Vision
检测到 Atmos 音轨 ≠ 能输出 Atmos
设备支持某能力 ≠ Kivo 已验证该能力
第三方库可解析 ≠ Kivo 商业可宣称
```

所有 HDR / Dolby / Atmos / DTS / passthrough / exclusive mode / hardware decode / DRM 相关能力，必须等真实 adapter、设备检测、样本验证、合规确认之后才能展示为 Verified。

---

## 13. Diagnostics Direction

专业播放器必须可诊断。

**长期 diagnostics 方向**：

```
Command trace
Session trace
Generation trace
Pipeline trace
Packet trace
Decode trace
Output trace
Clock trace
Error trace
Latency marker
State transition log
Diagnostic snapshot
```

- 不做云上报
- 不收集隐私
- 不上传用户路径
- 本地诊断必须可关闭
- 日志必须脱敏

P0-019 做 diagnostics contracts。

---

## 14. Quality Direction

最强播放器不是"能跑一次"，而是长期稳定。

**必须逐步建立**：

```
Open/close storm
Seek storm
Long-run test
Bad media test
Large file test
Multi-track test
Subtitle stress
High bitrate placeholder
A/V sync budget
Memory budget
Thread shutdown budget
Frame pacing budget
Audio latency budget
Crash-free baseline
```

- P0-020 到 P0-024 会逐步建立这些 gate
- P0-001 到 P0-009 不能跳过质量模型

---

## 15. Adapter Direction

所有外部能力必须通过 Adapter 接入。

**允许未来 Adapter**：

```
FFmpegProbeAdapter
FFmpegDemuxAdapter
FFmpegDecodeAdapter
D3D11VideoOutputAdapter
WasapiAudioOutputAdapter
LibassSubtitleAdapter
LibplaceboResearchAdapter if approved later
```

**禁止**：

```
libmpv production backend
mpv backend
FFmpeg context 泄漏到 core
D3D11 object 泄漏到 command/engine
WASAPI object 泄漏到 command/engine
Qt/QML 类型进入 playback core
Win32 HWND 进入 command model
```

**Adapter 必须满足**：

```
1. 被 Kivo 控制
2. 不能控制 Kivo Engine
3. 不能拥有产品状态机
4. 不能决定 UI badge
5. 不能直接污染 core public API
6. 必须可替换
7. 必须可测试
8. 必须可隔离 license 风险
```

---

## 16. Architecture Invariants

后续所有 P0 任务必须守住以下 invariants：

```
1. Commands are input only
2. Events are output only
3. Engine owns state transitions
4. Session owns lifecycle identity
5. Pipeline owns media flow boundary
6. Decoder owns decode boundary
7. Output owns platform output boundary
8. CapabilityModel owns support claims
9. Diagnostics owns traceability
10. Adapter owns third-party integration
11. No third-party type in core public API
12. No platform handle in command / engine API
13. No UI type in playback core
14. No fake support claim
15. No god object
16. No bucket directories
17. No responsibility merging to pass fan-out
18. No direct FFmpeg/D3D11/WASAPI before scheduled ticket
19. No push without Push Authorization
20. No P0 ticket proceeds without allowed files and STOP conditions
```

---

## 17. P0 Route Direction

P0 是播放后端核心路线，不是商业 UI 路线。

**顺序固定**：

```
P0-001 Core Brain
P0-002 Pipeline Contracts
P0-003 Media Probe Model
P0-004 Packet Flow Contracts
P0-005 Decode Contracts
P0-006 Clock And A/V Sync Contracts
P0-007 Video Output Contracts
P0-008 Audio Output Contracts
P0-009 Subtitle Contracts
P0-010 FFmpeg Probe Adapter
P0-011 FFmpeg Demux Adapter
P0-012 FFmpeg Decode Adapter
P0-013 D3D11 Video Output Adapter
P0-014 WASAPI Audio Output Adapter
P0-015 A/V Sync Integration
P0-016 HDR / Color Pipeline
P0-017 Advanced Audio
P0-018 Player Quality Gates
P0-019 Playback Diagnostics / Trace Contracts
P0-020 Format Compatibility Matrix / Sample Corpus Gate
P0-021 Performance / Resource Budget Gates
P0-022 Fault Tolerance / Bad Media Hardening
P0-023 Persistent Playback Core State
P0-024 Release Quality / Soak / Stress Gates
P0-025 Legal / Codec / DRM Boundary Planning
P0-026 Hardware Decode / Zero-Copy Boundary Planning
P0-027 Renderer Quality / Scaling / Frame Pacing Policy
P0-028 Device Capability Runtime Matrix
```

**任何任务不允许提前实现后续任务能力**。如果发现某一层必须依赖后一层，说明边界设计错了，必须 STOP。

---

## 18. P0-002 Direction Preview

P0-002 只做 Pipeline Contracts。

P0-002 应该建立：

```
pipeline/contracts/
  media_pipeline.h
  pipeline_command.h
  pipeline_event.h
  pipeline_result.h
  pipeline_error.h
  pipeline_state.h
  pipeline_generation.h
  pipeline_cancellation.h
  pipeline_flush.h
  pipeline_drain.h
  pipeline_seek.h
```

但具体文件要由 P0-002 任务书再次确认 allowed files。

**P0-002 禁止**：

```
FFmpeg
AVFormatContext
AVPacket
file IO
real demux
real decode
real output
thread implementation
packet queue implementation if not contract-only
```

**P0-002 必须考虑**：

```
open/probe boundary
stream selection boundary
flush/drain boundary
seek boundary
generation boundary
cancellation boundary
EOS boundary
discontinuity boundary
backpressure boundary
error boundary
```

---

## 19. Final Rule

Agent 不能只因为测试能跑就认为完成。每个 P0 任务必须回答：

```
这一步是否让 Kivo 更接近专业播放核心？
有没有提前接后续层？
有没有破坏家谱树？
有没有把第三方/平台类型泄漏进 core？
有没有假宣称能力？
有没有留出后续 adapter 接入点？
有没有测试非法路径？
有没有可诊断性？
有没有防返工？
```

如果答案不清楚，必须 STOP_UNCERTAIN。

**Kivo Playback Core 的方向是**：

```
自研大脑
分层清晰
边界干净
状态确定
错误可解释
能力可验证
接入可替换
输出可诊断
长期可商业化
```

---

**Document Status**: ACTIVE  
**Next Step**: P0-002 Pipeline Contracts  
**Do not proceed to P0-002 without this document approved**
