# KIVO P0 统一自动化执行主协议

**版本**: V1.0  
**日期**: 2026-06-10  
**范围**: P0-002 到 P0-028  
**状态**: ACTIVE  
**继承**: 所有 P0 任务必须继承本协议

---

## 1. 目的

本文档定义了 **Kivo Video 后端播放核心 P0 系列任务（P0-002 到 P0-028）的统一自动化执行协议**。

**核心原则**：
- 每一张 P0 任务都必须按协议步骤执行，不能只按路线图标题自由发挥
- 每一张 P0 任务都必须先规划，再实现
- 每一张 P0 任务都必须通过所有门禁检查才能提交
- 每一张 P0 任务都必须有完整的审计追踪

**协议地位**：
- 本协议是 P0 系列任务的 **最高执行标准**
- 任何 P0 任务不得违反本协议
- 如本协议与任务书冲突，以本协议为准
- 本协议可根据执行经验修订，但修订必须经过用户确认

---

## 2. 适用范围

**适用任务**: P0-002 到 P0-028（后端播放核心路线）

**不适用任务**:
- P1 系列（UI/前端任务）
- P2 系列（工具/脚本任务）
- 非播放核心任务

**任务类型**:
- 合同建立任务（如 P0-002 Pipeline Contracts）
- 模型建立任务（如 P0-003 Media Probe Model）
- Adapter 接入任务（如 P0-010 FFmpeg Probe Adapter）
- 质量门禁任务（如 P0-018 Player Quality Gates）
- 诊断追踪任务（如 P0-019 Playback Diagnostics）

---

## 3. 执行流程（强制）

每一张 P0 任务必须按以下 **21 个步骤** 顺序执行：

### 步骤 1: Initial Environment Header（初始环境头）

**必须输出**：
```
=== Initial Environment Header ===
Timestamp: YYYY-MM-DD HH:MM:SS
Working Directory: <absolute-path>
Git Branch: <branch-name>
Git Status: <clean/dirty>
Last Commit: <commit-hash> <commit-message>
=== Initial Environment Header: DONE ===
```

**目的**：记录任务开始时的环境状态，便于后续审计和重现。

---

### 步骤 2: Enter Target Project Gate（进入目标项目门）

**必须验证**：
1. 确认目标项目目录存在且可访问
2. 确认工作区没有无关变更
3. 确认构建环境可用（CMake、编译器、测试运行器）

**必须输出**：
```
=== Enter Target Project Gate ===
Project Directory: <path>
Build Environment: <available/unavailable>
Test Runner: <available/unavailable>
Result: PASS / STOP_TOOLCHAIN_MISSING
=== Enter Target Project Gate: DONE ===
```

**STOP 条件**：构建环境不可用 → `STOP_TOOLCHAIN_MISSING`

---

### 步骤 3: Project State Header（项目状态头）

**必须输出**：
```
=== Project State Header ===
Project Structure:
  src/          - <summary>
  tests/        - <summary>
  scripts/      - <summary>
  docs/         - <summary>
Build Status: <pass/fail/unknown>
Test Status: <pass/fail/unknown>
=== Project State Header: DONE ===
```

---

### 步骤 4: Branch / Remote Safety Gate（分支/远程安全门）

**必须验证**：
1. 确认在正确的分支上（如 `kivo-playback-pipeline-contracts-p0-002`）
2. 确认没有未提交的变更可能丢失
3. 确认远程未推送（local commit only）

**必须输出**：
```
=== Branch / Remote Safety Gate ===
Current Branch: <branch-name>
Expected Branch: <expected-branch-name>
Uncommitted Changes: <yes/no>
Remote Pushed: <yes/no>
Result: PASS / STOP_UNSAFE_BRANCH
=== Branch / Remote Safety Gate: DONE ===
```

**STOP 条件**：分支不正确或有未提交的关键变更 → `STOP_UNSAFE_BRANCH`

---

### 步骤 5: Inventory Gate（清单门）

**必须列出**：
1. 范围内所有现有源文件
2. 范围内所有现有测试文件
3. 范围内所有现有脚本文件

