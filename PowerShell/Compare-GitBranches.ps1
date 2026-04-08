<#
.SYNOPSIS
    Compares two git branches holistically by content, producing a detailed report.

.DESCRIPTION
    Performs a comprehensive content-based comparison of two git branches, designed
    for repositories where history has been rewritten. Instead of relying solely on
    commit ancestry, this script compares actual file trees, blob hashes, and diffs.

    Analysis includes:
    - Commit ahead/behind counts (ancestry-based, informational only)
    - File-level diff stats (additions, deletions, modifications, renames)
    - Unique files per branch (files that exist only on one side)
    - Content comparison for shared-path files (same path, different content)
    - Rename/move detection via blob hash matching
    - Unique content chunks (diff hunks for files with differing content)

    Defaults:
    - BaseBranch defaults to the currently checked-out local branch.
    - CompareBranch defaults to the upstream remote of the current branch.
    - Both parameters support tab completion from all local and remote branches.

.PARAMETER BaseBranch
    The base branch for comparison (e.g., 'main', 'origin/main'). Defaults to
    the currently checked-out local branch.

.PARAMETER CompareBranch
    The branch to compare against the base (e.g., 'origin/bkp/tablet'). Defaults
    to the upstream remote-tracking branch of the current branch.

.PARAMETER RepoPath
    Path to the git repository. Defaults to the current directory.

.PARAMETER OutputPath
    Path for the output report file. Defaults to a timestamped .md file in the
    repo directory.

.PARAMETER Format
    Output format: 'Markdown' (default) or 'Text'.

.PARAMETER MaxDiffLines
    Maximum number of diff lines to include per file for content chunks. Default: 500.

.PARAMETER SkipContentChunks
    Skip the detailed per-file diff hunks (faster for large repos).

.PARAMETER LogPath
    Path for the log file. Defaults to a timestamped .log file next to the report.

.EXAMPLE
    .\Compare-GitBranches.ps1
    # Uses current branch as base and its upstream as compare.

.EXAMPLE
    .\Compare-GitBranches.ps1 -BaseBranch origin/main -CompareBranch origin/bkp/tablet

.EXAMPLE
    .\Compare-GitBranches.ps1 -BaseBranch main -CompareBranch origin/del/main -RepoPath C:\MyRepo -SkipContentChunks

.EXAMPLE
    .\Compare-GitBranches.ps1 -BaseBranch origin/main -CompareBranch origin/tablet -Verbose -Debug
#>

[CmdletBinding()]
param(
    [Parameter(Mandatory = $false, Position = 0)]
    [string]$BaseBranch,

    [Parameter(Mandatory = $false, Position = 1)]
    [string]$CompareBranch,

    [Parameter(Mandatory = $false)]
    [string]$RepoPath = ".",

    [Parameter(Mandatory = $false)]
    [string]$OutputPath,

    [Parameter(Mandatory = $false)]
    [ValidateSet('Markdown', 'Text')]
    [string]$Format = 'Markdown',

    [Parameter(Mandatory = $false)]
    [int]$MaxDiffLines = 500,

    [Parameter(Mandatory = $false)]
    [switch]$SkipContentChunks,

    [Parameter(Mandatory = $false)]
    [string]$LogPath
)

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

#region Tab Completion

$script:BranchCompleter = {
    param($commandName, $parameterName, $wordToComplete, $commandAst, $fakeBoundParameters)

    try {
        $branches = @(git branch -a --no-color 2>$null |
            ForEach-Object { $_.Trim() -replace '^\*\s+', '' -replace '^remotes/', '' } |
            Where-Object { $_ -and $_ -notmatch '->' } |
            Sort-Object -Unique)

        $pattern = if ($wordToComplete) { "$wordToComplete*" } else { '*' }

        $branches | Where-Object { $_ -like $pattern } | ForEach-Object {
            [System.Management.Automation.CompletionResult]::new($_, $_, 'ParameterValue', $_)
        }
    }
    catch {
        # Silently fail — tab completion should never throw
    }
}

Register-ArgumentCompleter -CommandName $MyInvocation.MyCommand.Name -ParameterName BaseBranch -ScriptBlock $script:BranchCompleter
Register-ArgumentCompleter -CommandName $MyInvocation.MyCommand.Name -ParameterName CompareBranch -ScriptBlock $script:BranchCompleter

#endregion

#region Resolve Branch Defaults

if (-not $BaseBranch) {
    $BaseBranch = (git symbolic-ref --short HEAD 2>$null)
    if (-not $BaseBranch) {
        throw "No BaseBranch specified and unable to detect current branch. Are you in a git repository?"
    }
    Write-Verbose "BaseBranch defaulted to current branch: $BaseBranch"
}

