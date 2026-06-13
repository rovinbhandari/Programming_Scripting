#!/usr/bin/env pwsh
#Requires -Version 7.4
# Safety scan of changes for things that must never be committed: secrets,
# local filesystem paths (Windows and Linux), and force-added .gitignored
# files. Run it yourself any time.
#
# Usage:
#   pwsh check-changes.ps1                 # scan the currently STAGED changes (default)
#   pwsh check-changes.ps1 -Commit HEAD    # scan the changes in an existing commit
#   pwsh check-changes.ps1 -Commit <sha>   # scan the changes in a specific commit
#
# Exit: 0 = no blocking issues, 1 = blocking issue(s) found, 2 = bad usage / not a git repo.
param([string]$Commit)

$ErrorActionPreference = 'Stop'

git rev-parse --is-inside-work-tree 1>$null 2>$null
if ($LASTEXITCODE -ne 0) { Write-Host 'Not inside a git repository.'; exit 2 }

if ($Commit) {
  git rev-parse --verify --quiet "$Commit^{commit}" 1>$null 2>$null
  if ($LASTEXITCODE -ne 0) { Write-Host "Not a valid commit: $Commit"; exit 2 }
  $names    = @(git diff-tree --no-commit-id --name-only -r --root --diff-filter=ACMR $Commit | Where-Object { $_ })
  $diffText = git diff-tree --no-commit-id -p --unified=0 -r --root $Commit
  $scope    = "commit $(git rev-parse --short $Commit)"
} else {
  $names    = @(git diff --cached --name-only --diff-filter=ACMR | Where-Object { $_ })
  $diffText = git diff --cached --unified=0
  $scope    = 'staged changes'
}

if ($names.Count -eq 0) { Write-Host "No changes to check in $scope."; exit 0 }

$block = [System.Collections.Generic.List[string]]::new()
$warn  = [System.Collections.Generic.List[string]]::new()

# Files matching .gitignore that are present anyway (force-added). --no-index makes
# check-ignore consult the ignore rules even for already-tracked paths.
foreach ($f in $names) {
  git check-ignore -q --no-index -- $f 2>$null
  if ($LASTEXITCODE -eq 0) { $block.Add("Ignored file is committed/staged (force-added?): $f") }
}

# Staged .env files (a committed default may be fine; confirm no real secrets).
foreach ($f in $names) {
  $leaf = Split-Path $f -Leaf
  if ($leaf -match '^\.env($|\.)' -and $leaf -notmatch '\.(example|sample|template|dist)$') {
    $warn.Add("Env file in $scope`: $f (confirm it contains no real secrets).")
  }
}

# Added lines (with their file path) from the diff.
$file = ''
$added = [System.Collections.Generic.List[psobject]]::new()
foreach ($ln in $diffText) {
  if ($ln.StartsWith('+++ ')) {
    $p = $ln.Substring(4); if ($p.StartsWith('b/')) { $p = $p.Substring(2) }
    $file = $p; continue
  }
  if ($ln.StartsWith('+') -and -not $ln.StartsWith('+++')) {
    $added.Add([pscustomobject]@{ File = $file; Text = $ln.Substring(1) })
  }
}

# A path segment that is clearly a placeholder rather than a real user/dir.
function Test-PlaceholderPath([string]$p) {
  return ($p -match '(?i)(\\|/)(user|username|youruser|someone|you|name|shared|public|default|runner)(/|\\|$)') -or
         ($p -match '\.\.\.|<[^>]+>|\$\{|%\w+%')
}

# Personal home directories (blocking) across operating systems.
$homeRx = '([A-Za-z]:\\Users\\[^\\/:*?"<>|]+)' +   # Windows  C:\Users\<user>
          '|(/home/[^/\s]+)' +                      # Linux home dir (commit-skill:allow)
          '|(/root(?:/[^/\s]*|\b))' +               # Linux root home (commit-skill:allow)
          '|(/mnt/[a-z]/Users/[^/\s]+)'             # WSL Windows user dir (commit-skill:allow)

# Other machine-specific absolute paths (warning).
$driveRx = '\b[A-Za-z]:\\(?!Users\\)[^\s:*?"<>|]{2,}' # Windows drive path (non-Users)
$mntRx   = '/mnt/[a-z](?:/[^\s:*?"<>|]+)?'            # WSL / mounted drive
$mediaRx = '/(?:media|run/media)/[^/\s]+/[^\s]*'      # removable media (/media/<user>/...)
$tildeRx = '(?<![\w./~])~/[^\s:*?"<>|]+'              # home-relative path (commit-skill:allow)

foreach ($a in $added) {
  $t = $a.Text; $f = $a.File
  if ($t -match 'commit-skill:allow') { continue }   # honor inline allow marker

  if ($t -match '-----BEGIN [A-Z0-9 ]*PRIVATE KEY-----') { $block.Add("Private key material in $f") }
  if ($t -match '\bAKIA[0-9A-Z]{16}\b')                  { $block.Add("AWS access key id in $f") }
  if ($t -match '[A-Za-z][A-Za-z0-9+.\-]*://[^/\s:@]+:[^/\s:@]+@') { $block.Add("Credential embedded in URL in $f") }

  if ($t -match $homeRx) {
    $hit = $matches[0]
    if (-not (Test-PlaceholderPath $hit)) { $block.Add("Local home/personal path in ${f}: $hit") }
  }

  foreach ($rx in @($driveRx, $mntRx, $mediaRx, $tildeRx)) {
    if ($t -match $rx) {
      $hit = $matches[0]
      if (-not (Test-PlaceholderPath $hit)) { $warn.Add("Absolute/local path in ${f}: $hit") }
    }
  }

  if ($t -match '(?i)\b(pass(?:word|wd)?|secret|token|api[_-]?key|access[_-]?key|client[_-]?secret|auth[_-]?token)\b\s*[:=]\s*["'']?([^\s"'']{6,})') {
    $val = $matches[2]
    $isPh = $val -match '(?i)(your[_-]?|example|changeme|placeholder|redacted|dummy|sample|test[_-]?only|<[^>]+>|\$\{|xx+|0{6,})'
    $isType = $val -match '(?i)^(string|number|boolean|object|null|true|false|undefined|any|none|nil|int|integer|bool|float|double|str|date|guid|uuid|env)$'
    if (-not $isPh -and -not $isType) { $warn.Add("Possible secret assignment in ${f}: $($matches[0].Trim())") }
  }
  if ($t -match '(?i)\bbearer\s+[A-Za-z0-9._\-]{20,}') { $warn.Add("Bearer token in $f") }
}

function Write-Section($title, $items, $mark) {
  if ($items.Count -gt 0) {
    Write-Host ''
    Write-Host $title
    foreach ($i in ($items | Select-Object -Unique)) { Write-Host "  $mark $i" }
  }
}

Write-Host "Scanning $scope ($($names.Count) file(s))..."
Write-Section 'Blocking issues:' $block 'X'
Write-Section 'Warnings (confirm each is intentional):' $warn '!'

if ($block.Count -eq 0 -and $warn.Count -eq 0) { Write-Host 'No issues found.' }
Write-Host ''
Write-Host "Also (not auto-checked): read AGENTS.md at the repo root and in touched folders and honor any commit rules; review the diff for personal data and insecure code."

exit ([int]($block.Count -gt 0))