**必须输出**：
```
=== Inventory Gate ===
Source Files:
  <file-1>
  <file-2>
  ...
Test Files:
  <file-1>
  <file-2>
  ...
Script Files:
  <file-1>
  <file-2>
  ...
=== Inventory Gate: DONE ===
```

---

### 步骤 6: Baseline Verification Gate（基线验证门）

**必须运行**：
1. 所有治理检查（Whole Tree, Folder Fan-out, Include Direction, Source Purity）
2. 构建
3. 测试

**必须输出**：
```
=== Baseline Verification Gate ===
Governance Checks:
  Whole Tree: <pass/fail>
  Folder Fan-out: <pass/fail>
  Include Direction: <pass/fail>
  Source Purity: <pass/fail>
Build: <pass/fail>
Test: <pass/fail>
Baseline Status: GREEN / RED
Result: PASS / STOP_BASELINE_FAILED
=== Baseline Verification Gate: DONE ===
```

**STOP 条件**：基线为 RED（治理检查失败或构建失败或测试失败）→ `STOP_BASELINE_FAILED`

---

### 步骤 7: Ticket Scope Planning Gate（任务范围规划门）

**必须在实现前输出以下 ALL 内容**：

```
=== Ticket Scope Planning Gate ===
Task ID: <task-id>
Goal: <one-sentence-goal>
Non-goals:
  - <explicit-exclusion-1>
  - <explicit-exclusion-2>
Layer touched: <layer-name>
Allowed directories:
  - <dir-1>
  - <dir-2>
Forbidden directories:
  - <dir-1>
  - <dir-2>
Allowed files:
  - <file-1>
  - <file-2>
Forbidden files:
  - <file-1>
  - <file-2>
New contracts:
  - <contract-1>
  - <contract-2>
New tests:
  - <test-1>
  - <test-2>
CMake changes: <describe>
Script changes: <describe>
Boundary risks:
  - <risk-1>
  - <risk-2>
STOP conditions:
  - <stop-1>
  - <stop-2>
Acceptance criteria:
  - <criterion-1>
  - <criterion-2>
=== Ticket Scope Planning Gate: DONE ===
```

**关键规则**：
- 如果 Agent 无法明确 `Allowed files` / `Forbidden files`，必须 `STOP_UNCERTAIN`，不允许猜测
- 用户必须确认范围后，Agent 才能继续

---

### 步骤 8: Architecture Design Gate（架构设计门）

**必须输出**：
1. 架构图（文本或 ASCII）
2. 模块边界定义
3. 依赖方向定义
4. 数据流定义

**必须输出**：
```
=== Architecture Design Gate ===
Architecture Diagram:
  <text-or-ascii-diagram>

Module Boundaries:
  <module-1>: <responsibility>
  <module-2>: <responsibility>

Dependency Direction:
  <module-a> -> <module-b>: <reason>

Data Flow:
  <source> -> <transform> -> <sink>
=== Architecture Design Gate: DONE ===
```

---

### 步骤 9: Dependency Direction Matrix Gate（依赖方向矩阵门）

**必须创建依赖矩阵表**：

```
=== Dependency Direction Matrix Gate ===
| From \ To | core | pipeline | decoder | render | audio | ... |
|----------|------|---------|---------|--------|-------|-----|
| core     |  -   |    X    |    X    |   X    |   X   |     |
| pipeline |  OK  |    -    |    X    |   X    |   X   |     |
| ...      |      |         |         |        |       |     |

Legend:
  OK = Allowed dependency direction
  X  = Forbidden dependency direction
  -  = Self (no dependency)

Circular Dependency Check: <pass/fail>
Result: PASS / STOP_DEPENDENCY_VIOLATION
=== Dependency Direction Matrix Gate: DONE ===
```

**STOP 条件**：存在循环依赖或禁止的依赖方向 → `STOP_DEPENDENCY_VIOLATION`

---

### 步骤 10: Allowed Files Gate（允许文件门）

**必须显式列出**：
1. 所有允许创建/修改的文件
2. 所有禁止触摸的文件

