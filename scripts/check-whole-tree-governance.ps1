param()
# check-whole-tree-governance.ps1 - Check whole tree governance
# Checks: no bucket files, file size <= 500 lines, no platform-specific code in src/core

$ErrorActionPreference = "Stop"

Write-Output "=== Whole Tree Governance Check ==="

$exitCode = 0

# Get all files, excluding build and .git directories
function Get-SourceFiles {
    param($Path)
    
    Get-ChildItem -Path $Path -File -Recurse -Include "*.h","*.cpp","*.c" -ErrorAction SilentlyContinue | 
    Where-Object { $_.FullName -notlike "*\out\*" -and $_.FullName -notlike "*\.git\*" -and $_.FullName -notlike "*\build\*" }
}

# 1. Check for bucket directories (common/helper/utils/manager/service/glue/facade)
# Exclude build and .git directories
Write-Output "--- Check 1: Bucket directory check ---"
$bucketNames = @("common", "helper", "utils", "types", "stubs", "domain", "shared", "misc", "base")

$foundBuckets = @()
foreach ($bucket in $bucketNames) {
    $bucketDirs = Get-ChildItem -Path . -Directory -Recurse -ErrorAction SilentlyContinue | 
                  Where-Object { $_.Name -eq $bucket -and $_.FullName -notlike "*\out\*" -and $_.FullName -notlike "*\.git\*" -and $_.FullName -notlike "*\build\*" }
    
    foreach ($bucketDir in $bucketDirs) {
        $foundBuckets += $bucketDir.FullName
        Write-Output "STOP: Found bucket directory: $($bucketDir.FullName)"
        $exitCode = 1
    }
}

if ($foundBuckets.Count -eq 0) {
    Write-Output "PASS: No bucket directories found"
}

# 2. Check file size (<= 500 lines)
Write-Output "--- Check 2: File size check (<= 500 lines) ---"
$largeFiles = @()
$files = Get-SourceFiles -Path .

foreach ($file in $files) {
    $lineCount = (Get-Content $file.FullName -ErrorAction SilentlyContinue | Measure-Object -Line).Lines
    if ($lineCount -gt 500) {
        $largeFiles += "$($file.FullName) ($lineCount lines)"
        Write-Output "STOP: File too large: $($file.FullName) ($lineCount lines)"
        $exitCode = 1
    }
}

if ($largeFiles.Count -eq 0) {
    Write-Output "PASS: All files <= 500 lines"
}

# 3. Check no platform-specific code in src/core
Write-Output "--- Check 3: Platform-specific code check in src/core ---"
if (Test-Path "src/core") {
    $platformPatterns = @("_WIN32", "__linux__", "__APPLE__", "_MSC_VER", "__GNUC__")
    $coreFiles = Get-ChildItem -Path "src/core" -File -Recurse -Include "*.h","*.cpp" -ErrorAction SilentlyContinue
    
    foreach ($file in $coreFiles) {
        $content = Get-Content $file.FullName -ErrorAction SilentlyContinue
        $lineNum = 0
        
        foreach ($line in $content) {
            $lineNum++
            
            # Skip comment lines
            if ($line -match '^\s*//') {
                continue
            }
            
            foreach ($pattern in $platformPatterns) {
                if ($line -match $pattern) {
                    Write-Output "STOP: [$($file.FullName):$lineNum] Platform-specific code: $pattern"
                    Write-Output "  Line: $line"
                    $exitCode = 1
                }
            }
        }
    }
    
    if ($exitCode -eq 0) {
        Write-Output "PASS: No platform-specific code in src/core"
    }
} else {
    Write-Output "SKIP: src/core not found"
}

if ($exitCode -eq 0) {
    Write-Output "=== Whole Tree Governance Check: PASSED ==="
} else {
    Write-Output "=== Whole Tree Governance Check: FAILED ==="
}

exit $exitCode
