# Whole Tree Family Governance

Kivo 项目采用「整树家谱模式」：

- 文件夹 = 功能族
- 子文件夹 = 子功能族
- 单文件 = 最小职责

## 规则

1. 同一目录不得出现多个职责族
2. 文件数量未超限但明显有多个主题的，必须拆分子族
3. 同层文件靠命名前缀区分多个概念的，算违规
4. 出现 common/helper/utils 泛化桶，算违规
5. 一个目录同时混 UI、engine、pipeline、decoder、output、library 任意两个以上层级，算违规
6. production 和 tests 混放，算违规
7. video、audio、subtitle、hdr、library 多族混在同一目录，算违规
8. 为了不超过文件数，把多个概念合并进一个文件，算违规

## 文件数量目标

- 生产目录：目标 ≤ 7 个业务文件，硬上限 ≤ 9 个
- tests 目录：目标 ≤ 10 个 test files
- scripts 目录：目标 ≤ 10 个脚本

