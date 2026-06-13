#!/usr/bin/env pwsh
#Requires -Version 7.4
# Audit an existing commit (or HEAD) against this repository's commit policy:
# validates the message format AND scans the commit's changes for unsafe content.
# This is the one-shot you can run yourself after committing.
#
# Usage:
#   pwsh check-commit.ps1            # check HEAD
#   pwsh check-commit.ps1 <sha>      # check a specific commit
#
# Exit: 0 = conforms, 1 = issue(s) found, 2 = bad usage / not a valid commit.
param([Parameter(Position = 0)][string]$Commit = 'HEAD')

$ErrorActionPreference = 'Stop'
$here = Split-Path -Parent $MyInvocation.MyCommand.Path
$exe  = (Get-Process -Id $PID).Path   # reuse the current PowerShell host (pwsh)

git rev-parse --is-inside-work-tree 1>$null 2>$null
if ($LASTEXITCODE -ne 0) { Write-Host 'Not inside a git repository.'; exit 2 }
git rev-parse --verify --quiet "$Commit^{commit}" 1>$null 2>$null
if ($LASTEXITCODE -ne 0) { Write-Host "Not a valid commit: $Commit"; exit 2 }

$short = git rev-parse --short $Commit
Write-Host "== Checking commit $short =="

Write-Host ''
Write-Host '-- message --'
& $exe -NoProfile -File (Join-Path $here 'check-message.ps1') -Commit $Commit
$m = $LASTEXITCODE

Write-Host ''
Write-Host '-- changes --'
& $exe -NoProfile -File (Join-Path $here 'check-changes.ps1') -Commit $Commit
$c = $LASTEXITCODE

$fail = [int]($m -gt 0) -bor [int]($c -gt 0)
Write-Host ''
if ($fail -eq 0) { Write-Host "PASSED: commit $short conforms." } else { Write-Host "FAILED: commit $short has issues above." }
exit $fail
