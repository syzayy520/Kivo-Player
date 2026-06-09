# check-doc-index.ps1 - Check docs/README.md index completeness
# Usage: powershell -ExecutionPolicy Bypass -File scripts/check-doc-index.ps1

$ErrorActionPreference = "Stop"

$docsDir = Join-Path $PSScriptRoot "..\docs"
$readmePath = Join-Path $docsDir "README.md"

Write-Output "=== Document Index Check ==="

# Check if docs/README.md exists
if (-not (Test-Path $readmePath)) {
    Write-Output "FAIL: docs/README.md not found at $readmePath"
    exit 1
}

# Parse docs/README.md to get listed documents
$readmeContent = Get-Content $readmePath -Encoding UTF8
$listedDocs = @()
$inTable = $false
foreach ($line in $readmeContent) {
    if ($line -match "^\| \[(.+?)\]\((.+?)\) \|") {
        $docFile = $matches[2]
        $listedDocs += $docFile
    }
}

Write-Output "Listed documents in docs/README.md: $($listedDocs.Count)"
foreach ($doc in $listedDocs) {
    Write-Output "  - $doc"
}

# Check all .md files in docs/ (excluding README.md itself)
$allDocs = Get-ChildItem -Path $docsDir -Filter "*.md" | Where-Object { $_.Name -ne "README.md" }
$missingDocs = @()

foreach ($docFile in $allDocs) {
    $relativePath = $docFile.Name
    if ($listedDocs -notcontains $relativePath) {
        $missingDocs += $relativePath
        Write-Output "WARN: $relativePath not listed in docs/README.md"
    }
}

if ($missingDocs.Count -gt 0) {
    Write-Output "FAIL: $($missingDocs.Count) documents not listed in docs/README.md"
    Write-Output "=== Document Index Check: FAILED ==="
    exit 1
} else {
    Write-Output "PASS: All documents listed in docs/README.md"
    Write-Output "=== Document Index Check: PASSED ==="
    exit 0
}