if (-not $CompareBranch) {
    # Get the upstream remote-tracking branch of the current (or specified base) branch
    $upstream = (git rev-parse --abbrev-ref "${BaseBranch}@{upstream}" 2>$null)
    if (-not $upstream) {
        throw "No CompareBranch specified and '$BaseBranch' has no upstream tracking branch. Set one with 'git branch -u <remote>/<branch>' or specify -CompareBranch explicitly."
    }
    $CompareBranch = $upstream
    Write-Verbose "CompareBranch defaulted to upstream: $CompareBranch"
}

#endregion

#region Telemetry & Logging

$script:Telemetry = [ordered]@{
    StartTime        = [datetime]::UtcNow
    EndTime          = $null
    Duration         = $null
    BaseBranch       = $BaseBranch
    CompareBranch    = $CompareBranch
    RepoPath         = $null
    GitVersion       = $null
    TotalFilesBase   = 0
    TotalFilesCompare = 0
    UniqueToBase     = 0
    UniqueToCompare  = 0
    SharedModified   = 0
    SharedIdentical  = 0
    Renames          = 0
    Errors           = [System.Collections.Generic.List[string]]::new()
    Warnings         = [System.Collections.Generic.List[string]]::new()
}

function Write-Log {
    [CmdletBinding()]
    param(
        [Parameter(Mandatory)][string]$Message,
        [ValidateSet('INFO', 'WARN', 'ERROR', 'DEBUG', 'VERBOSE')][string]$Level = 'INFO'
    )

    $timestamp = Get-Date -Format 'yyyy-MM-dd HH:mm:ss.fff'
    $entry = "[$timestamp] [$Level] $Message"

    switch ($Level) {
        'DEBUG'   { Write-Debug $Message }
        'VERBOSE' { Write-Verbose $Message }
        'WARN'    { Write-Warning $Message; $script:Telemetry.Warnings.Add($Message) }
        'ERROR'   { Write-Error $Message; $script:Telemetry.Errors.Add($Message) }
        default   { Write-Host $entry }
    }

    if ($script:LogFile) {
        $entry | Out-File -FilePath $script:LogFile -Append -Encoding utf8
    }
}

#endregion

#region Git Helpers

function Invoke-Git {
    [CmdletBinding()]
    param(
        [Parameter(Mandatory)][string[]]$Arguments
    )

    $argString = $Arguments -join ' '
    Write-Log "git $argString" -Level DEBUG

    $output = & git @Arguments 2>&1
    $exitCode = $LASTEXITCODE

    if ($exitCode -ne 0) {
        $errorText = ($output | Where-Object { $_ -is [System.Management.Automation.ErrorRecord] }) -join "`n"
        if (-not $errorText) { $errorText = $output -join "`n" }
        Write-Log "git exited with code $exitCode`: $errorText" -Level WARN
        return $null
    }

    # Filter out stderr/ErrorRecords, return only stdout strings
    $output | Where-Object { $_ -isnot [System.Management.Automation.ErrorRecord] }
}

function Test-BranchExists {
    [CmdletBinding()]
    param([string]$Branch)

    $result = Invoke-Git @('rev-parse', '--verify', '--quiet', $Branch)
    return ($LASTEXITCODE -eq 0)
}

function Get-BranchFiles {
    <# Returns hashtable: path -> blob hash #>
    [CmdletBinding()]
    param([string]$Branch)

    Write-Log "Listing file tree for $Branch" -Level VERBOSE
    $files = @{}
    $lines = Invoke-Git @('ls-tree', '-r', '--format=%(objectname) %(path)', $Branch)
    if ($null -eq $lines) { return $files }

    foreach ($line in $lines) {
        if ($line -match '^([0-9a-f]+)\s+(.+)$') {
            $files[$Matches[2]] = $Matches[1]
        }
    }
    Write-Log "Found $($files.Count) files on $Branch" -Level VERBOSE
    return $files
}

function Get-CommitCounts {
    <# Returns ahead/behind counts between two branches #>
    [CmdletBinding()]
    param([string]$BranchA, [string]$BranchB)

    $aheadLines = Invoke-Git @('rev-list', '--count', "$BranchA..$BranchB")
    $behindLines = Invoke-Git @('rev-list', '--count', "$BranchB..$BranchA")

    $ahead = if ($null -ne $aheadLines) { [int]($aheadLines | Select-Object -First 1) } else { -1 }
    $behind = if ($null -ne $behindLines) { [int]($behindLines | Select-Object -First 1) } else { -1 }

    return @{ Ahead = $ahead; Behind = $behind }
}

function Get-DiffStat {
    <# Returns the --stat output as a string #>
    [CmdletBinding()]
    param([string]$BranchA, [string]$BranchB)

    $output = Invoke-Git @('diff', '--stat', $BranchA, $BranchB)
    if ($null -eq $output) { return "" }
    return ($output -join "`n")
}

