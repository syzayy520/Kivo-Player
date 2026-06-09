param()
# check-include-direction.ps1 - Check include direction governance
# src/core should only include std lib and core internal headers, not 3rd-party headers

$ErrorActionPreference = "Stop"

Write-Output "=== Include Direction Check ==="

$exitCode = 0

# Directories to check
$dirsToCheck = @("src/core")

# Allowed include patterns for src/core
$allowedPatterns = @(
    '^#include <[a-z]',  # std lib includes like <iostream>, <vector>, etc.
    '^#include "core/',  # core internal includes
    '^#include "playback_',  # core internal includes (alternative pattern)
    '^#include "error/"',
    '^#include "state/"',
    '^#include "command/"',
    '^#include "engine/"',
    '^#include "event/"',
    '^#include "session/"',
    '^#include "clock/"',
    '^#include "timeline/"',
    '^#include "capability/"',
    '^#include "id/"',
    '^#include "time/"',
    '^#include "result/"'
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
        continue
    }
    
    $files = Get-ChildItem -Path $dir -Recurse -File -Include "*.h","*.cpp" -ErrorAction SilentlyContinue
    
    foreach ($file in $files) {
        $content = Get-Content $file.FullName -ErrorAction SilentlyContinue
        $lineNum = 0
        
        foreach ($line in $content) {
            $lineNum++
            
            # Skip comments and empty lines
            if ($line -match '^\s*//' -or $line -match '^\s*$') {
                continue
            }
            
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