**必须输出**：
```
=== Allowed Files Gate ===
Allowed to Create/Modify:
  <file-1> - <reason>
  <file-2> - <reason>

Forbidden to Touch:
  <file-1> - <reason>
  <file-2> - <reason>

User Confirmation: <required/already-confirmed>
Result: PASS / STOP_UNCERTAIN
=== Allowed Files Gate: DONE ===
```

**STOP 条件**：允许文件列表不明确 → `STOP_UNCERTAIN`

---

### 步骤 11: Whole Tree Family Governance Precheck（整树家谱治理预检）

**必须运行**：
1. `scripts/check-whole-tree-governance.ps1`
2. `scripts/check-folder-fanout.ps1`

**必须输出**：
```
=== Whole Tree Family Governance Precheck ===
Whole Tree Governance: <pass/fail>
Folder Fan-out: <pass/fail>
Result: PASS / STOP_GOVERNANCE_VIOLATION
=== Whole Tree Family Governance Precheck: DONE ===
```

**STOP 条件**：治理检查失败 → `STOP_GOVERNANCE_VIOLATION`

---

### 步骤 12: Implementation（实现）

**规则**：
1. 小步实现，增量提交（如需要）
2. 严格遵守整树家谱模式
3. 每完成一个子功能，立即运行治理检查

**必须输出**：
```
=== Implementation ===
Sub-task 1: <description> - DONE
Sub-task 2: <description> - DONE
...
=== Implementation: DONE ===
```

---

### 步骤 13: Automated Gates（自动化门）

**必须运行**：
1. 所有治理检查
2. 构建
3. 测试

**必须输出**：
```
=== Automated Gates ===
Governance Checks: <pass/fail>
Build: <pass/fail>
Test: <pass/fail>
Result: PASS / STOP_BUILD_FAILED / STOP_TEST_FAILED
=== Automated Gates: DONE ===
```

**STOP 条件**：
- 构建失败 → `STOP_BUILD_FAILED`
- 测试失败 → `STOP_TEST_FAILED`

---

### 步骤 14: Self Review（自审）

**必须审查**：
1. 所有变更的 diff
2. 是否有 unintended changes
3. 是否符合整树家谱模式
4. 是否有禁止的桶目录
5. 是否有职责合并

**必须输出**：
```
=== Self Review ===
Files Changed: <count>
Lines Added: <count>
Lines Deleted: <count>
Unintended Changes: <yes/no>
Whole Tree Compliance: <yes/no>
Bucket Directories: <yes/no>
Responsibility Merging: <yes/no>
Result: PASS / NEEDS_REPAIR
=== Self Review: DONE ===
```

**修复循环**：如发现问题，必须修复后重新运行 Automated Gates，直到全部 PASS。

---

### 步骤 15: Repair Loop（修复循环）

**触发条件**：Self Review 或 Automated Gates 失败。

**必须执行**：
1. 识别失败原因
2. 制定修复计划
3. 执行修复
4. 重新运行失败的门
5. 如仍失败，重复修复循环

**必须输出**：
```
=== Repair Loop ===
Repair Iteration 1:
  Failure: <description>
  Fix: <description>
  Result: <pass/fail>
Repair Iteration 2:
  ...
Result: PASS / STOP_UNCERTAIN
=== Repair Loop: DONE ===
```

**STOP 条件**：修复 3 次后仍失败 → `STOP_UNCERTAIN`

---

### 步骤 16: Polish Loop（打磨循环）

**即使一次 build/test 通过，也必须执行 Polish Loop**。

**Polish Pass 1 — Architecture consistency（架构一致性）**：
- 检查架构图与实现是否一致
- 检查模块边界是否清晰
- 检查依赖方向是否正确

**Polish Pass 2 — Boundary tightening（边界收紧）**：
- 检查 public API 是否最小化
- 检查 internal API 是否合理
- 检查是否有泄漏的类型

**Polish Pass 3 — Test strengthening（测试加强）**：
- 检查测试覆盖率
- 检查边界条件测试
- 检查错误处理测试