function Get-DiffNameStatus {
    <# Returns parsed name-status entries #>
    [CmdletBinding()]
    param([string]$BranchA, [string]$BranchB)

    $lines = Invoke-Git @('diff', '--name-status', '-M', $BranchA, $BranchB)
    if ($null -eq $lines) { return @() }

    $entries = @()
    foreach ($line in $lines) {
        if ($line -match '^(R\d*)\t(.+)\t(.+)$') {
            $entries += [PSCustomObject]@{ Status = $Matches[1]; Path = $Matches[3]; OldPath = $Matches[2] }
        }
        elseif ($line -match '^([AMDTCUX])\t(.+)$') {
            $entries += [PSCustomObject]@{ Status = $Matches[1]; Path = $Matches[2]; OldPath = $null }
        }
    }
    return $entries
}

function Get-FileDiffHunks {
    <# Returns truncated diff hunks for a single file between two branches #>
    [CmdletBinding()]
    param([string]$BranchA, [string]$BranchB, [string]$FilePath, [int]$MaxLines)

    $output = Invoke-Git @('diff', '--unified=3', $BranchA, $BranchB, '--', $FilePath)
    if ($null -eq $output) { return "" }

    $allLines = $output
    if ($allLines.Count -gt $MaxLines) {
        $truncated = $allLines | Select-Object -First $MaxLines
        $remaining = $allLines.Count - $MaxLines
        return (($truncated -join "`n") + "`n... ($remaining more lines truncated)")
    }
    return ($allLines -join "`n")
}

#endregion

#region Analysis Functions

function Find-BlobMatches {
    <#
    .SYNOPSIS
        For files unique to one branch, find if identical content exists at a
        different path on the other branch (rename/move detection by blob hash).
    #>
    [CmdletBinding()]
    param(
        [hashtable]$UniqueFiles,       # path -> blob hash (files on one side only)
        [hashtable]$OtherBranchFiles   # path -> blob hash (all files on the other side)
    )

    Write-Log "Scanning for blob-level rename matches across $($UniqueFiles.Count) files" -Level VERBOSE

    # Build reverse lookup: blob -> list of paths on the other branch
    $blobToPath = @{}
    foreach ($entry in $OtherBranchFiles.GetEnumerator()) {
        if (-not $blobToPath.ContainsKey($entry.Value)) {
            $blobToPath[$entry.Value] = [System.Collections.Generic.List[string]]::new()
        }
        $blobToPath[$entry.Value].Add($entry.Key)
    }

    $matches = @()
    foreach ($entry in $UniqueFiles.GetEnumerator()) {
        $blob = $entry.Value
        if ($blobToPath.ContainsKey($blob)) {
            $matches += [PSCustomObject]@{
                Path        = $entry.Key
                Blob        = $blob
                MatchPaths  = $blobToPath[$blob]
                Type        = 'IdenticalContent'
            }
        }
    }

    Write-Log "Found $($matches.Count) blob-level matches" -Level VERBOSE
    return $matches
}

function Get-SharedFileAnalysis {
    <#
    .SYNOPSIS
        For files that exist at the same path on both branches, classify as
        identical or modified by comparing blob hashes.
    #>
    [CmdletBinding()]
    param(
        [hashtable]$BaseFiles,
        [hashtable]$CompareFiles
    )

    $identical = [System.Collections.Generic.List[string]]::new()
    $modified = [System.Collections.Generic.List[string]]::new()

    $sharedPaths = $BaseFiles.Keys | Where-Object { $CompareFiles.ContainsKey($_) }

    foreach ($path in $sharedPaths) {
        if ($BaseFiles[$path] -eq $CompareFiles[$path]) {
            $identical.Add($path)
        }
        else {
            $modified.Add($path)
        }
    }

    Write-Log "Shared paths: $($identical.Count) identical, $($modified.Count) modified" -Level VERBOSE
    return @{ Identical = $identical; Modified = $modified }
}

#endregion

#region Report Generation

