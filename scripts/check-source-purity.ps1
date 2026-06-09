param()
# check-source-purity.ps1 - Check source purity governance
# src/core should not contain 3rd-party code
# Comments mentioning 3rd-party tools are OK (e.g., "Does NOT depend on FFmpeg")

$ErrorActionPreference = "Stop"

Write-Output "=== Source Purity Check ==="

$exitCode = 0

# Directories to check
$dirsToCheck = @("src/core")

# Patterns that indicate actual 3rd-party code (not just comments)
# These patterns match actual #include or API usage, not comments
$thirdPartyPatterns = @(
    '#include\s+<ffmpeg',
    '#include\s+<libav',
    '#include\s+<SDL2',
    '#include\s+<Qt',
    '#include\s+<d3d11',
    '#include\s+<dxgi',
    '#include\s+<wasapi',
    '#include\s+"third_party/',
    '#include\s+"external/',
    'avformat_open_input',  # FFmpeg API
    'avcodec_send_packet',  # FFmpeg API
    'SDL_Init',             # SDL API
    'QApplication',         # Qt API
    'ID3D11Device',        # D3D11 API
    'IAudioClient'         # WASAPI API
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
            
            # Skip comment lines (lines starting with // or containing only comments)
            if ($line -match '^\s*//') {
                continue
            }
            
            # Check for 3rd-party indicators (only in non-comment lines)
            foreach ($pattern in $thirdPartyPatterns) {
                if ($line -match $pattern) {
                    Write-Output "STOP: [$($file.FullName):$lineNum] 3rd-party code: $pattern"
                    Write-Output "  Line: $line"
                    $exitCode = 1
                    break
                }
            }
        }
    }
}

if ($exitCode -eq 0) {
    Write-Output "PASS: Source purity check passed (no 3rd-party code in src/core)"
    Write-Output "=== Source Purity Check: PASSED ==="
} else {
    Write-Output "=== Source Purity Check: FAILED ==="
}

exit $exitCode