**Polish Pass 4 — Whole tree family review（整树家谱审查）**：
- 运行 `scripts/check-whole-tree-governance.ps1`
- 运行 `scripts/check-folder-fanout.ps1`
- 确认无桶目录、无职责合并

**Polish Pass 5 — CMake / script robustness（CMake/脚本健壮性）**：
- 检查 CMakeLists.txt 完整性
- 检查脚本是否正确处理边界情况
- 检查脚本输出是否清晰

**Polish Pass 6 — Report evidence dry run（报告证据预演）**：
- 预演最终报告的所有检查
- 确认所有证据可用
- 确认分类明确

**必须输出**：
```
=== Polish Loop ===
Pass 1 - Architecture consistency: PASS
Pass 2 - Boundary tightening: PASS
Pass 3 - Test strengthening: PASS
Pass 4 - Whole tree family review: PASS
Pass 5 - CMake/script robustness: PASS
Pass 6 - Report evidence dry run: PASS
Result: PASS / NEEDS_MORE_POLISH
=== Polish Loop: DONE ===
```

**关键规则**：
- Polish 不能扩大范围
- Polish 不能顺手接真实后端
- 如 Polish 发现新问题，必须修复后重新 Polish

---

### 步骤 17: Whole Tree Family Governance Postcheck（整树家谱治理后检）

**必须运行**（与步骤 11 相同）：
1. `scripts/check-whole-tree-governance.ps1`
2. `scripts/check-folder-fanout.ps1`
3. `scripts/check-playback-include-direction.ps1`
4. `scripts/check-playback-core-source-purity.ps1`

**必须输出**：
```
=== Whole Tree Family Governance Postcheck ===
Whole Tree Governance: PASS
Folder Fan-out: PASS
Include Direction: PASS
Source Purity: PASS
Result: PASS / STOP_GOVERNANCE_VIOLATION
=== Whole Tree Family Governance Postcheck: DONE ===
```

**STOP 条件**：治理检查失败 → `STOP_GOVERNANCE_VIOLATION`

---

### 步骤 18: Final Gates（最终门）

**必须验证**：
1. 所有变更文件都在 Allowed files 列表内
2. 没有禁止文件被修改
3. 构建通过
4. 测试通过
5. 治理检查通过

**必须输出**：
```
=== Final Gates ===
Allowed Files Check: PASS
Forbidden Files Check: PASS
Build: PASS
Test: PASS
Governance: PASS
Result: PASS / STOP_ALLOWLIST_VIOLATION / STOP_BUILD_FAILED / STOP_TEST_FAILED
=== Final Gates: DONE ===
```

**STOP 条件**：
- Allowlist 违规 → `STOP_ALLOWLIST_VIOLATION`
- 构建失败 → `STOP_BUILD_FAILED`
- 测试失败 → `STOP_TEST_FAILED`

---

### 步骤 19: Commit（提交）

**规则**：
1. 只能 local commit，禁止 push
2. Commit message 必须清晰描述变更
3. 必须使用 `git add <specific-files>`，禁止 `git add .`
4. Commit 后必须输出 `git show --stat`

**必须输出**：
```
=== Commit ===
Commit Message: <message>
Files Committed:
  <file-1>
  <file-2>
Commit Hash: <hash>
Result: DONE
=== Commit: DONE ===
```

---

### 步骤 20: Post-commit Verification（提交后验证）

**必须运行**：
1. `git status --short --branch`
2. `git log --oneline -3`
3. `git show --stat --oneline --name-status -1`
4. 构建
5. 测试
6. 治理检查

**必须输出**：
```
=== Post-commit Verification ===
Git Status: <clean/dirty>
Last 3 Commits:
  <hash-1> <message-1>
  <hash-2> <message-2>
  <hash-3> <message-3>
Build: PASS
Test: PASS
Governance: PASS
Result: PASS / STOP_POST_COMMIT_FAILED
=== Post-commit Verification: DONE ===
```

**STOP 条件**：提交后验证失败 → `STOP_POST_COMMIT_FAILED`

---

### 步骤 21: Final Report（最终报告）

**必须输出**（完整报告格式）：