function Format-Markdown {
    [CmdletBinding()]
    param([hashtable]$Data)

    $sb = [System.Text.StringBuilder]::new()

    [void]$sb.AppendLine("# Git Branch Comparison Report")
    [void]$sb.AppendLine("")
    [void]$sb.AppendLine("Generated: $(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')")
    [void]$sb.AppendLine("Analysis method: **content-based** (blob hash comparison + diff)")
    [void]$sb.AppendLine("")
    [void]$sb.AppendLine("| Property | Value |")
    [void]$sb.AppendLine("|---|---|")
    [void]$sb.AppendLine("| Base branch | ``$($Data.BaseBranch)`` |")
    [void]$sb.AppendLine("| Compare branch | ``$($Data.CompareBranch)`` |")
    [void]$sb.AppendLine("| Repository | ``$($Data.RepoPath)`` |")
    [void]$sb.AppendLine("| Git version | $($Data.GitVersion) |")
    [void]$sb.AppendLine("")

    # Commit counts
    [void]$sb.AppendLine("---")
    [void]$sb.AppendLine("")
    [void]$sb.AppendLine("## Commit Ancestry")
    [void]$sb.AppendLine("")
    if ($Data.CommitCounts.Ahead -ge 0) {
        [void]$sb.AppendLine("| Metric | Count |")
        [void]$sb.AppendLine("|---|---|")
        [void]$sb.AppendLine("| Compare ahead of Base | $($Data.CommitCounts.Ahead) |")
        [void]$sb.AppendLine("| Compare behind Base | $($Data.CommitCounts.Behind) |")
        if ($Data.CommitCounts.Ahead -eq 0 -and $Data.CommitCounts.Behind -eq 0) {
            [void]$sb.AppendLine("")
            [void]$sb.AppendLine("> Branches point to the same commit.")
        }
        elseif ($Data.CommitCounts.Ahead -eq 0) {
            [void]$sb.AppendLine("")
            [void]$sb.AppendLine("> Compare is an ancestor (subset) of Base by commit history.")
        }
    }
    else {
        [void]$sb.AppendLine("> Could not determine commit ancestry (branches may not share history).")
    }
    [void]$sb.AppendLine("")
    [void]$sb.AppendLine("> **Note**: With rewritten history, commit counts may be misleading. See content analysis below.")
    [void]$sb.AppendLine("")

    # File tree summary
    [void]$sb.AppendLine("---")
    [void]$sb.AppendLine("")
    [void]$sb.AppendLine("## File Tree Summary")
    [void]$sb.AppendLine("")
    [void]$sb.AppendLine("| Metric | Count |")
    [void]$sb.AppendLine("|---|---|")
    [void]$sb.AppendLine("| Total files on Base | $($Data.BaseFileCount) |")
    [void]$sb.AppendLine("| Total files on Compare | $($Data.CompareFileCount) |")
    [void]$sb.AppendLine("| Files at shared paths | $($Data.SharedIdentical + $Data.SharedModified) |")
    [void]$sb.AppendLine("| — Identical content | $($Data.SharedIdentical) |")
    [void]$sb.AppendLine("| — Modified content | $($Data.SharedModified) |")
    [void]$sb.AppendLine("| Unique to Base | $($Data.UniqueToBase) |")
    [void]$sb.AppendLine("| Unique to Compare | $($Data.UniqueToCompare) |")
    [void]$sb.AppendLine("")

    # Content verdict
    if ($Data.SharedModified -eq 0 -and $Data.UniqueToBase -eq 0 -and $Data.UniqueToCompare -eq 0) {
        [void]$sb.AppendLine("> **Verdict: Branches are content-identical.** Safe to delete Compare branch.")
    }
    elseif ($Data.SharedModified -eq 0 -and $Data.UniqueToCompare -eq 0 -and $Data.UniqueToBase -gt 0) {
        [void]$sb.AppendLine("> **Verdict: Compare is a content-subset of Base.** All Compare files exist identically on Base. Safe to delete Compare branch.")
    }
    elseif ($Data.SharedModified -eq 0 -and $Data.UniqueToBase -eq 0 -and $Data.UniqueToCompare -gt 0) {
        [void]$sb.AppendLine("> **Verdict: Base is a content-subset of Compare.** Compare has additional files.")
    }
    else {
        [void]$sb.AppendLine("> **Verdict: Branches have divergent content.** Review details below before deleting.")
    }
    [void]$sb.AppendLine("")

    # Diff stat
    [void]$sb.AppendLine("---")
    [void]$sb.AppendLine("")
    [void]$sb.AppendLine("## Diff Stat")
    [void]$sb.AppendLine("")
    [void]$sb.AppendLine('```')
    [void]$sb.AppendLine($Data.DiffStat)
    [void]$sb.AppendLine('```')
    [void]$sb.AppendLine("")

    # Name-status table
    if ($Data.NameStatus.Count -gt 0) {
        [void]$sb.AppendLine("---")
        [void]$sb.AppendLine("")
        [void]$sb.AppendLine("## File Change Summary (name-status)")
        [void]$sb.AppendLine("")

        $grouped = $Data.NameStatus | Group-Object { $_.Status.Substring(0,1) }
        $statusLabels = @{ 'A' = 'Added (on Compare)'; 'D' = 'Deleted (on Compare)'; 'M' = 'Modified'; 'R' = 'Renamed/Moved' }

        foreach ($group in $grouped | Sort-Object Name) {
            $label = if ($statusLabels.ContainsKey($group.Name)) { $statusLabels[$group.Name] } else { $group.Name }
            [void]$sb.AppendLine("### $label ($($group.Count) files)")
            [void]$sb.AppendLine("")
            [void]$sb.AppendLine("| File | Details |")
            [void]$sb.AppendLine("|---|---|")
            foreach ($item in $group.Group) {
                if ($item.OldPath) {
                    [void]$sb.AppendLine("| ``$($item.Path)`` | from ``$($item.OldPath)`` |")
                }
                else {
                    [void]$sb.AppendLine("| ``$($item.Path)`` | |")
                }
            }
            [void]$sb.AppendLine("")
        }
    }

    # Unique files with rename detection
    if ($Data.UniqueToBase -gt 0 -or $Data.UniqueToCompare -gt 0) {
        [void]$sb.AppendLine("---")
        [void]$sb.AppendLine("")
        [void]$sb.AppendLine("## Unique Files & Rename Detection")
        [void]$sb.AppendLine("")

        if ($Data.UniqueToBaseFiles.Count -gt 0) {
            [void]$sb.AppendLine("### Files only on Base ($($Data.UniqueToBase))")
            [void]$sb.AppendLine("")
            [void]$sb.AppendLine("| File | Blob Match on Compare |")
            [void]$sb.AppendLine("|---|---|")
            foreach ($path in $Data.UniqueToBaseFiles.Keys | Sort-Object) {
                $match = $Data.BaseBlobMatches | Where-Object { $_.Path -eq $path }
                if ($match) {
                    $matchPaths = ($match.MatchPaths -join ', ')
                    [void]$sb.AppendLine("| ``$path`` | Identical content at: ``$matchPaths`` |")
                }
                else {
                    [void]$sb.AppendLine("| ``$path`` | **No match — truly unique to Base** |")
                }
            }
            [void]$sb.AppendLine("")
        }

        if ($Data.UniqueToCompareFiles.Count -gt 0) {
            [void]$sb.AppendLine("### Files only on Compare ($($Data.UniqueToCompare))")
            [void]$sb.AppendLine("")
            [void]$sb.AppendLine("| File | Blob Match on Base |")
            [void]$sb.AppendLine("|---|---|")
            foreach ($path in $Data.UniqueToCompareFiles.Keys | Sort-Object) {
                $match = $Data.CompareBlobMatches | Where-Object { $_.Path -eq $path }
                if ($match) {
                    $matchPaths = ($match.MatchPaths -join ', ')
                    [void]$sb.AppendLine("| ``$path`` | Identical content at: ``$matchPaths`` |")
                }
                else {
                    [void]$sb.AppendLine("| ``$path`` | **No match — truly unique to Compare** |")
                }
            }
            [void]$sb.AppendLine("")
        }
    }

    # Shared files with modified content
    if ($Data.SharedModifiedList.Count -gt 0) {
        [void]$sb.AppendLine("---")
        [void]$sb.AppendLine("")
        [void]$sb.AppendLine("## Shared Paths with Different Content ($($Data.SharedModified) files)")
        [void]$sb.AppendLine("")
        [void]$sb.AppendLine("These files exist at the same path on both branches but have different content.")
        [void]$sb.AppendLine("")

        if ($Data.ContentChunks.Count -gt 0) {
            foreach ($path in $Data.SharedModifiedList | Sort-Object) {
                [void]$sb.AppendLine("### ``$path``")
                [void]$sb.AppendLine("")
                if ($Data.ContentChunks.ContainsKey($path)) {
                    [void]$sb.AppendLine('```diff')
                    [void]$sb.AppendLine($Data.ContentChunks[$path])
                    [void]$sb.AppendLine('```')
                }
                else {
                    [void]$sb.AppendLine("(diff not available)")
                }
                [void]$sb.AppendLine("")
            }
        }
        else {
            [void]$sb.AppendLine("| File |")
            [void]$sb.AppendLine("|---|")
            foreach ($path in $Data.SharedModifiedList | Sort-Object) {
                [void]$sb.AppendLine("| ``$path`` |")
            }
            [void]$sb.AppendLine("")
            [void]$sb.AppendLine("*(Content chunks skipped — use without ``-SkipContentChunks`` to see diffs)*")
            [void]$sb.AppendLine("")
        }
    }

    # Telemetry
    [void]$sb.AppendLine("---")
    [void]$sb.AppendLine("")
    [void]$sb.AppendLine("## Run Telemetry")
    [void]$sb.AppendLine("")
    [void]$sb.AppendLine("| Metric | Value |")
    [void]$sb.AppendLine("|---|---|")
    [void]$sb.AppendLine("| Start time (UTC) | $($script:Telemetry.StartTime.ToString('o')) |")
    [void]$sb.AppendLine("| Duration | $($script:Telemetry.Duration) |")
    [void]$sb.AppendLine("| Warnings | $($script:Telemetry.Warnings.Count) |")
    [void]$sb.AppendLine("| Errors | $($script:Telemetry.Errors.Count) |")
    [void]$sb.AppendLine("")

    return $sb.ToString()
}

