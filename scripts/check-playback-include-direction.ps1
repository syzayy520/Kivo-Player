param()
# check-playback-include-direction.ps1 - Check include direction governance
# Playback source directories should only include std lib and internal headers, not 3rd-party headers

$ErrorActionPreference = "Stop"

Write-Output "=== Include Direction Check ==="

$exitCode = 0

# Directories to check (playback source directories)
$dirsToCheck = @(
    "src/core",
    "src/pipeline/contracts",
    "src/decoder/contracts", 
    "src/render/contracts",
    "src/audio/contracts"
)

# Forbidden patterns (3rd-party includes)
$forbiddenPatterns = @(
    '^#include <ffmpeg',
    '^#include <libav',
    '^#include <SDL2',
    '^#include <Qt',
    '^#include <d3d11',
    '^#include <dxgi',
    '^#include <wasapi',
    '^#include "third_party/',
    '^#include "external/',
    '^#include "../third_party/',
    '^#include "../external/'
)

foreach ($dir in $dirsToCheck) {
    if (-not (Test-Path $dir)) {
        Write-Output "SKIP: [$dir] not found"
        continue
    }
    
    Write-Output "Scanning: [$dir]"
    
    $files = Get-ChildItem -Path $dir -Recurse -File -Include "*.h","*.cpp" -ErrorAction SilentlyContinue
    
    foreach ($file in $files) {
        $content = Get-Content $file.FullName -ErrorAction SilentlyContinue
        $lineNum = 0
        
        foreach ($line in $content) {
            $lineNum++
            
            # Check for #include lines
            if ($line -match '^#include\s+["<](.+)[">]') {
                $includePath = $matches[1]
                
                # Check if forbidden
                $isForbidden = $false
                foreach ($pattern in $forbiddenPatterns) {
                    if ($line -match $pattern) {
                        $isForbidden = $true
                        break
                    }
                }
                
                if ($isForbidden) {
                    Write-Output "STOP: [$($file.FullName):$lineNum] Forbidden include: $line"
                    $exitCode = 1
                }
            }
        }
    }
}

if ($exitCode -eq 0) {
    Write-Output "PASS: Include direction check passed"
    Write-Output "=== Include Direction Check: PASSED ==="
} else {
    Write-Output "=== Include Direction Check: FAILED ==="
}

exit $exitCode
