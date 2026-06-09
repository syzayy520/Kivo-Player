param()
# run-foundation-gates.ps1 - Run foundation gates
# Runs all 4 governance checks and exits 0 only if all pass

$ErrorActionPreference = "Stop"

Write-Output "=========================================="
Write-Output " Foundation Gates - Kivo Video Ultimate"
Write-Output "=========================================="

$exitCode = 0

# Gate 1: Whole Tree Governance
Write-Output "`n--- Gate 1: Whole Tree Governance ---"
& "$PSScriptRoot/check-whole-tree-governance.ps1"
if ($LASTEXITCODE -ne 0) {
    $exitCode = 1
}

# Gate 2: Folder Fan-out
Write-Output "`n--- Gate 2: Folder Fan-out ---"
& "$PSScriptRoot/check-folder-fanout.ps1"
if ($LASTEXITCODE -ne 0) {
    $exitCode = 1
}

# Gate 3: Include Direction
Write-Output "`n--- Gate 3: Include Direction ---"
& "$PSScriptRoot/check-playback-include-direction.ps1"
if ($LASTEXITCODE -ne 0) {
    $exitCode = 1
}

# Gate 4: Source Purity
Write-Output "`n--- Gate 4: Source Purity ---"
& "$PSScriptRoot/check-playback-core-source-purity.ps1"
if ($LASTEXITCODE -ne 0) {
    $exitCode = 1
}

# Final result
Write-Output "`n=========================================="
if ($exitCode -eq 0) {
    Write-Output " RESULT: ALL GATES PASSED"
    Write-Output "=========================================="
} else {
    Write-Output " RESULT: SOME GATES FAILED"
    Write-Output "=========================================="
}

exit $exitCode