function Format-PlainText {
    [CmdletBinding()]
    param([hashtable]$Data)

    $sb = [System.Text.StringBuilder]::new()

    [void]$sb.AppendLine("GIT BRANCH COMPARISON REPORT")
    [void]$sb.AppendLine("=" * 60)
    [void]$sb.AppendLine("Generated: $(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')")
    [void]$sb.AppendLine("Method: content-based (blob hash comparison + diff)")
    [void]$sb.AppendLine("")
    [void]$sb.AppendLine("Base branch:    $($Data.BaseBranch)")
    [void]$sb.AppendLine("Compare branch: $($Data.CompareBranch)")
    [void]$sb.AppendLine("Repository:     $($Data.RepoPath)")
    [void]$sb.AppendLine("Git version:    $($Data.GitVersion)")
    [void]$sb.AppendLine("")

    [void]$sb.AppendLine("COMMIT ANCESTRY")
    [void]$sb.AppendLine("-" * 40)
    if ($Data.CommitCounts.Ahead -ge 0) {
        [void]$sb.AppendLine("Compare ahead of Base:  $($Data.CommitCounts.Ahead)")
        [void]$sb.AppendLine("Compare behind Base:    $($Data.CommitCounts.Behind)")
    }
    else {
        [void]$sb.AppendLine("Could not determine (no shared history)")
    }
    [void]$sb.AppendLine("NOTE: With rewritten history, commit counts may be misleading.")
    [void]$sb.AppendLine("")

    [void]$sb.AppendLine("FILE TREE SUMMARY")
    [void]$sb.AppendLine("-" * 40)
    [void]$sb.AppendLine("Total files on Base:    $($Data.BaseFileCount)")
    [void]$sb.AppendLine("Total files on Compare: $($Data.CompareFileCount)")
    [void]$sb.AppendLine("Shared paths identical: $($Data.SharedIdentical)")
    [void]$sb.AppendLine("Shared paths modified:  $($Data.SharedModified)")
    [void]$sb.AppendLine("Unique to Base:         $($Data.UniqueToBase)")
    [void]$sb.AppendLine("Unique to Compare:      $($Data.UniqueToCompare)")
    [void]$sb.AppendLine("")

    [void]$sb.AppendLine("DIFF STAT")
    [void]$sb.AppendLine("-" * 40)
    [void]$sb.AppendLine($Data.DiffStat)
    [void]$sb.AppendLine("")

    if ($Data.NameStatus.Count -gt 0) {
        [void]$sb.AppendLine("FILE CHANGES (name-status)")
        [void]$sb.AppendLine("-" * 40)
        foreach ($item in $Data.NameStatus) {
            if ($item.OldPath) {
                [void]$sb.AppendLine("  $($item.Status)`t$($item.Path)  (from: $($item.OldPath))")
            }
            else {
                [void]$sb.AppendLine("  $($item.Status)`t$($item.Path)")
            }
        }
        [void]$sb.AppendLine("")
    }

    if ($Data.UniqueToBaseFiles.Count -gt 0) {
        [void]$sb.AppendLine("FILES ONLY ON BASE ($($Data.UniqueToBase))")
        [void]$sb.AppendLine("-" * 40)
        foreach ($path in $Data.UniqueToBaseFiles.Keys | Sort-Object) {
            $match = $Data.BaseBlobMatches | Where-Object { $_.Path -eq $path }
            if ($match) {
                [void]$sb.AppendLine("  $path  -> identical content at: $($match.MatchPaths -join ', ')")
            }
            else {
                [void]$sb.AppendLine("  $path  [TRULY UNIQUE]")
            }
        }
        [void]$sb.AppendLine("")
    }

    if ($Data.UniqueToCompareFiles.Count -gt 0) {
        [void]$sb.AppendLine("FILES ONLY ON COMPARE ($($Data.UniqueToCompare))")
        [void]$sb.AppendLine("-" * 40)
        foreach ($path in $Data.UniqueToCompareFiles.Keys | Sort-Object) {
            $match = $Data.CompareBlobMatches | Where-Object { $_.Path -eq $path }
            if ($match) {
                [void]$sb.AppendLine("  $path  -> identical content at: $($match.MatchPaths -join ', ')")
            }
            else {
                [void]$sb.AppendLine("  $path  [TRULY UNIQUE]")
            }
        }
        [void]$sb.AppendLine("")
    }

    if ($Data.SharedModifiedList.Count -gt 0) {
        [void]$sb.AppendLine("SHARED PATHS WITH DIFFERENT CONTENT ($($Data.SharedModified))")
        [void]$sb.AppendLine("-" * 40)
        foreach ($path in $Data.SharedModifiedList | Sort-Object) {
            [void]$sb.AppendLine("")
            [void]$sb.AppendLine("  $path")
            if ($Data.ContentChunks.ContainsKey($path)) {
                foreach ($line in ($Data.ContentChunks[$path] -split "`n")) {
                    [void]$sb.AppendLine("    $line")
                }
            }
        }
        [void]$sb.AppendLine("")
    }

    [void]$sb.AppendLine("TELEMETRY")
    [void]$sb.AppendLine("-" * 40)
    [void]$sb.AppendLine("Start (UTC): $($script:Telemetry.StartTime.ToString('o'))")
    [void]$sb.AppendLine("Duration:    $($script:Telemetry.Duration)")
    [void]$sb.AppendLine("Warnings:    $($script:Telemetry.Warnings.Count)")
    [void]$sb.AppendLine("Errors:      $($script:Telemetry.Errors.Count)")
    [void]$sb.AppendLine("")

    return $sb.ToString()
}

