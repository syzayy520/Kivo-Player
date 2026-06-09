param()
# check-playback-core-source-purity.ps1 - Check source purity governance
# Playback source directories should not contain 3rd-party code or forbidden tokens (even in comments)

$ErrorActionPreference = "Stop"

Write-Output "=== Source Purity Check ==="

$exitCode = 0

# Directories to check (playback source directories)
$dirsToCheck = @(
    "src/core",
    "src/pipeline/contracts",
    "src/decoder/contracts", 
    "src/render/contracts",
    "src/audio/contracts"
)

# Forbidden tokens (even in comments, for production src)
$forbiddenTokens = @(
    'ffmpeg',
    'libav',
    'SDL2',
    'Qt6',
    'Qt5',
    'd3d11',
    'dxgi',
    'wasapi',
    'libmpv',
    'third_party',
    'external'
)

# Docs directory (allowed to have forbidden tokens for documentation)
$docsDir = "docs"

foreach ($dir in $dirsToCheck) {
    if (-not (Test-Path $dir)) {
        Write-Output "SKIP: [$dir] not found"
        continue
    }
    
    Write-Output "Scanning: [$dir]"
    
    $files = Get-ChildItem -Path $dir -Recurse -File -Include "*.h","*.cpp" -ErrorAction SilentlyContinue
    
    foreach ($file in $files) {
        $content = Get-Content $file.FullName -Raw -ErrorAction SilentlyContinue
        
        if ($null -eq $content) {
            continue
        }
        
        # Check for forbidden tokens (in all content, including comments)
        foreach ($token in $forbiddenTokens) {
            if ($content -match $token) {
                Write-Output "STOP: [$($file.FullName)] contains forbidden token: $token"
                $exitCode = 1
                break
            }
        }
    }
}

if ($exitCode -eq 0) {
    Write-Output "PASS: Source purity check passed (no forbidden tokens in playback src)"
    Write-Output "=== Source Purity Check: PASSED ==="
} else {
    Write-Output "=== Source Purity Check: FAILED ==="
}

exit $exitCode