```
=== Final Report ===

## 1. Git Status (After Commit)

<branch-name>
<status>

## 2. Commit Chain Evidence

**git log --oneline -5**:
<commits>

**git show --stat --oneline --name-status -1**:
<commit-details>

## 3. Touched Folders
<folders>

## 4. Folder Fan-out Result
<result>

## 5. Subfamily Split Check
<result>

## 6. Single Responsibility Check
<result>

## 7. Include Direction Check
<result>

## 8. Source Purity Check
<result>

## 9. CMake Source Completeness
<result>

## 10. Build/Test
<result>

## 11. Governance Checks
<result>

## 12. Final Classification

**Final Classification**: PASS_COMMITTED / STOP_*

**Push status**: not pushed by design

**Branch**: <branch-name>

**HEAD**: <commit-hash>

**Commit**: <commit-message>

**Working tree**: <clean/dirty>

===

=== Final Report: DONE ===
```

---

## 4. 整树家谱治理规则

### 4.1 家谱模式（Hard Gate）

**规则**：
- 文件夹 = 功能族
- 子文件夹 = 子功能族
- 单文件 = 最小职责

**禁止**：
- 为了省事把多个职责塞进一个文件
- helper/utils/manager/service/glue/facade 桶文件
- 禁止从头重做已完成模块
- 禁止大重构

### 4.2 扇出限制（Fan-out Limit）

**规则**：
- 同一功能族目录下的业务文件数量 ≤ 7
- `src/core` 是核心根族，允许包含子功能族目录
- 对 `src/core` 这类 root family，应输出 WARNING / REVIEW，而不是强迫合并子功能族
- 只有出现 common/helper/utils/types/stubs/domain 这种模糊桶，才应 STOP

### 4.3 包含方向（Include Direction）

**规则**：
- `src/core` 只能包含 std lib 和 core internal
- `src/pipeline/contracts` 只能包含 std lib 和 core/public
- 禁止包含第三方库头文件
- 禁止包含平台特定头文件

### 4.4 源码纯净（Source Purity）

**规则**：
- `src/core` 不能包含第三方代码
- 生产源码注释也不能出现 forbidden tokens（FFmpeg, D3D11, WASAPI, libmpv, Qt 等）
- 如需说明禁区，写在 `docs/README`，不在生产源码中

---

## 5. 分类类型

每一张 P0 任务的最终分类必须使用以下类型之一：

### 5.1 PASS 类型

**PASS_COMMITTED**：任务完成，已提交，工作区干净。

### 5.2 STOP 类型

**STOP_BASELINE_FAILED**：基线验证失败（治理检查失败或构建失败或测试失败）。

**STOP_TOOLCHAIN_MISSING**：构建环境不可用（CMake、编译器、测试运行器缺失）。

**STOP_BOUNDARY_VIOLATION**：边界违规（模块边界不清晰、依赖方向错误）。

**STOP_GOVERNANCE_VIOLATION**：治理检查失败（整树家谱、扇出、包含方向、源码纯净）。

**STOP_BUILD_FAILED**：构建失败。

**STOP_TEST_FAILED**：测试失败。

**STOP_ALLOWLIST_VIOLATION**：Allowlist 违规（修改了禁止文件）。

**STOP_UNSAFE_BRANCH**：分支不安全（分支不正确或有未提交的关键变更）。

**STOP_UNCERTAIN**：信息不足，Agent 无法明确 allowed files / forbidden files，或修复 3 次后仍失败。

---

## 6. STOP 条件详解

### 6.1 何时 STOP

**必须 STOP 的情况**：
1. 构建环境不可用
2. 基线验证失败
3. 分支不安全
4. Allowed files / Forbidden files 不明确
5. 治理检查失败
6. 构建失败
7. 测试失败
8. Allowlist 违规
9. 修复 3 次后仍失败
10. 用户明确要求 STOP

### 6.2 如何 STOP

**STOP 时必须输出**：
```
=== STOP ===
STOP Reason: <reason-code>
STOP Description: <description>
STOP Evidence:
  <evidence-1>
  <evidence-2>
Next Action: <wait-for-user/need-more-info>
=== STOP: DONE ===
```

