# Kivo Video Ultimate

Kivo 最强播放器自研核心地基项目。

## P0 路线

P0-001 到 P0-028 是后端播放核心路线，本仓库只做自研播放核心地基，不接真实 FFmpeg/D3D11/WASAPI/libmpv/Qt/UI。

## 当前状态

P0-001: Playback Core Foundation — 进行中

## 目录结构

- `src/core` — 播放核心合同族
- `src/pipeline/contracts` — Pipeline 抽象合同
- `src/decoder/contracts` — Decoder 抽象合同
- `src/render/contracts` — Video Output 抽象合同
- `src/audio/contracts` — Audio Output 抽象合同
- `tests/unit` — 单元测试
- `scripts` — 门禁脚本
- `docs` — 设计文档

## 构建

```powershell
cmake --preset windows-msvc-debug
cmake --build --preset windows-msvc-debug
ctest --preset windows-msvc-debug --output-on-failure
```

## 许可

TODO
