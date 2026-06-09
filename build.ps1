# build.ps1 - 一键构建 Kivo Video Ultimate
# 用法:  .\build.ps1          (默认 build)
#        .\build.ps1 clean     (清理构建目录)
#        .\build.ps1 configure (仅配置)
#        .\build.ps1 build     (配置+构建)
#        .\build.ps1 test      (运行测试)

param([string]$Task = "build")

$ErrorActionPreference = "Stop"

# ===== 硬编码路径（已知可用）=====
$VCROOT    = "C:\Program Files\Microsoft Visual Studio\18\Community"
$MSVCVER   = "14.51.36231"
$WINSDKVER = "10.0.26100.0"
$WINSDKBASE= "C:\Program Files (x86)\Windows Kits\10"
$CMAKE     = "C:\Program Files\Microsoft Visual Studio\18\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"

# ===== 设置环境变量（cl.exe 依赖这些）=====
$env:INCLUDE = "$VCROOT\VC\Tools\MSVC\$MSVCVER\include;$WINSDKBASE\Include\$WINSDKVER\ucrt;$WINSDKBASE\Include\$WINSDKVER\um;$WINSDKBASE\Include\$WINSDKVER\shared"
$env:LIB     = "$VCROOT\VC\Tools\MSVC\$MSVCVER\lib\x64;$WINSDKBASE\Lib\$WINSDKVER\ucrt\x64;$WINSDKBASE\Lib\$WINSDKVER\um\x64"
$env:PATH    = "$VCROOT\VC\Tools\MSVC\$MSVCVER\bin\Hostx64\x64;$WINSDKBASE\bin\$WINSDKVER\x64;$env:PATH"

Set-Location $PSScriptRoot

Write-Host "==========================================" -ForegroundColor Cyan
Write-Host " Kivo Video Ultimate - Build Script"        -ForegroundColor Cyan
Write-Host "==========================================" -ForegroundColor Cyan
Write-Host " Project : $PSScriptRoot"                 -ForegroundColor Gray
Write-Host " CMake   : $CMAKE"                        -ForegroundColor Gray
Write-Host " Task    : $Task"                          -ForegroundColor Gray
Write-Host "==========================================" -ForegroundColor Cyan
Write-Host ""

# ===== 执行任务 =====
$ec = 0
switch ($Task) {
    "clean" {
        if (Test-Path "out") { Remove-Item "out" -Recurse -Force; Write-Host "Cleaned." -ForegroundColor Green }
        else { Write-Host "Nothing to clean." -ForegroundColor Gray }
    }
    "configure" {
        & "$CMAKE" --preset windows-msvc-debug
        $ec = $LASTEXITCODE
    }
    "build" {
        if (-not (Test-Path "out\build\windows-msvc-debug\CMakeCache.txt")) {
            Write-Host ">>> Configuring first..." -ForegroundColor Yellow
            & "$CMAKE" --preset windows-msvc-debug
            $ec = $LASTEXITCODE
            if ($ec -ne 0) { exit $ec }
        }
        & "$CMAKE" --build out\build\windows-msvc-debug --config Debug
        $ec = $LASTEXITCODE
    }
    "test" {
        # 使用 ctest 运行测试（和 cmake 同目录）
        $CTEST = "C:\Program Files\Microsoft Visual Studio\18\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\ctest.exe"
        & "$CTEST" --test-dir out\build\windows-msvc-debug --output-on-failure
        $ec = $LASTEXITCODE
    }
    default {
        Write-Host "Unknown task: $Task" -ForegroundColor Red
        Write-Host "Valid: clean, configure, build, test" -ForegroundColor Yellow
        $ec = 1
    }
}

Write-Host ""
Write-Host "Exit code: $ec" -ForegroundColor $(if($ec-eq0){"Green"}else{"Red"})
exit $ec
