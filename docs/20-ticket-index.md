# Kivo Video Ultimate - P0 Ticket Index

本文档列出了 Kivo Video Ultimate 项目的所有 P0 级别 ticket。

## P0 路线图概览

P0 路线是**后端播放核心路线**，不是商业 UI 路线。本仓库只做自研播放核心地基，不接真实 FFmpeg/D3D11/WASAPI/libmpv/Qt/UI。

**核心原则**:
- 自研大脑，不是 mpv shell
- 分层清晰，边界干净
- 状态确定，错误可解释
- 能力可验证，接入可替换
- 输出可诊断，长期可商业化

**路线源文件**: `docs/playback-core/modern-media-engine-roadmap-and-p0-checklist.md`

---

## Ticket 列表

| Ticket | 名称 | 状态 | 说明 |
|--------|------|------|------|
| [P0-001](#p0-001) | Playback Core Foundation (Core Brain) | ✅ PASS_COMMITTED | 播放核心地基：Command, Event, Error, StateMachine, Engine |
| [P0-001B](#p0-001b) | Playback Core North Star | ✅ PASS_COMMITTED | 播放核心北极星方向文档 |
| [P0-Master-Protocol](#p0-master-protocol) | P0 Autonomous Execution Master Protocol | ✅ PASS_COMMITTED | P0-002 到 P0-028 统一自动化执行协议 |
| [P0-002](#p0-002) | Pipeline Contracts | ✅ PASS_COMMITTED | Pipeline 合同层 |
| [P0-003](#p0-003) | Media Probe Model | ✅ PASS_COMMITTED | Media Probe 模型 |
| [P0-004](#p0-004) | Packet Flow Contracts | ✅ PASS_COMMITTED | Packet Flow 合同 |
| [P0-005](#p0-005) | Decode Contracts | ✅ PASS_COMMITTED | Decode 合同 |
| [P0-006](#p0-006) | Timeline / Timestamp / Segment Contracts | ⏳ PENDING | Timeline 合同：Timebase, MediaTimestamp, TimelineSegment, SeekTarget |
| [P0-007](#p0-007) | Clock Domain / A-V Sync Contracts | ⏳ PENDING | Clock 合同：ClockDomain, MasterClock, DriftObservation |
| [P0-008](#p0-008) | Presentation Decision / Queue Policy / Scheduler Contracts | ⏳ PENDING | Presentation 决策层 |
| [P0-009](#p0-009) | Memory / Surface / Opaque Handle / Pool Lifetime Contracts | ⏳ PENDING | 零拷贝内存/表面生命周期 |
| [P0-010](#p0-010) | Demuxer / Media Source Contracts | ⏳ PENDING | Demuxer 合同 |
| [P0-011](#p0-011) | Media Format / Color / HDR Metadata Contracts | ⏳ PENDING | 媒体格式/色彩/HDR |
| [P0-012](#p0-012) | Capability / Negotiation Contracts | ⏳ PENDING | 能力和协商 |
| [P0-013](#p0-013) | Device / Recovery Contracts | ⏳ PENDING | 设备丢失恢复 |
| [P0-014](#p0-014) | Video Renderer Contracts | ⏳ PENDING | 视频渲染器 |
| [P0-015](#p0-015) | Audio Endpoint / Audio Renderer / Audio Clock / Passthrough Contracts | ⏳ PENDING | 音频端点/渲染/时钟/直通 |
| [P0-016](#p0-016) | Subtitle / Overlay Contracts | ⏳ PENDING | 字幕覆盖 |
| [P0-017](#p0-017) | Execution / Concurrency / Task Contracts | ⏳ PENDING | 执行/并发/任务 |
| [P0-018](#p0-018) | Diagnostics / Telemetry / Trace Contracts | ⏳ PENDING | 诊断/遥测/追踪 |
| [P0-019](#p0-019) | Media Case / Stress Test Scenario Contracts | ⏳ PENDING | 媒体用例/压力测试 |
| [P1-020](#p1-020) | FFmpeg Probe + Demux Adapter | ⏳ P1 | P1 最小可播放阶段开始 |
| [P1-021](#p1-021) | Software Decode Adapter | ⏳ P1 | 软件解码 |
| [P1-022](#p1-022) | Timeline + Clock Runtime | ⏳ P1 | 时间线+时钟运行时 |
| [P1-023](#p1-023) | Presentation Decision Runtime | ⏳ P1 | 呈现决策运行时 |
| [P1-024](#p1-024) | WASAPI Shared PCM Output | ⏳ P1 | WASAPI 共享 PCM |
| [P1-025](#p1-025) | D3D11 Video Presentation | ⏳ P1 | D3D11 视频呈现 |
| [P1-026](#p1-026) | Local File Playback MVP | ⏳ P1 | 本地播放 MVP |
| [P1-027](#p1-027) | Seek / Pause / Resume / EOS Integration | ⏳ P1 | 寻道/暂停/恢复/EOS |
| [P1-028](#p1-028) | Diagnostics Overlay / Log Snapshot | ⏳ P1 | 诊断覆盖/日志快照 |

---

## 状态说明

| 状态 | 说明 |
|------|------|
| ✅ PASS_COMMITTED | 已通过验收，已提交本地 commit |
| 🔄 IN_PROGRESS | 进行中 |
| ⏳ PENDING | 待开始（等待前置任务完成） |
| ❌ STOP | 已停止（遇到问题） |
| ⏳ P1 | P1 阶段（P0 完成后进入） |

---

## 说明

P0-006 到 P0-019 的详细路线和每张 ticket 的范围、合同清单、禁止项，参见路线源文件：
**`docs/playback-core/modern-media-engine-roadmap-and-p0-checklist.md`**

P1-020 到 P1-028 的最小可播放阶段路线也在此文件中定义。

---

**文档状态**: ACTIVE  
**最后更新**: 2026-06-10  
**维护者**: Kivo Team
