# check-file-size.ps1 - Check file sizes in docs/ and src/
# Usage: powershell -ExecutionPolicy Bypass -File scripts/check-file-size.ps1
# Thresholds: docs/*.md <= 1000 lines (governance docs can be larger), src/**/*.h/*.cpp <= 500 lines

$ErrorActionPreference = "Stop"

Write-Output "=== File Size Check ==="

$highRiskFiles = @()
$warnings = @()

# Check docs/ - governance docs can be up to 1000 lines
$docsDir = Join-Path $PSScriptRoot "..\docs"
$docsFiles = Get-ChildItem -Path $docsDir -Filter "*.md" -Recurse
foreach ($file in $docsFiles) {
    $lineCount = (Get-Content $file.FullName).Count
    if ($lineCount -gt 1000) {
        $highRiskFiles += "$($file.Name): $lineCount lines (HIGH RISK: > 1000)"
    } elseif ($lineCount -gt 800) {
        $warnings += "$($file.Name): $lineCount lines (WARNING: > 800)"
    }
}

# Check src/ - source files must be <= 500 lines
$srcDir = Join-Path $PSScriptRoot "..\src"
$srcFiles = Get-ChildItem -Path $srcDir -Filter "*.h" -Recurse
$srcFiles += Get-ChildItem -Path $srcDir -Filter "*.cpp" -Recurse
foreach ($file in $srcFiles) {
    $lineCount = (Get-Content $file.FullName).Count
    if ($lineCount -gt 500) {
        $highRiskFiles += "$($file.Name): $lineCount lines (HIGH RISK: > 500)"
    } elseif ($lineCount -gt 400) {
        $warnings += "$($file.Name): $lineCount lines (WARNING: > 400)"
    }
}

# Output results
if ($highRiskFiles.Count -gt 0) {
    Write-Output "HIGH RISK files (> limit):"
    foreach ($f in $highRiskFiles) {
        Write-Output "  - $f"
    }
}

if ($warnings.Count -gt 0) {
    Write-Output "WARNING files (near limit):"
    foreach ($w in $warnings) {
        Write-Output "  - $w"
    }
}

if ($highRiskFiles.Count -eq 0) {
    Write-Output "PASS: No high-risk files found"
    Write-Output "=== File Size Check: PASSED ==="
    exit 0
} else {
    Write-Output "FAIL: $($highRiskFiles.Count) high-risk files found"
    Write-Output "=== File Size Check: FAILED ==="
    exit 1
}
