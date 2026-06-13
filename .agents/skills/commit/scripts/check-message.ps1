#!/usr/bin/env pwsh
#Requires -Version 7.4
# Validate a commit message against this repository's convention:
#   - Subject (first line) <= 80 characters.
#   - A blank line, then up to 5 bullets ("- ..."), each <= 120 characters.
#   - Trailers (Co-authored-by:, Signed-off-by:, ...) are exempt.
# Usage:
#   pwsh check-message.ps1 <message-file>     # validate a draft message file
#   pwsh check-message.ps1 -Commit HEAD       # validate an existing commit's message
#   <command> | pwsh check-message.ps1        # validate piped text
# Exit:   0 = OK, 1 = rule violation(s), 2 = usage error.
param([Parameter(Position = 0)][string]$Path, [string]$Commit)

$ErrorActionPreference = 'Stop'

if ($Commit) {
  git rev-parse --verify --quiet "$Commit^{commit}" 1>$null 2>$null
  if ($LASTEXITCODE -ne 0) { Write-Host "Not a valid commit: $Commit"; exit 2 }
  $raw = (git log -1 --format=%B $Commit | Out-String)
} elseif ($Path) {
  if (-not (Test-Path -LiteralPath $Path)) { Write-Host "Message file not found: $Path"; exit 2 }
  $raw = Get-Content -LiteralPath $Path -Raw
} elseif ([Console]::IsInputRedirected) {
  $raw = [Console]::In.ReadToEnd()
} else {
  Write-Host 'Usage: check-message.ps1 <message-file> | -Commit <ref>'; exit 2
}

if ([string]::IsNullOrWhiteSpace($raw)) { Write-Host 'X Empty commit message.'; exit 1 }

# Drop git comment lines, then strip leading/trailing blank lines.
$lines = @($raw -split "`r?`n" | Where-Object { $_ -notmatch '^\s*#' })
$start = 0; $end = $lines.Count - 1
while ($start -le $end -and $lines[$start].Trim() -eq '') { $start++ }
while ($end -ge $start -and $lines[$end].Trim() -eq '') { $end-- }
if ($start -gt $end) { Write-Host 'X Empty commit message.'; exit 1 }
$lines = @($lines[$start..$end])

$errs = @(); $warns = @()

$subject = $lines[0]
if ($subject.Length -gt 80) { $errs += "Subject is $($subject.Length) chars (max 80)." }
if ($subject -match '\.\s*$') { $warns += 'Subject ends with a period (convention: no trailing period).' }
if ($lines.Count -ge 2 -and $lines[1].Trim() -ne '') { $warns += 'No blank line between subject and body.' }

$trailerRx = '^(Co-authored-by|Signed-off-by|Acked-by|Reviewed-by|Reported-by|Tested-by|Cc|Refs?|Fixes|Closes|Resolves|See-also|BREAKING[ -]CHANGE):'
$bullets = 0
for ($i = 1; $i -lt $lines.Count; $i++) {
  $l = $lines[$i]
  if ($l.Trim() -eq '' -or $l -match $trailerRx) { continue }
  if ($l -match '^\s*[-*]\s+\S') {
    $bullets++
    if ($l.Length -gt 120) { $errs += "Bullet $bullets is $($l.Length) chars (max 120)." }
  } else {
    $warns += "Body line is neither a bullet nor a trailer: '$l'"
  }
}
if ($bullets -gt 5) { $errs += "Body has $bullets bullets (max 5)." }

foreach ($e in $errs)  { Write-Host "X $e" }
foreach ($w in $warns) { Write-Host "! $w" }
if ($errs.Count -eq 0) { Write-Host "OK: subject $($subject.Length) chars, $bullets bullet(s)." }

exit ([int]($errs.Count -gt 0))
