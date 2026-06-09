param()
# check-folder-fanout.ps1 - Check folder fan-out governance
# Fan-out rule: max 7 business files per feature family directory
# Root family (e.g., src/core) may have many sub-families - this is OK
# Only flag root family if it contains bucket directories (common/helper/utils/types/stubs/domain)

$ErrorActionPreference = "Stop"

Write-Output "=== Folder Fan-out Check ==="

# Bucket directory names that indicate violation
$bucketNames = @("common", "helper", "utils", "types", "stubs", "domain", "shared", "misc", "base")

# Root family directories that are allowed to have many sub-families
$rootFamilies = @("src", "src/core")

$exitCode = 0

function Test-DirectoryFanout {
    param(
        [string]$DirPath,
        [bool]$IsRootFamily = $false
    )
    
    if (-not (Test-Path $DirPath)) {
        return
    }
    
    $dirName = Split-Path $DirPath -Leaf
    
    # Count business files (not directories, not test files, not generated files)
    $businessFiles = Get-ChildItem -Path $DirPath -File -Filter "*.h" -ErrorAction SilentlyContinue
    $businessFiles += Get-ChildItem -Path $DirPath -File -Filter "*.cpp" -ErrorAction SilentlyContinue
    $businessFiles = $businessFiles | Where-Object { $_.Name -notlike "*_test*" -and $_.Name -notlike "*_tests*" }
    
    $subDirs = Get-ChildItem -Path $DirPath -Directory -ErrorAction SilentlyContinue
    
    if ($IsRootFamily) {
        # Root family: check for bucket directories, not file count
        $bucketDirs = $subDirs | Where-Object { $bucketNames -contains $_.Name }
        if ($bucketDirs.Count -gt 0) {
            Write-Output "STOP: [$DirPath] contains bucket directories: $($bucketDirs.Name -join ', ')"
            $script:exitCode = 1
        } else {
            Write-Output "PASS: [$DirPath] root family - sub-families are clear ($($subDirs.Count) sub-families)"
        }
    } else {
        # Non-root family: check business file count <= 7
        if ($businessFiles.Count -gt 7) {
            Write-Output "STOP: [$DirPath] has $($businessFiles.Count) business files (max 7)"
            $script:exitCode = 1
        } elseif ($businessFiles.Count -gt 0) {
            Write-Output "PASS: [$DirPath] has $($businessFiles.Count) business files (<= 7)"
        }
        
        # Also check subdirectories (recurse)
        foreach ($subDir in $subDirs) {
            Test-DirectoryFanout -DirPath $subDir.FullName -IsRootFamily $false
        }
    }
}

# Check src/ and src/core/
foreach ($rootFamily in $rootFamilies) {
    if (Test-Path $rootFamily) {
        Test-DirectoryFanout -DirPath $rootFamily -IsRootFamily $true
    }
}

if ($exitCode -eq 0) {
    Write-Output "=== Folder Fan-out Check: PASSED ==="
} else {
    Write-Output "=== Folder Fan-out Check: FAILED ==="
}

exit $exitCode