#endregion

#region Main

try {
    # Resolve paths
    $RepoPath = Resolve-Path $RepoPath -ErrorAction Stop | Select-Object -ExpandProperty Path
    $script:Telemetry.RepoPath = $RepoPath

    $timestamp = Get-Date -Format 'yyyyMMdd-HHmmss'
    $safeBranch = ($CompareBranch -replace '[/\\:*?"<>|]', '-')
    if (-not $OutputPath) {
        $ext = if ($Format -eq 'Markdown') { 'md' } else { 'txt' }
        $OutputPath = Join-Path $RepoPath "branch-compare-$safeBranch-$timestamp.$ext"
    }
    if (-not $LogPath) {
        $LogPath = Join-Path $RepoPath "branch-compare-$safeBranch-$timestamp.log"
    }
    $script:LogFile = $LogPath

    Write-Log "Starting branch comparison: $BaseBranch vs $CompareBranch"
    Write-Log "Repository: $RepoPath"
    Write-Log "Output: $OutputPath"

    # Change to repo directory
    Push-Location $RepoPath

    # Validate git
    $gitVersionOutput = Invoke-Git @('--version')
    if ($null -eq $gitVersionOutput) {
        throw "Git is not available. Ensure git is installed and in PATH."
    }
    $gitVersion = ($gitVersionOutput | Select-Object -First 1).Trim()
    $script:Telemetry.GitVersion = $gitVersion
    Write-Log "Git: $gitVersion" -Level VERBOSE

    # Validate branches
    Write-Log "Validating branches..." -Level VERBOSE
    if (-not (Test-BranchExists $BaseBranch)) {
        throw "Base branch '$BaseBranch' does not exist. Run 'git fetch' first for remote branches."
    }
    if (-not (Test-BranchExists $CompareBranch)) {
        throw "Compare branch '$CompareBranch' does not exist. Run 'git fetch' first for remote branches."
    }

    # 1. Commit ancestry
    Write-Log "Calculating commit counts..." -Level VERBOSE
    $commitCounts = Get-CommitCounts -BranchA $BaseBranch -BranchB $CompareBranch

    # 2. File trees
    Write-Log "Building file trees..." -Level VERBOSE
    $baseFiles = Get-BranchFiles -Branch $BaseBranch
    $compareFiles = Get-BranchFiles -Branch $CompareBranch
    $script:Telemetry.TotalFilesBase = $baseFiles.Count
    $script:Telemetry.TotalFilesCompare = $compareFiles.Count

    # 3. Shared file analysis
    Write-Log "Analyzing shared paths..." -Level VERBOSE
    $sharedAnalysis = Get-SharedFileAnalysis -BaseFiles $baseFiles -CompareFiles $compareFiles

    # 4. Unique files per branch
    $uniqueToBase = @{}
    foreach ($path in $baseFiles.Keys) {
        if (-not $compareFiles.ContainsKey($path)) {
            $uniqueToBase[$path] = $baseFiles[$path]
        }
    }

    $uniqueToCompare = @{}
    foreach ($path in $compareFiles.Keys) {
        if (-not $baseFiles.ContainsKey($path)) {
            $uniqueToCompare[$path] = $compareFiles[$path]
        }
    }

    $script:Telemetry.UniqueToBase = $uniqueToBase.Count
    $script:Telemetry.UniqueToCompare = $uniqueToCompare.Count
    $script:Telemetry.SharedModified = $sharedAnalysis.Modified.Count
    $script:Telemetry.SharedIdentical = $sharedAnalysis.Identical.Count

    # 5. Rename detection via blob hash
    Write-Log "Detecting renames via blob hash matching..." -Level VERBOSE
    $baseBlobMatches = @(Find-BlobMatches -UniqueFiles $uniqueToBase -OtherBranchFiles $compareFiles)
    $compareBlobMatches = @(Find-BlobMatches -UniqueFiles $uniqueToCompare -OtherBranchFiles $baseFiles)
    $script:Telemetry.Renames = $baseBlobMatches.Count + $compareBlobMatches.Count

    # 6. Diff stat and name-status
    Write-Log "Running diff stat..." -Level VERBOSE
    $diffStat = Get-DiffStat -BranchA $BaseBranch -BranchB $CompareBranch
    $nameStatus = @(Get-DiffNameStatus -BranchA $BaseBranch -BranchB $CompareBranch)

    # 7. Content chunks for modified shared files
    $contentChunks = @{}
    if (-not $SkipContentChunks -and $sharedAnalysis.Modified.Count -gt 0) {
        Write-Log "Extracting content chunks for $($sharedAnalysis.Modified.Count) modified files..." -Level VERBOSE
        $i = 0
        foreach ($path in $sharedAnalysis.Modified) {
            $i++
            Write-Progress -Activity "Extracting diff hunks" -Status $path -PercentComplete (($i / $sharedAnalysis.Modified.Count) * 100)
            Write-Log "Diffing: $path" -Level DEBUG
            $hunks = Get-FileDiffHunks -BranchA $BaseBranch -BranchB $CompareBranch -FilePath $path -MaxLines $MaxDiffLines
            if ($hunks) {
                $contentChunks[$path] = $hunks
            }
        }
        Write-Progress -Activity "Extracting diff hunks" -Completed
    }

    # Assemble report data
    $reportData = @{
        BaseBranch         = $BaseBranch
        CompareBranch      = $CompareBranch
        RepoPath           = $RepoPath
        GitVersion         = $gitVersion
        CommitCounts       = $commitCounts
        BaseFileCount      = $baseFiles.Count
        CompareFileCount   = $compareFiles.Count
        SharedIdentical    = $sharedAnalysis.Identical.Count
        SharedModified     = $sharedAnalysis.Modified.Count
        SharedModifiedList = $sharedAnalysis.Modified
        UniqueToBase       = $uniqueToBase.Count
        UniqueToCompare    = $uniqueToCompare.Count
        UniqueToBaseFiles  = $uniqueToBase
        UniqueToCompareFiles = $uniqueToCompare
        BaseBlobMatches    = $baseBlobMatches
        CompareBlobMatches = $compareBlobMatches
        DiffStat           = $diffStat
        NameStatus         = $nameStatus
        ContentChunks      = $contentChunks
    }

    # Format output
    Write-Log "Generating $Format report..." -Level VERBOSE
    $report = switch ($Format) {
        'Markdown'  { Format-Markdown -Data $reportData }
        'Text'      { Format-PlainText -Data $reportData }
    }

    # Finalize telemetry
    $script:Telemetry.EndTime = [datetime]::UtcNow
    $script:Telemetry.Duration = ($script:Telemetry.EndTime - $script:Telemetry.StartTime).ToString()

    # Write report
    $report | Out-File -FilePath $OutputPath -Encoding utf8 -NoNewline
    Write-Log "Report written to: $OutputPath"

    # Write telemetry to log
    Write-Log "--- Telemetry ---"
    foreach ($key in $script:Telemetry.Keys) {
        $val = $script:Telemetry[$key]
        if ($val -is [System.Collections.Generic.List[string]] -and $val.Count -gt 0) {
            Write-Log "  $key`:"
            foreach ($item in $val) { Write-Log "    - $item" }
        }
        else {
            Write-Log "  $key`: $val"
        }
    }

    # Console summary
    Write-Host ""
    Write-Host "Branch Comparison Complete" -ForegroundColor Green
    Write-Host "  Base:    $BaseBranch ($($baseFiles.Count) files)"
    Write-Host "  Compare: $CompareBranch ($($compareFiles.Count) files)"
    Write-Host "  Shared identical: $($sharedAnalysis.Identical.Count) | Modified: $($sharedAnalysis.Modified.Count)"
    Write-Host "  Unique to Base: $($uniqueToBase.Count) | Unique to Compare: $($uniqueToCompare.Count)"
    Write-Host "  Rename matches: $($baseBlobMatches.Count + $compareBlobMatches.Count)"
    Write-Host "  Report: $OutputPath" -ForegroundColor Cyan
    Write-Host "  Log:    $LogPath" -ForegroundColor DarkGray
    Write-Host ""
}
catch {
    Write-Log "FATAL: $_" -Level ERROR
    Write-Log $_.ScriptStackTrace -Level DEBUG
    throw
}
finally {
    Pop-Location -ErrorAction SilentlyContinue
}

#endregion