**STOP 后**：
- 必须等待用户指令
- 禁止自行继续
- 禁止自行猜测

---

## 7. 附录 A：任务范围规划模板

（每张 P0 任务开始前必须填写并输出此模板）

```text
=== Ticket Scope Planning Gate ===
Task ID: <task-id>
Goal: <one-sentence-goal>
Non-goals:
  - <explicit-exclusion-1>
  - <explicit-exclusion-2>
Layer touched: <layer-name>
Allowed directories:
  - <dir-1>
  - <dir-2>
Forbidden directories:
  - <dir-1>
  - <dir-2>
Allowed files:
  - <file-1>
  - <file-2>
Forbidden files:
  - <file-1>
  - <file-2>
New contracts:
  - <contract-1>
  - <contract-2>
New tests:
  - <test-1>
  - <test-2>
CMake changes: <describe>
Script changes: <describe>
Boundary risks:
  - <risk-1>
  - <risk-2>
STOP conditions:
  - <stop-1>
  - <stop-2>
Acceptance criteria:
  - <criterion-1>
  - <criterion-2>
=== Ticket Scope Planning Gate: DONE ===
```

---

## 8. 附录 B：最终报告模板

（每张 P0 任务结束时必须输出此报告）

```text
=== Final Report ===

## 1. Git Status (After Commit)

<branch-name>
<git-status-output>

## 2. Commit Chain Evidence

**git log --oneline -5**:
<git-log-output>

**git show --stat --oneline --name-status -1**:
<git-show-output>

## 3. Touched Folders
<folders-list>

## 4. Folder Fan-out Result
<fanout-check-result>

## 5. Subfamily Split Check
<subfamily-check-result>

## 6. Single Responsibility Check
<responsibility-check-result>

## 7. Include Direction Check
<include-check-result>

## 8. Source Purity Check
<source-purity-result>

## 9. CMake Source Completeness
<cmake-check-result>

## 10. Build/Test
<build-test-result>

## 11. Governance Checks
<governance-check-result>

## 12. Final Classification

**Final Classification**: <PASS_COMMITTED / STOP_*>

**Push status**: not pushed by design

**Branch**: <branch-name>

**HEAD**: <commit-hash>

**Commit**: <commit-message>

**Working tree**: <clean/dirty>

===

=== Final Report: DONE ===
```

---

## 9. 附录 C：禁止偏航规则

### 9.1 禁止提前接入后续层

**规则**：
- P0-002 到 P0-009：只做 contracts，不接真实后端
- P0-010 以后：才允许真实 FFmpeg probe adapter
- P0-013 以后：才允许 D3D11 video output adapter
- P0-014 以后：才允许 WASAPI audio output adapter

**违反后果**：`STOP_BOUNDARY_VIOLATION`

### 9.2 禁止使用桶目录

**禁止的桶目录名称**：
- common
- helper
- utils
- types
- stubs
- domain
- misc
- shared
- manager（当 manager 变成桶时）
- service（当 service 变成桶时）

**违反后果**：`STOP_GOVERNANCE_VIOLATION`

### 9.3 禁止职责合并

**禁止的行为**：
- 为了通过 fan-out 合并职责族
- 把多个概念塞进一个文件
- 用 manager / engine / player / service 变成 god object

**违反后果**：`STOP_GOVERNANCE_VIOLATION`

### 9.4 禁止假能力声明

**禁止的行为**：
- 检测到 HDR metadata ≠ 支持 HDR 输出
- 检测到 Dolby Vision ≠ 支持 Dolby Vision
- 能 fallback 到 HDR10 ≠ 完整 Dolby Vision
- 检测到 Atmos 音轨 ≠ 能输出 Atmos
- 设备支持某能力 ≠ Kivo 已验证该能力
- 第三方库可解析 ≠ Kivo 商业可宣称

**违反后果**：`STOP_BOUNDARY_VIOLATION`

---

## 10. 附录 D：修订历史

| 版本 | 日期 | 修订内容 | 修订人 |
|------|------|----------|--------|
| V1.0 | 2026-06-10 | 初始版本 | Agent |

---

**文档结束**


