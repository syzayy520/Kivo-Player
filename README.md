# Kivo Video Ultimate

Kivo 最强播放器自研核心地基项目。

## P0 路线

P0-001 到 P0-028 是后端播放核心路线，本仓库只做自研播放核心地基，不接真实 FFmpeg/D3D11/WASAPI/libmpv/Qt/UI。

## North Star

**Kivo Playback Core North Star** 定义了播放核心的长期方向、架构总纲、核心原则、禁止偏航规则。

- 文档: `docs/24-playback-core-north-star.md`
- 状态: ACTIVE
- 范围: P0-002 到 P0-028 必须继承此方向

## P0 统一执行协议

**KIVO P0 统一自动化执行主协议** 定义了 P0-002 到 P0-028 每张任务必须遵循的执行流程、治理规则、STOP 条件和报告格式。

- 文档: `docs/23-p0-autonomous-execution-master-protocol.md`
- 状态: ACTIVE
- 范围: P0-002 到 P0-028 必须继承此协议

## 当前状态

| Ticket | 状态 | 说明 |
|--------|------|------|
| P0-001 | ✅ 已完成 | Playback Core Foundation (Core Brain) |
| P0-001B | ✅ 已完成 | North Star (方向文档) |
| P0-Master-Protocol | 🔄 进行中 | P0 统一自动化执行主协议 |
| P0-002 | ⏳ 待开始 | Pipeline Contracts (待 P0-Master-Protocol 完成) |

## 目录结构

- \src/core\ — 播放核心合同族
- \src/pipeline/contracts\ — Pipeline 抽象合同
- \src/decoder/contracts\ — Decoder 抽象合同
- \src/render/contracts\ — Video Output 抽象合同
- \src/audio/contracts\ — Audio Output 抽象合同
- \	ests/unit\ — 单元测试
- \scripts\ — 门禁脚本
- \docs\ — 设计文档

## 构建

**推荐方式**：使用 \uild.ps1\ 一键构建（自动设置 VS 环境）：

\\\powershell
.\build.ps1          # 配置 + 构建
.\build.ps1 test     # 运行测试
.\build.ps1 clean    # 清理构建目录
\\\

**手动方式**（需要先设置 VS 环境变量）：

\\\powershell
# 设置 VS 2022 环境变量（示例路径，需按实际安装位置调整）
\ = \"C:/Program Files/Microsoft Visual Studio/18/Community/VC/Tools/MSVC/14.51.36231/include;...\"
\     = \"C:/Program Files/Microsoft Visual Studio/18/Community/VC/Tools/MSVC/14.51.36231/lib/x64;...\"
\C:\Users\Administrator\.workbuddy\binaries\node\versions\22.22.2;C:\Users\Administrator\.workbuddy\binaries\python\versions\3.13.12;C:\Users\Administrator\.workbuddy\binaries\node\cli-connector-packages;C:\nvm4w\nvm\nodejs;C:\Windows\System32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0;C:\Windows\System32\OpenSSH;F:\Files\实用工具\图片处理\ImageMagick-7.1.2-Q16-HDRI;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files\dotnet\;C:\Program Files\nodejs\;C:\Program Files\Git\cmd;C:\Windows\System32\OpenSSH\;C:\Program Files\GitHub CLI\;C:\Program Files (x86)\NetSarang\Xftp 8\;C:\Users\Administrator\.cargo\bin;C:\Users\Administrator\AppData\Local\Programs\Python\Python310\Scripts\;C:\Users\Administrator\AppData\Local\Programs\Python\Python310\;C:\Users\Administrator\AppData\Local\Microsoft\WindowsApps;C:\Users\Administrator\AppData\Local\Python\bin;C:\Users\Administrator\.dotnet\tools;C:\Users\Administrator\AppData\Roaming\npm;C:\Users\Administrator\AppData\Local\Microsoft\WinGet\Links;C:\Users\Administrator\AppData\Local\Programs\Ollama;C:\Users\Administrator\.local\bin;F:\File\Microsoft VS Code\bin;C:\Users\Administrator\AppData\Local\Programs\Microsoft VS Code Insiders\bin;F:\Files\实用工具\AI工具\CodeBuddy CN\bin    = \"C:/Program Files/Microsoft Visual Studio/18/Community/VC/Tools/MSVC/14.51.36231/bin/Hostx64/x64;...\"

# 然后构建
cmake --preset windows-msvc-debug
cmake --build out/build/windows-msvc-debug --config Debug
ctest --test-dir out/build/windows-msvc-debug --output-on-failure
\\\

## 许可

TODO