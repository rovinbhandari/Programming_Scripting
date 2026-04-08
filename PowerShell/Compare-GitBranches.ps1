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
    - Rename/move detection via blob hash matching (renames are flagged but
      distinguished from true content differences in the verdict)
    - Unique content chunks (diff hunks for files with differing content)

    Defaults:
    - Base defaults to the upstream remote-tracking branch of the current branch.
    - CompareTo defaults to the currently checked-out local branch.
    - Both parameters support tab completion from all local and remote branches.
    - Use -IncludePath to scope comparison to specific files or folders.

    Report labels use actual branch names (e.g. "Unique to origin/main") rather
    than generic "Base"/"Compare" labels.

.PARAMETER Base
    The reference/older branch (e.g., 'origin/main'). Defaults to the upstream
    remote-tracking branch of the current local branch.

.PARAMETER CompareTo
    The branch to compare against Base — typically the newer/local branch
    (e.g., 'tablet'). Defaults to the currently checked-out local branch.

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

.PARAMETER IncludePath
    One or more glob patterns to scope the comparison to specific files or folders.
    Only files matching at least one pattern are included. Patterns are matched against
    repo-relative paths using -like. Use 'Book Notes/*' for a folder, '*.md' for a type.
    Renames into/out of matched paths are still detected.

.PARAMETER LogPath
    Path for the log file. Defaults to a timestamped .log file next to the report.

.EXAMPLE
    .\Compare-GitBranches.ps1
    # Base = upstream of current branch, CompareTo = current local branch.

.EXAMPLE
    .\Compare-GitBranches.ps1 -Base origin/main -CompareTo tablet

.EXAMPLE
    .\Compare-GitBranches.ps1 origin/main origin/del/main -RepoPath C:\MyRepo -SkipContentChunks

.EXAMPLE
    .\Compare-GitBranches.ps1 origin/main origin/tablet -IncludePath 'Book Notes/*','Clippings/*'

.EXAMPLE
    .\Compare-GitBranches.ps1 origin/main origin/tablet -Verbose -Debug
#>

[CmdletBinding()]
param(
    [Parameter(Mandatory = $false, Position = 0)]
    [Alias('BaseBranch')]
    [string]$Base,

    [Parameter(Mandatory = $false, Position = 1)]
    [Alias('CompareBranch')]
    [string]$CompareTo,

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
    [string[]]$IncludePath,

    [Parameter(Mandatory = $false)]
    [string]$LogPath
)

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

# Ensure git output is decoded as UTF-8 (prevents mojibake on non-ASCII paths like ø, अ)
$script:PreviousOutputEncoding = [Console]::OutputEncoding
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8

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

Register-ArgumentCompleter -CommandName $MyInvocation.MyCommand.Name -ParameterName Base -ScriptBlock $script:BranchCompleter
Register-ArgumentCompleter -CommandName $MyInvocation.MyCommand.Name -ParameterName CompareTo -ScriptBlock $script:BranchCompleter

#endregion

#region Resolve Branch Defaults

# Detect current local branch for resolving defaults
$currentBranch = (git symbolic-ref --short HEAD 2>$null)

if (-not $Base) {
    if (-not $currentBranch) {
        throw "No -Base specified and unable to detect current branch. Are you in a git repository?"
    }
    $upstream = (git rev-parse --abbrev-ref "${currentBranch}@{upstream}" 2>$null)
    if (-not $upstream) {
        throw "No -Base specified and '$currentBranch' has no upstream tracking branch. Set one with 'git branch -u <remote>/<branch>' or specify -Base explicitly."
    }
    $Base = $upstream
    Write-Verbose "Base defaulted to upstream of '$currentBranch': $Base"
}

if (-not $CompareTo) {
    if (-not $currentBranch) {
        throw "No -CompareTo specified and unable to detect current branch. Are you in a git repository?"
    }
    $CompareTo = $currentBranch
    Write-Verbose "CompareTo defaulted to current branch: $CompareTo"
}

#endregion

#region Telemetry & Logging

$script:Telemetry = [ordered]@{
    StartTime        = [datetime]::UtcNow
    EndTime          = $null
    Duration         = $null
    Base             = $Base
    CompareTo        = $CompareTo
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

    # Prepend -c core.quotePath=false so git emits raw UTF-8 paths
    # instead of octal-escaping non-ASCII characters (e.g. ø, अ).
    $fullArgs = @('-c', 'core.quotePath=false') + $Arguments
    $output = & git @fullArgs 2>&1
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
    <# Returns the --stat output as a string, optionally scoped to specific paths #>
    [CmdletBinding()]
    param([string]$BranchA, [string]$BranchB, [string[]]$PathFilter)

    $gitArgs = @('diff', '--stat', $BranchA, $BranchB)
    if ($PathFilter -and $PathFilter.Count -gt 0) {
        $gitArgs += '--'
        $gitArgs += $PathFilter
    }
    $output = Invoke-Git $gitArgs
    if ($null -eq $output) { return "" }
    return ($output -join "`n")
}

function Get-DiffNameStatus {
    <# Returns parsed name-status entries, optionally scoped to specific paths #>
    [CmdletBinding()]
    param([string]$BranchA, [string]$BranchB, [string[]]$PathFilter)

    $gitArgs = @('diff', '--name-status', '-M', $BranchA, $BranchB)
    if ($PathFilter -and $PathFilter.Count -gt 0) {
        $gitArgs += '--'
        $gitArgs += $PathFilter
    }
    $lines = Invoke-Git $gitArgs
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

function Get-DiffNumStat {
    <# Returns parsed numstat entries with insertions/deletions per file #>
    [CmdletBinding()]
    param([string]$BranchA, [string]$BranchB, [string[]]$PathFilter)

    $gitArgs = @('diff', '--numstat', '-M', $BranchA, $BranchB)
    if ($PathFilter -and $PathFilter.Count -gt 0) {
        $gitArgs += '--'
        $gitArgs += $PathFilter
    }
    $lines = Invoke-Git $gitArgs
    if ($null -eq $lines) { return @() }

    $entries = @()
    foreach ($line in $lines) {
        if ($line -match '^(\d+|-)\t(\d+|-)\t(.+)$') {
            $ins = if ($Matches[1] -eq '-') { 0 } else { [int]$Matches[1] }
            $del = if ($Matches[2] -eq '-') { 0 } else { [int]$Matches[2] }
            $pathPart = $Matches[3].Trim()
            $path = $pathPart
            $oldPath = $null
            # Handle {old => new} rename notation
            if ($pathPart -match '(.*)\{(.+?)\s+=>[\s]+(.*?)\}(.*)') {
                $prefix = $Matches[1]
                $oldPart = $Matches[2]
                $newPart = $Matches[3]
                $suffix = $Matches[4]
                $oldPath = ("${prefix}${oldPart}${suffix}" -replace '//', '/')
                $path = ("${prefix}${newPart}${suffix}" -replace '//', '/')
            }
            elseif ($pathPart -match '^(.+?)\s+=>[\s]+(.+)$') {
                $oldPath = $Matches[1].Trim()
                $path = $Matches[2].Trim()
            }
            $entries += [PSCustomObject]@{
                Path       = $path
                OldPath    = $oldPath
                Insertions = $ins
                Deletions  = $del
                Total      = $ins + $del
                Binary     = ($line -match '^-\t-\t')
            }
        }
    }
    return $entries
}

function Get-BulkFileDetails {
    <# Gets line count and last commit info for a list of files on a branch #>
    [CmdletBinding()]
    param(
        [string]$Branch,
        [string[]]$FilePaths
    )

    $details = @{}
    if (-not $FilePaths -or $FilePaths.Count -eq 0) { return $details }
    $i = 0
    foreach ($path in $FilePaths) {
        $i++
        Write-Progress -Activity "Gathering file details ($Branch)" -Status $path -PercentComplete (($i / $FilePaths.Count) * 100)
        # Line count from blob
        $content = Invoke-Git @('show', "${Branch}:${path}")
        $lineCount = if ($null -ne $content) { @($content).Count } else { 0 }

        # Last commit info
        $logOutput = Invoke-Git @('log', '-1', '--format=%ai|||%s', $Branch, '--', $path)
        $date = ''
        $message = ''
        if ($logOutput) {
            $logLine = ($logOutput | Select-Object -First 1)
            $parts = $logLine -split '\|\|\|', 2
            if ($parts.Count -ge 2) {
                $date = $parts[0].Trim() -replace '\s+[\+\-]\d{4}$', ''
                $message = $parts[1].Trim()
                if ($message.Length -gt 60) { $message = $message.Substring(0, 57) + '...' }
            }
        }

        $details[$path] = @{
            LineCount = $lineCount
            Date      = $date
            Message   = $message
        }
    }
    Write-Progress -Activity "Gathering file details ($Branch)" -Completed
    return $details
}

function Get-GitHubBaseUrl {
    <# Derives a browsable GitHub/hosted-git base URL from the origin remote #>
    [CmdletBinding()]
    param()

    $remoteUrl = Invoke-Git @('remote', 'get-url', 'origin')
    if (-not $remoteUrl) { return $null }

    $url = ($remoteUrl | Select-Object -First 1).Trim()

    # SSH: git@github.com:user/repo.git
    if ($url -match '^git@github\.com:(.+?)(?:\.git)?$') {
        return "https://github.com/$($Matches[1])"
    }
    # HTTPS: https://github.com/user/repo.git
    if ($url -match '^https?://github\.com/(.+?)(?:\.git)?$') {
        return "https://github.com/$($Matches[1])"
    }
    # Generic SSH: git@host:user/repo.git
    if ($url -match '^git@([^:]+):(.+?)(?:\.git)?$') {
        return "https://$($Matches[1])/$($Matches[2])"
    }
    # Generic HTTPS
    if ($url -match '^https?://([^/]+)/(.+?)(?:\.git)?$') {
        return "https://$($Matches[1])/$($Matches[2])"
    }

    Write-Log "Could not derive browsable URL from remote: $url" -Level WARN
    return $null
}

function Format-FileRef {
    <# Returns a markdown link: local relative link if file exists in working tree,
       GitHub blob URL for remote-only files, or code span as last resort #>
    [CmdletBinding()]
    param(
        [string]$Path,
        [string]$RepoPath,
        [string]$Branch,
        [string]$GitHubBaseUrl
    )

    $cleanPath = $Path
    if ($cleanPath.StartsWith('"') -and $cleanPath.EndsWith('"')) {
        $cleanPath = $cleanPath.Substring(1, $cleanPath.Length - 2)
    }

    # Try local file first
    $fullPath = Join-Path $RepoPath $cleanPath
    if (Test-Path -LiteralPath $fullPath) {
        $urlPath = $cleanPath -replace '\\', '/' -replace ' ', '%20'
        $displayName = $cleanPath -replace '\|', '\|'
        return "[$displayName]($urlPath)"
    }

    # Fall back to GitHub blob URL for remote-only files
    if ($GitHubBaseUrl -and $Branch) {
        $urlPath = [Uri]::EscapeUriString(($cleanPath -replace '\\', '/'))
        $ghBranch = $Branch -replace '^origin/', ''
        $displayName = $cleanPath -replace '\|', '\|'
        return "[$displayName]($GitHubBaseUrl/blob/$ghBranch/$urlPath)"
    }

    # No link possible
    $escapedPath = $Path -replace '\|', '\|'
    return "``$escapedPath``"
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

function Find-FuzzyRenames {
    <#
    .SYNOPSIS
        For files still unmatched after exact blob matching, detect probable
        renames+edits by comparing basenames.  When two files share the same
        filename (at different paths), compute content similarity between their
        blobs via git diff --numstat.  Searches ALL files on the other branch
        (not just unmatched ones) so it catches cases where the renamed copy
        also exists at the original path as a shared file.
    #>
    [CmdletBinding()]
    param(
        [string[]]$UnmatchedBase,         # paths unique to Base with no blob match
        [hashtable]$BaseFiles,            # path -> blob (all Base files)
        [string[]]$UnmatchedCompare,      # paths unique to CompareTo with no blob match
        [hashtable]$CompareFiles,         # path -> blob (all CompareTo files)
        [int]$MinSimilarityPct = 50       # minimum similarity % to count as a fuzzy match
    )

    Write-Log "Scanning for fuzzy renames among $($UnmatchedBase.Count) base / $($UnmatchedCompare.Count) compare unmatched files" -Level VERBOSE

    if ($UnmatchedBase.Count -eq 0 -and $UnmatchedCompare.Count -eq 0) { return @() }

    # Build basename -> list-of-paths index for ALL files on each branch
    $allCompareByName = @{}
    foreach ($path in $CompareFiles.Keys) {
        $name = [System.IO.Path]::GetFileName($path)
        if (-not $allCompareByName.ContainsKey($name)) {
            $allCompareByName[$name] = [System.Collections.Generic.List[string]]::new()
        }
        $allCompareByName[$name].Add($path)
    }

    $allBaseByName = @{}
    foreach ($path in $BaseFiles.Keys) {
        $name = [System.IO.Path]::GetFileName($path)
        if (-not $allBaseByName.ContainsKey($name)) {
            $allBaseByName[$name] = [System.Collections.Generic.List[string]]::new()
        }
        $allBaseByName[$name].Add($path)
    }

    # Helper: compute similarity between two blobs
    $computeSimilarity = {
        param([string]$BlobA, [string]$BlobB)
        if ($BlobA -eq $BlobB) { return 100 }

        $raw = Invoke-Git @('diff', '--numstat', $BlobA, $BlobB)
        if ($raw) {
            $parts = ($raw | Select-Object -First 1) -split '\t'
            $ins = 0; $del = 0
            if ($parts[0] -ne '-') { $ins = [int]$parts[0] }
            if ($parts[1] -ne '-') { $del = [int]$parts[1] }
            $totalChanged = $ins + $del
            $aLineCount  = @(Invoke-Git @('cat-file', '-p', $BlobA)).Count
            $bLineCount = @(Invoke-Git @('cat-file', '-p', $BlobB)).Count
            $maxLines = [Math]::Max($aLineCount, $bLineCount)
            if ($maxLines -eq 0) { $maxLines = 1 }
            $sim = [Math]::Round((1 - ($totalChanged / (2 * $maxLines))) * 100)
            if ($sim -lt 0) { $sim = 0 }
            return $sim
        }
        return 0
    }

    $matches = @()

    # Match unmatched Base files against ALL CompareTo files (at different paths)
    foreach ($basePath in $UnmatchedBase) {
        $baseName = [System.IO.Path]::GetFileName($basePath)
        if (-not $allCompareByName.ContainsKey($baseName)) { continue }

        $baseBlob = $BaseFiles[$basePath]
        $bestSim = -1; $bestMatch = $null

        foreach ($comparePath in $allCompareByName[$baseName]) {
            if ($comparePath -eq $basePath) { continue }  # skip same path (shared file)
            $compareBlob = $CompareFiles[$comparePath]
            $sim = & $computeSimilarity $baseBlob $compareBlob
            Write-Log "  Fuzzy: $basePath <-> $comparePath  similarity=$sim%" -Level DEBUG
            if ($sim -gt $bestSim) { $bestSim = $sim; $bestMatch = $comparePath }
        }

        if ($bestSim -ge $MinSimilarityPct -and $bestMatch) {
            $matches += [PSCustomObject]@{
                BasePath     = $basePath
                ComparePath  = $bestMatch
                Similarity   = $bestSim
                Type         = 'FuzzyRename'
            }
            Write-Log "Fuzzy match: $basePath -> $bestMatch ($bestSim%)" -Level VERBOSE
        }
    }

    # Match unmatched CompareTo files against ALL Base files (at different paths)
    # Skip files already matched from the Base side above
    $alreadyMatchedCompare = [System.Collections.Generic.HashSet[string]]::new(
        [string[]]@($matches | ForEach-Object { $_.ComparePath }))

    foreach ($comparePath in $UnmatchedCompare) {
        if ($alreadyMatchedCompare.Contains($comparePath)) { continue }
        $compareName = [System.IO.Path]::GetFileName($comparePath)
        if (-not $allBaseByName.ContainsKey($compareName)) { continue }

        $compareBlob = $CompareFiles[$comparePath]
        $bestSim = -1; $bestMatch = $null

        foreach ($baseCandidate in $allBaseByName[$compareName]) {
            if ($baseCandidate -eq $comparePath) { continue }
            $baseBlob = $BaseFiles[$baseCandidate]
            $sim = & $computeSimilarity $baseBlob $compareBlob
            Write-Log "  Fuzzy: $comparePath <-> $baseCandidate  similarity=$sim%" -Level DEBUG
            if ($sim -gt $bestSim) { $bestSim = $sim; $bestMatch = $baseCandidate }
        }

        if ($bestSim -ge $MinSimilarityPct -and $bestMatch) {
            $matches += [PSCustomObject]@{
                BasePath     = $bestMatch
                ComparePath  = $comparePath
                Similarity   = $bestSim
                Type         = 'FuzzyRename'
            }
            Write-Log "Fuzzy match: $comparePath -> $bestMatch ($bestSim%)" -Level VERBOSE
        }
    }

    Write-Log "Found $($matches.Count) fuzzy rename matches" -Level VERBOSE
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

    # Emoji indicators for visual review
    $emojiRed = [char]::ConvertFromUtf32(0x1F534)
    $emojiYellow = [char]::ConvertFromUtf32(0x1F7E1)
    $emojiGreen = [char]::ConvertFromUtf32(0x1F7E2)
    $emojiWhite = [char]::ConvertFromUtf32(0x26AA)
    $arrow = [char]0x2192

    # YAML Frontmatter
    [void]$sb.AppendLine("---")
    [void]$sb.AppendLine("created: $(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')")
    [void]$sb.AppendLine("method: content-based (blob hash comparison + diff)")
    [void]$sb.AppendLine("base: $($Data.Base)")
    [void]$sb.AppendLine("compare_to: $($Data.CompareTo)")
    [void]$sb.AppendLine("repository: $($Data.RepoPath)")
    [void]$sb.AppendLine("local_branch: $($Data.LocalBranch)")
    [void]$sb.AppendLine("git_version: $($Data.GitVersion)")
    if ($Data.IncludePath) {
        [void]$sb.AppendLine("scoped_to: [$($Data.IncludePath -join ', ')]")
    }
    [void]$sb.AppendLine("---")
    [void]$sb.AppendLine("")
    [void]$sb.AppendLine("# Git Branch Comparison Report")
    [void]$sb.AppendLine("")

    # Commit counts
    [void]$sb.AppendLine("---")
    [void]$sb.AppendLine("")
    [void]$sb.AppendLine("## Commit Ancestry")
    [void]$sb.AppendLine("")
    if ($Data.CommitCounts.Ahead -ge 0) {
        [void]$sb.AppendLine("| Metric | Count |")
        [void]$sb.AppendLine("|---|---|")
        [void]$sb.AppendLine("| ``$($Data.CompareTo)`` ahead of ``$($Data.Base)`` | $($Data.CommitCounts.Ahead) |")
        [void]$sb.AppendLine("| ``$($Data.CompareTo)`` behind ``$($Data.Base)`` | $($Data.CommitCounts.Behind) |")
        if ($Data.CommitCounts.Ahead -eq 0 -and $Data.CommitCounts.Behind -eq 0) {
            [void]$sb.AppendLine("")
            [void]$sb.AppendLine("> Branches point to the same commit.")
        }
        elseif ($Data.CommitCounts.Ahead -eq 0) {
            [void]$sb.AppendLine("")
            [void]$sb.AppendLine("> ``$($Data.CompareTo)`` is an ancestor (subset) of ``$($Data.Base)`` by commit history.")
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
    [void]$sb.AppendLine("| Total files on ``$($Data.Base)`` | $($Data.BaseFileCount) |")
    [void]$sb.AppendLine("| Total files on ``$($Data.CompareTo)`` | $($Data.CompareFileCount) |")
    [void]$sb.AppendLine("| Files at shared paths | $($Data.SharedIdentical + $Data.SharedModified) |")
    [void]$sb.AppendLine("| — Identical content | $($Data.SharedIdentical) |")
    [void]$sb.AppendLine("| — Modified content | $($Data.SharedModified) |")
    [void]$sb.AppendLine("| Unique to ``$($Data.Base)`` | $($Data.UniqueToBase) |")
    [void]$sb.AppendLine("| — Renames/moves (identical content elsewhere) | $($Data.RenamesOnBase) |")
    [void]$sb.AppendLine("| — Probable renames with edits (fuzzy match) | $($Data.FuzzyRenames.Count) |")
    [void]$sb.AppendLine("| — Truly unique (no content match) | $($Data.TrulyUniqueToBase) |")
    [void]$sb.AppendLine("| Unique to ``$($Data.CompareTo)`` | $($Data.UniqueToCompare) |")
    [void]$sb.AppendLine("| — Renames/moves (identical content elsewhere) | $($Data.RenamesOnCompare) |")
    [void]$sb.AppendLine("| — Truly unique (no content match) | $($Data.TrulyUniqueToCompare) |")
    [void]$sb.AppendLine("")

    # Content verdict (renames are harmless — only truly unique files and modified content matter)
    $hasTrueContentDiff = ($Data.SharedModified -gt 0) -or ($Data.TrulyUniqueToBase -gt 0) -or ($Data.TrulyUniqueToCompare -gt 0)
    $hasOnlyRenames = (-not $hasTrueContentDiff) -and (($Data.RenamesOnBase + $Data.RenamesOnCompare) -gt 0)

    if ($Data.SharedModified -eq 0 -and $Data.UniqueToBase -eq 0 -and $Data.UniqueToCompare -eq 0) {
        [void]$sb.AppendLine("> **Verdict: Branches are content-identical.** Safe to delete ``$($Data.CompareTo)``.")
    }
    elseif ($hasOnlyRenames) {
        [void]$sb.AppendLine("> **Verdict: Branches differ only by file renames/moves.** All content exists on both branches — just at different paths. Safe to delete ``$($Data.CompareTo)`` if the path layout on ``$($Data.Base)`` is preferred.")
    }
    elseif (-not $hasTrueContentDiff -and $Data.UniqueToBase -eq 0 -and $Data.UniqueToCompare -eq 0) {
        [void]$sb.AppendLine("> **Verdict: Branches are content-identical.** Safe to delete ``$($Data.CompareTo)``.")
    }
    elseif ($Data.SharedModified -eq 0 -and $Data.TrulyUniqueToCompare -eq 0 -and $Data.TrulyUniqueToBase -gt 0) {
        [void]$sb.AppendLine("> **Verdict: ``$($Data.CompareTo)`` is a content-subset of ``$($Data.Base)``.** All ``$($Data.CompareTo)`` content exists on ``$($Data.Base)`` (possibly at different paths). Safe to delete ``$($Data.CompareTo)``.")
    }
    elseif ($Data.SharedModified -eq 0 -and $Data.TrulyUniqueToBase -eq 0 -and $Data.TrulyUniqueToCompare -gt 0) {
        [void]$sb.AppendLine("> **Verdict: ``$($Data.Base)`` is a content-subset of ``$($Data.CompareTo)``.** ``$($Data.CompareTo)`` has additional unique files.")
    }
    else {
        [void]$sb.AppendLine("> **Verdict: Branches have divergent content.** Review details below before deleting.")
    }
    [void]$sb.AppendLine("")

    # Diff stat (sorted table with indicators)
    [void]$sb.AppendLine("---")
    [void]$sb.AppendLine("")
    [void]$sb.AppendLine("## Diff Stat")
    [void]$sb.AppendLine("")
    [void]$sb.AppendLine("Changes from ``$($Data.Base)`` to ``$($Data.CompareTo)``, sorted by severity.")
    [void]$sb.AppendLine("")
    if ($Data.NumStat -and @($Data.NumStat).Count -gt 0) {
        # Build a status map from NameStatus so we know which branch each file belongs to
        $fileStatusMap = @{}
        foreach ($ns in $Data.NameStatus) {
            $fileStatusMap[$ns.Path] = $ns.Status.Substring(0,1)
            if ($ns.OldPath) { $fileStatusMap[$ns.OldPath] = 'D' }
        }

        # Assign severity indicator + reason based on status and size
        # Severity rank: 1=red (review), 2=yellow (moderate), 3=green (minor), 4=white (no change)
        $annotated = foreach ($entry in $Data.NumStat) {
            $fStatus = if ($fileStatusMap.ContainsKey($entry.Path)) { $fileStatusMap[$entry.Path] } else { 'M' }

            if ($fStatus -eq 'R' -and $entry.Total -eq 0) {
                $indicator = $emojiWhite; $reason = 'rename only'; $sevRank = 4
            }
            elseif ($fStatus -eq 'R' -and $entry.Total -gt 0) {
                # Renamed + modified content
                if ($entry.Total -ge 100) { $indicator = $emojiRed; $reason = "renamed + $($entry.Total) lines changed"; $sevRank = 1 }
                elseif ($entry.Total -ge 20) { $indicator = $emojiYellow; $reason = "renamed + $($entry.Total) lines changed"; $sevRank = 2 }
                else { $indicator = $emojiGreen; $reason = "renamed + $($entry.Total) lines changed"; $sevRank = 3 }
            }
            elseif ($fStatus -eq 'D') {
                # Only on Base — would be lost if Base is deleted; full severity
                if ($entry.Total -ge 100) { $indicator = $emojiRed; $reason = "only on $($Data.Base), $($entry.Deletions) lines lost"; $sevRank = 1 }
                elseif ($entry.Total -ge 20) { $indicator = $emojiYellow; $reason = "only on $($Data.Base), $($entry.Deletions) lines lost"; $sevRank = 2 }
                elseif ($entry.Total -gt 0) { $indicator = $emojiGreen; $reason = "only on $($Data.Base), $($entry.Deletions) lines lost"; $sevRank = 3 }
                else { $indicator = $emojiWhite; $reason = "only on $($Data.Base), empty"; $sevRank = 4 }
            }
            elseif ($fStatus -eq 'A') {
                # New on CompareTo — safe (already on target branch); cap at yellow
                if ($entry.Total -ge 100) { $indicator = $emojiYellow; $reason = "new on $($Data.CompareTo), $($entry.Insertions) lines"; $sevRank = 2 }
                elseif ($entry.Total -ge 20) { $indicator = $emojiGreen; $reason = "new on $($Data.CompareTo), $($entry.Insertions) lines"; $sevRank = 3 }
                elseif ($entry.Total -gt 0) { $indicator = $emojiGreen; $reason = "new on $($Data.CompareTo), $($entry.Insertions) lines"; $sevRank = 3 }
                else { $indicator = $emojiWhite; $reason = "new empty file on $($Data.CompareTo)"; $sevRank = 4 }
            }
            else {
                # Modified — full severity by size
                if ($entry.Total -ge 100) { $indicator = $emojiRed; $reason = "modified, $($entry.Total) lines changed"; $sevRank = 1 }
                elseif ($entry.Total -ge 20) { $indicator = $emojiYellow; $reason = "modified, $($entry.Total) lines changed"; $sevRank = 2 }
                elseif ($entry.Total -gt 0) { $indicator = $emojiGreen; $reason = "modified, $($entry.Total) lines changed"; $sevRank = 3 }
                else { $indicator = $emojiWhite; $reason = 'no content change'; $sevRank = 4 }
            }

            # Change direction rank: 1=deletions only, 2=mixed, 3=additions only, 4=no change
            $changeRank = if ($entry.Deletions -gt 0 -and $entry.Insertions -eq 0) { 1 }
                          elseif ($entry.Deletions -gt 0 -and $entry.Insertions -gt 0) { 2 }
                          elseif ($entry.Insertions -gt 0 -and $entry.Deletions -eq 0) { 3 }
                          else { 4 }

            [PSCustomObject]@{
                Entry      = $entry
                Status     = $fStatus
                Indicator  = $indicator
                Reason     = $reason
                SevRank    = $sevRank
                ChangeRank = $changeRank
            }
        }

        $sorted = @($annotated | Sort-Object SevRank, ChangeRank, { -($_.Entry.Total) })
        [void]$sb.AppendLine("| # | File | +Lines | -Lines | Total | |")
        [void]$sb.AppendLine("|--:|---|--:|--:|--:|---|")
        $rank = 0
        foreach ($item in $sorted) {
            $rank++
            $entry = $item.Entry
            $fBranch = if ($item.Status -eq 'D') { $Data.Base } else { $Data.CompareTo }
            $fileRef = Format-FileRef -Path $entry.Path -RepoPath $Data.RepoPath -Branch $fBranch -GitHubBaseUrl $Data.GitHubBaseUrl
            [void]$sb.AppendLine("| $rank | $fileRef | $($entry.Insertions) | $($entry.Deletions) | $($entry.Total) | $($item.Indicator) ($($item.Reason)) |")
        }
        [void]$sb.AppendLine("")
        $totalIns = ($sorted | Measure-Object -Property { $_.Entry.Insertions } -Sum).Sum
        $totalDel = ($sorted | Measure-Object -Property { $_.Entry.Deletions } -Sum).Sum
        [void]$sb.AppendLine("**$($sorted.Count) files changed, $totalIns insertions(+), $totalDel deletions(-)**")
    }
    else {
        [void]$sb.AppendLine("No file changes detected.")
    }
    [void]$sb.AppendLine("")

    # Name-status table with rich details
    if ($Data.NameStatus.Count -gt 0) {
        [void]$sb.AppendLine("---")
        [void]$sb.AppendLine("")
        [void]$sb.AppendLine("## File Change Summary (name-status)")
        [void]$sb.AppendLine("")

        $grouped = $Data.NameStatus | Group-Object { $_.Status.Substring(0,1) }
        $statusLabels = @{
            'A' = "New on ``$($Data.CompareTo)`` (not on ``$($Data.Base)``)"
            'D' = "Only on ``$($Data.Base)`` (not on ``$($Data.CompareTo)``)"
            'M' = 'Modified'
            'R' = "Renamed/Moved (``$($Data.Base)`` $arrow ``$($Data.CompareTo)``)"
        }

        foreach ($group in $grouped | Sort-Object Name) {
            $label = if ($statusLabels.ContainsKey($group.Name)) { $statusLabels[$group.Name] } else { $group.Name }
            [void]$sb.AppendLine("### $label ($($group.Count) files)")
            [void]$sb.AppendLine("")

            switch ($group.Name) {
                'A' {
                    [void]$sb.AppendLine("| File | Lines | Last Modified | Commit |")
                    [void]$sb.AppendLine("|---|--:|---|---|")
                    foreach ($item in $group.Group) {
                        $fileRef = Format-FileRef -Path $item.Path -RepoPath $Data.RepoPath -Branch $Data.CompareTo -GitHubBaseUrl $Data.GitHubBaseUrl
                        $d = if ($Data.FileDetails.ContainsKey("A:$($item.Path)")) { $Data.FileDetails["A:$($item.Path)"] } else { $null }
                        $lc = if ($d) { $d.LineCount } else { [char]0x2014 }
                        $dt = if ($d -and $d.Date) { $d.Date } else { [char]0x2014 }
                        $msg = if ($d -and $d.Message) { $d.Message -replace '\|', '\|' } else { [char]0x2014 }
                        [void]$sb.AppendLine("| $fileRef | $lc | $dt | $msg |")
                    }
                }
                'D' {
                    [void]$sb.AppendLine("| File | Lines | Last Modified | Commit |")
                    [void]$sb.AppendLine("|---|--:|---|---|")
                    foreach ($item in $group.Group) {
                        $fileRef = Format-FileRef -Path $item.Path -RepoPath $Data.RepoPath -Branch $Data.Base -GitHubBaseUrl $Data.GitHubBaseUrl
                        $d = if ($Data.FileDetails.ContainsKey("D:$($item.Path)")) { $Data.FileDetails["D:$($item.Path)"] } else { $null }
                        $lc = if ($d) { $d.LineCount } else { [char]0x2014 }
                        $dt = if ($d -and $d.Date) { $d.Date } else { [char]0x2014 }
                        $msg = if ($d -and $d.Message) { $d.Message -replace '\|', '\|' } else { [char]0x2014 }
                        [void]$sb.AppendLine("| $fileRef | $lc | $dt | $msg |")
                    }
                }
                'M' {
                    [void]$sb.AppendLine("| File | +Lines | -Lines |")
                    [void]$sb.AppendLine("|---|--:|--:|")
                    foreach ($item in $group.Group) {
                        $fileRef = Format-FileRef -Path $item.Path -RepoPath $Data.RepoPath -Branch $Data.CompareTo -GitHubBaseUrl $Data.GitHubBaseUrl
                        $ns = $Data.NumStat | Where-Object { $_.Path -eq $item.Path } | Select-Object -First 1
                        $ins = if ($ns) { $ns.Insertions } else { [char]0x2014 }
                        $del = if ($ns) { $ns.Deletions } else { [char]0x2014 }
                        [void]$sb.AppendLine("| $fileRef | $ins | $del |")
                    }
                }
                'R' {
                    [void]$sb.AppendLine("| On ``$($Data.Base)`` | On ``$($Data.CompareTo)`` |")
                    [void]$sb.AppendLine("|---|---|")
                    foreach ($item in $group.Group) {
                        $oldRef = Format-FileRef -Path $item.OldPath -RepoPath $Data.RepoPath -Branch $Data.Base -GitHubBaseUrl $Data.GitHubBaseUrl
                        $newRef = Format-FileRef -Path $item.Path -RepoPath $Data.RepoPath -Branch $Data.CompareTo -GitHubBaseUrl $Data.GitHubBaseUrl
                        [void]$sb.AppendLine("| $oldRef | $newRef |")
                    }
                }
                default {
                    [void]$sb.AppendLine("| File | Details |")
                    [void]$sb.AppendLine("|---|---|")
                    foreach ($item in $group.Group) {
                        [void]$sb.AppendLine("| ``$($item.Path)`` | |")
                    }
                }
            }
            [void]$sb.AppendLine("")
        }
    }

    # Unique files with rename detection (sorted: truly unique first, renames last)
    if ($Data.UniqueToBase -gt 0 -or $Data.UniqueToCompare -gt 0) {
        [void]$sb.AppendLine("---")
        [void]$sb.AppendLine("")
        [void]$sb.AppendLine("## Unique Files & Rename Detection")
        [void]$sb.AppendLine("")

        if ($Data.UniqueToBaseFiles.Count -gt 0) {
            [void]$sb.AppendLine("### Files only on ``$($Data.Base)`` ($($Data.UniqueToBase))")
            [void]$sb.AppendLine("")
            [void]$sb.AppendLine("$emojiRed = truly unique | $emojiYellow = probable rename with edits | $emojiGreen = identical content elsewhere (rename/move)")
            [void]$sb.AppendLine("")
            [void]$sb.AppendLine("| | File | Match on ``$($Data.CompareTo)`` |")
            [void]$sb.AppendLine("|---|---|---|")
            # Sort: truly unique first (0), then fuzzy (1), then exact blob match (2)
            $sortedPaths = @($Data.UniqueToBaseFiles.Keys | Sort-Object | Sort-Object {
                $p = $_
                if ($Data.BaseBlobMatches | Where-Object { $_.Path -eq $p }) { 2 }
                elseif ($Data.FuzzyRenames | Where-Object { $_.BasePath -eq $p }) { 1 }
                else { 0 }
            })
            foreach ($path in $sortedPaths) {
                $match = $Data.BaseBlobMatches | Where-Object { $_.Path -eq $path }
                $fuzzy = $Data.FuzzyRenames | Where-Object { $_.BasePath -eq $path }
                if ($match) {
                    $matchPaths = ($match.MatchPaths | ForEach-Object { Format-FileRef -Path $_ -RepoPath $Data.RepoPath -Branch $Data.CompareTo -GitHubBaseUrl $Data.GitHubBaseUrl }) -join ', '
                    $fileRef = Format-FileRef -Path $path -RepoPath $Data.RepoPath -Branch $Data.Base -GitHubBaseUrl $Data.GitHubBaseUrl
                    [void]$sb.AppendLine("| $emojiGreen | $fileRef | Identical content at: $matchPaths |")
                }
                elseif ($fuzzy) {
                    $matchRef = Format-FileRef -Path $fuzzy.ComparePath -RepoPath $Data.RepoPath -Branch $Data.CompareTo -GitHubBaseUrl $Data.GitHubBaseUrl
                    $fileRef = Format-FileRef -Path $path -RepoPath $Data.RepoPath -Branch $Data.Base -GitHubBaseUrl $Data.GitHubBaseUrl
                    [void]$sb.AppendLine("| $emojiYellow | $fileRef | Probable rename+edit ($($fuzzy.Similarity)% similar): $matchRef |")
                }
                else {
                    $fileRef = Format-FileRef -Path $path -RepoPath $Data.RepoPath -Branch $Data.Base -GitHubBaseUrl $Data.GitHubBaseUrl
                    [void]$sb.AppendLine("| $emojiRed | $fileRef | **No match — truly unique to ``$($Data.Base)``** |")
                }
            }
            [void]$sb.AppendLine("")
        }

        if ($Data.UniqueToCompareFiles.Count -gt 0) {
            [void]$sb.AppendLine("### Files only on ``$($Data.CompareTo)`` ($($Data.UniqueToCompare))")
            [void]$sb.AppendLine("")
            [void]$sb.AppendLine("$emojiRed = truly unique | $emojiYellow = probable rename with edits | $emojiGreen = identical content elsewhere (rename/move)")
            [void]$sb.AppendLine("")
            [void]$sb.AppendLine("| | File | Match on ``$($Data.Base)`` |")
            [void]$sb.AppendLine("|---|---|---|")
            # Sort: truly unique first (0), then fuzzy (1), then exact blob match (2)
            $sortedPaths = @($Data.UniqueToCompareFiles.Keys | Sort-Object | Sort-Object {
                $p = $_
                if ($Data.CompareBlobMatches | Where-Object { $_.Path -eq $p }) { 2 }
                elseif ($Data.FuzzyRenames | Where-Object { $_.ComparePath -eq $p }) { 1 }
                else { 0 }
            })
            foreach ($path in $sortedPaths) {
                $match = $Data.CompareBlobMatches | Where-Object { $_.Path -eq $path }
                $fuzzy = $Data.FuzzyRenames | Where-Object { $_.ComparePath -eq $path }
                if ($match) {
                    $matchPaths = ($match.MatchPaths | ForEach-Object { Format-FileRef -Path $_ -RepoPath $Data.RepoPath -Branch $Data.Base -GitHubBaseUrl $Data.GitHubBaseUrl }) -join ', '
                    $fileRef = Format-FileRef -Path $path -RepoPath $Data.RepoPath -Branch $Data.CompareTo -GitHubBaseUrl $Data.GitHubBaseUrl
                    [void]$sb.AppendLine("| $emojiGreen | $fileRef | Identical content at: $matchPaths |")
                }
                elseif ($fuzzy) {
                    $matchRef = Format-FileRef -Path $fuzzy.BasePath -RepoPath $Data.RepoPath -Branch $Data.Base -GitHubBaseUrl $Data.GitHubBaseUrl
                    $fileRef = Format-FileRef -Path $path -RepoPath $Data.RepoPath -Branch $Data.CompareTo -GitHubBaseUrl $Data.GitHubBaseUrl
                    [void]$sb.AppendLine("| $emojiYellow | $fileRef | Probable rename+edit ($($fuzzy.Similarity)% similar): $matchRef |")
                }
                else {
                    $fileRef = Format-FileRef -Path $path -RepoPath $Data.RepoPath -Branch $Data.CompareTo -GitHubBaseUrl $Data.GitHubBaseUrl
                    [void]$sb.AppendLine("| $emojiRed | $fileRef | **No match — truly unique to ``$($Data.CompareTo)``** |")
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
        [void]$sb.AppendLine("Changes shown as ``$($Data.Base)`` $arrow ``$($Data.CompareTo)``.")
        [void]$sb.AppendLine("")

        if ($Data.ContentChunks.Count -gt 0) {
            foreach ($path in $Data.SharedModifiedList | Sort-Object) {
                $fileRef = Format-FileRef -Path $path -RepoPath $Data.RepoPath -Branch $Data.CompareTo -GitHubBaseUrl $Data.GitHubBaseUrl
                [void]$sb.AppendLine("### $fileRef")
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

    # Fuzzy renames with different content (moved + edited files)
    if ($Data.FuzzyRenames.Count -gt 0) {
        [void]$sb.AppendLine("---")
        [void]$sb.AppendLine("")
        [void]$sb.AppendLine("## Probable Renames with Edits ($($Data.FuzzyRenames.Count) pairs)")
        [void]$sb.AppendLine("")
        [void]$sb.AppendLine("These files share the same filename but exist at different paths with different content.")
        [void]$sb.AppendLine("Matched by filename; similarity computed from blob content.")
        [void]$sb.AppendLine("")

        if ($Data.FuzzyChunks.Count -gt 0) {
            foreach ($fr in $Data.FuzzyRenames | Sort-Object { $_.Similarity }) {
                $baseRef = Format-FileRef -Path $fr.BasePath -RepoPath $Data.RepoPath -Branch $Data.Base -GitHubBaseUrl $Data.GitHubBaseUrl
                $compareRef = Format-FileRef -Path $fr.ComparePath -RepoPath $Data.RepoPath -Branch $Data.CompareTo -GitHubBaseUrl $Data.GitHubBaseUrl
                [void]$sb.AppendLine("### $baseRef $arrow $compareRef ($($fr.Similarity)% similar)")
                [void]$sb.AppendLine("")
                if ($Data.FuzzyChunks.ContainsKey($fr.BasePath)) {
                    [void]$sb.AppendLine('```diff')
                    [void]$sb.AppendLine($Data.FuzzyChunks[$fr.BasePath])
                    [void]$sb.AppendLine('```')
                }
                else {
                    [void]$sb.AppendLine("(diff not available)")
                }
                [void]$sb.AppendLine("")
            }
        }
        else {
            [void]$sb.AppendLine("| Base Path | CompareTo Path | Similarity |")
            [void]$sb.AppendLine("|---|---|---|")
            foreach ($fr in $Data.FuzzyRenames | Sort-Object { $_.Similarity }) {
                [void]$sb.AppendLine("| ``$($fr.BasePath)`` | ``$($fr.ComparePath)`` | $($fr.Similarity)% |")
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
    [void]$sb.AppendLine("Base:           $($Data.Base)")
    [void]$sb.AppendLine("CompareTo:      $($Data.CompareTo)")
    [void]$sb.AppendLine("Repository:     $($Data.RepoPath)")
    [void]$sb.AppendLine("Git version:    $($Data.GitVersion)")
    if ($Data.IncludePath) {
        [void]$sb.AppendLine("Scoped to:      $($Data.IncludePath -join ', ')")
    }
    [void]$sb.AppendLine("")

    [void]$sb.AppendLine("COMMIT ANCESTRY")
    [void]$sb.AppendLine("-" * 40)
    if ($Data.CommitCounts.Ahead -ge 0) {
        [void]$sb.AppendLine("$($Data.CompareTo) ahead of $($Data.Base):  $($Data.CommitCounts.Ahead)")
        [void]$sb.AppendLine("$($Data.CompareTo) behind $($Data.Base):    $($Data.CommitCounts.Behind)")
    }
    else {
        [void]$sb.AppendLine("Could not determine (no shared history)")
    }
    [void]$sb.AppendLine("NOTE: With rewritten history, commit counts may be misleading.")
    [void]$sb.AppendLine("")

    [void]$sb.AppendLine("FILE TREE SUMMARY")
    [void]$sb.AppendLine("-" * 40)
    [void]$sb.AppendLine("Total files on $($Data.Base):    $($Data.BaseFileCount)")
    [void]$sb.AppendLine("Total files on $($Data.CompareTo): $($Data.CompareFileCount)")
    [void]$sb.AppendLine("Shared paths identical: $($Data.SharedIdentical)")
    [void]$sb.AppendLine("Shared paths modified:  $($Data.SharedModified)")
    [void]$sb.AppendLine("Unique to $($Data.Base):         $($Data.UniqueToBase) (renames: $($Data.RenamesOnBase), fuzzy: $($Data.FuzzyRenames.Count), truly unique: $($Data.TrulyUniqueToBase))")
    [void]$sb.AppendLine("Unique to $($Data.CompareTo):      $($Data.UniqueToCompare) (renames: $($Data.RenamesOnCompare), truly unique: $($Data.TrulyUniqueToCompare))")
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
        [void]$sb.AppendLine("FILES ONLY ON $($Data.Base) ($($Data.UniqueToBase))")
        [void]$sb.AppendLine("-" * 40)
        foreach ($path in $Data.UniqueToBaseFiles.Keys | Sort-Object) {
            $match = $Data.BaseBlobMatches | Where-Object { $_.Path -eq $path }
            $fuzzy = $Data.FuzzyRenames | Where-Object { $_.BasePath -eq $path }
            if ($match) {
                [void]$sb.AppendLine("  $path  -> identical content at: $($match.MatchPaths -join ', ')")
            }
            elseif ($fuzzy) {
                [void]$sb.AppendLine("  $path  -> probable rename+edit ($($fuzzy.Similarity)% similar): $($fuzzy.ComparePath)")
            }
            else {
                [void]$sb.AppendLine("  $path  [TRULY UNIQUE]")
            }
        }
        [void]$sb.AppendLine("")
    }

    if ($Data.UniqueToCompareFiles.Count -gt 0) {
        [void]$sb.AppendLine("FILES ONLY ON $($Data.CompareTo) ($($Data.UniqueToCompare))")
        [void]$sb.AppendLine("-" * 40)
        foreach ($path in $Data.UniqueToCompareFiles.Keys | Sort-Object) {
            $match = $Data.CompareBlobMatches | Where-Object { $_.Path -eq $path }
            $fuzzy = $Data.FuzzyRenames | Where-Object { $_.ComparePath -eq $path }
            if ($match) {
                [void]$sb.AppendLine("  $path  -> identical content at: $($match.MatchPaths -join ', ')")
            }
            elseif ($fuzzy) {
                [void]$sb.AppendLine("  $path  -> probable rename+edit ($($fuzzy.Similarity)% similar): $($fuzzy.BasePath)")
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

    if ($Data.FuzzyRenames.Count -gt 0) {
        [void]$sb.AppendLine("PROBABLE RENAMES WITH EDITS ($($Data.FuzzyRenames.Count))")
        [void]$sb.AppendLine("-" * 40)
        foreach ($fr in $Data.FuzzyRenames | Sort-Object { $_.Similarity }) {
            [void]$sb.AppendLine("")
            [void]$sb.AppendLine("  $($fr.BasePath) -> $($fr.ComparePath) ($($fr.Similarity)% similar)")
            if ($Data.FuzzyChunks.ContainsKey($fr.BasePath)) {
                foreach ($line in ($Data.FuzzyChunks[$fr.BasePath] -split "`n")) {
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
    $safeBase = ($Base -replace '[/\\:*?"<>|]', '-')
    $safeCompareTo = ($CompareTo -replace '[/\\:*?"<>|]', '-')
    if (-not $OutputPath) {
        $ext = if ($Format -eq 'Markdown') { 'md' } else { 'txt' }
        $OutputPath = Join-Path $RepoPath "branch-compare-$safeBase-vs-$safeCompareTo-$timestamp.$ext"
    }
    if (-not $LogPath) {
        $LogPath = Join-Path $RepoPath "branch-compare-$safeBase-vs-$safeCompareTo-$timestamp.log"
    }
    $script:LogFile = $LogPath

    Write-Log "Starting branch comparison: $Base vs $CompareTo"
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

    # Resolve GitHub browsable URL for remote file links
    $gitHubBaseUrl = Get-GitHubBaseUrl
    if ($gitHubBaseUrl) {
        Write-Log "GitHub base URL: $gitHubBaseUrl" -Level VERBOSE
    } else {
        Write-Log "No browsable remote URL detected; remote files will not be hyperlinked" -Level WARN
    }

    # Validate branches
    Write-Log "Validating branches..." -Level VERBOSE
    if (-not (Test-BranchExists $Base)) {
        throw "Base branch '$Base' does not exist. Run 'git fetch' first for remote branches."
    }
    if (-not (Test-BranchExists $CompareTo)) {
        throw "CompareTo branch '$CompareTo' does not exist. Run 'git fetch' first for remote branches."
    }

    # 1. Commit ancestry
    Write-Log "Calculating commit counts..." -Level VERBOSE
    $commitCounts = Get-CommitCounts -BranchA $Base -BranchB $CompareTo

    # 2. File trees
    Write-Log "Building file trees..." -Level VERBOSE
    $baseFilesAll = Get-BranchFiles -Branch $Base
    $compareFilesAll = Get-BranchFiles -Branch $CompareTo

    # 2a. Apply IncludePath filter (keep unfiltered copies for rename detection across scopes)
    if ($IncludePath -and $IncludePath.Count -gt 0) {
        Write-Log "Filtering file trees with IncludePath: $($IncludePath -join ', ')" -Level VERBOSE

        $filterFiles = {
            param([hashtable]$Files, [string[]]$Patterns)
            $filtered = @{}
            foreach ($path in $Files.Keys) {
                foreach ($pattern in $Patterns) {
                    if ($path -like $pattern) {
                        $filtered[$path] = $Files[$path]
                        break
                    }
                }
            }
            return $filtered
        }

        $baseFiles = & $filterFiles $baseFilesAll $IncludePath
        $compareFiles = & $filterFiles $compareFilesAll $IncludePath
        Write-Log "After filter: Base=$($baseFiles.Count) files, Compare=$($compareFiles.Count) files" -Level VERBOSE
    }
    else {
        $baseFiles = $baseFilesAll
        $compareFiles = $compareFilesAll
    }

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

    # 5. Rename detection via blob hash (use ALL files from both branches for cross-scope matching)
    Write-Log "Detecting renames via blob hash matching..." -Level VERBOSE
    $baseBlobMatches = @(Find-BlobMatches -UniqueFiles $uniqueToBase -OtherBranchFiles $compareFilesAll)
    $compareBlobMatches = @(Find-BlobMatches -UniqueFiles $uniqueToCompare -OtherBranchFiles $baseFilesAll)
    $script:Telemetry.Renames = $baseBlobMatches.Count + $compareBlobMatches.Count

    # 5a. Compute truly unique files (unique path AND no blob match = real content difference)
    $trulyUniqueToBase = @($uniqueToBase.Keys | Where-Object {
        $path = $_; -not ($baseBlobMatches | Where-Object { $_.Path -eq $path })
    })
    $trulyUniqueToCompare = @($uniqueToCompare.Keys | Where-Object {
        $path = $_; -not ($compareBlobMatches | Where-Object { $_.Path -eq $path })
    })
    $renamesOnBase = $uniqueToBase.Count - $trulyUniqueToBase.Count
    $renamesOnCompare = $uniqueToCompare.Count - $trulyUniqueToCompare.Count

    Write-Log "Truly unique: Base=$($trulyUniqueToBase.Count) Compare=$($trulyUniqueToCompare.Count) Renames=$($renamesOnBase + $renamesOnCompare)" -Level VERBOSE

    # 5b. Fuzzy rename detection (same filename, different path, edited content)
    Write-Log "Detecting fuzzy renames (same filename, edited content)..." -Level VERBOSE
    $fuzzyRenames = @(Find-FuzzyRenames `
        -UnmatchedBase $trulyUniqueToBase `
        -BaseFiles $baseFilesAll `
        -UnmatchedCompare $trulyUniqueToCompare `
        -CompareFiles $compareFilesAll)
    $script:Telemetry.FuzzyRenames = $fuzzyRenames.Count

    # 5c. Recompute truly unique after fuzzy matching
    $fuzzyBasePaths = @($fuzzyRenames | ForEach-Object { $_.BasePath })
    $fuzzyComparePaths = @($fuzzyRenames | ForEach-Object { $_.ComparePath })
    $trulyUniqueToBase = @($trulyUniqueToBase | Where-Object { $_ -notin $fuzzyBasePaths })
    $trulyUniqueToCompare = @($trulyUniqueToCompare | Where-Object { $_ -notin $fuzzyComparePaths })

    # 6. Diff stat and name-status
    Write-Log "Running diff stat..." -Level VERBOSE
    if ($IncludePath -and $IncludePath.Count -gt 0) {
        # Scope git diff to matching paths only; collect all scoped paths
        $allScopedPaths = @($baseFiles.Keys) + @($compareFiles.Keys) | Sort-Object -Unique
        $diffStat = Get-DiffStat -BranchA $Base -BranchB $CompareTo -PathFilter $allScopedPaths
        $nameStatus = @(Get-DiffNameStatus -BranchA $Base -BranchB $CompareTo -PathFilter $allScopedPaths)
    }
    else {
        $diffStat = Get-DiffStat -BranchA $Base -BranchB $CompareTo
        $nameStatus = @(Get-DiffNameStatus -BranchA $Base -BranchB $CompareTo)
    }

    # 6a. Numstat for structured change data
    Write-Log "Running diff numstat..." -Level VERBOSE
    if ($IncludePath -and $IncludePath.Count -gt 0) {
        $numStat = @(Get-DiffNumStat -BranchA $Base -BranchB $CompareTo -PathFilter $allScopedPaths)
    }
    else {
        $numStat = @(Get-DiffNumStat -BranchA $Base -BranchB $CompareTo)
    }

    # 6b. File details for Added and Deleted files
    Write-Log "Gathering file details..." -Level VERBOSE
    $fileDetails = @{}
    $addedEntries = @($nameStatus | Where-Object { $_.Status -eq 'A' })
    $deletedEntries = @($nameStatus | Where-Object { $_.Status -eq 'D' })

    if ($addedEntries.Count -gt 0) {
        $addedDetails = Get-BulkFileDetails -Branch $CompareTo -FilePaths @($addedEntries | ForEach-Object { $_.Path })
        foreach ($key in $addedDetails.Keys) {
            $fileDetails["A:$key"] = $addedDetails[$key]
        }
    }
    if ($deletedEntries.Count -gt 0) {
        $deletedDetails = Get-BulkFileDetails -Branch $Base -FilePaths @($deletedEntries | ForEach-Object { $_.Path })
        foreach ($key in $deletedDetails.Keys) {
            $fileDetails["D:$key"] = $deletedDetails[$key]
        }
    }

    # 7. Content chunks for modified shared files
    $contentChunks = @{}
    if (-not $SkipContentChunks -and $sharedAnalysis.Modified.Count -gt 0) {
        Write-Log "Extracting content chunks for $($sharedAnalysis.Modified.Count) modified files..." -Level VERBOSE
        $i = 0
        foreach ($path in $sharedAnalysis.Modified) {
            $i++
            Write-Progress -Activity "Extracting diff hunks" -Status $path -PercentComplete (($i / $sharedAnalysis.Modified.Count) * 100)
            Write-Log "Diffing: $path" -Level DEBUG
            $hunks = Get-FileDiffHunks -BranchA $Base -BranchB $CompareTo -FilePath $path -MaxLines $MaxDiffLines
            if ($hunks) {
                $contentChunks[$path] = $hunks
            }
        }
        Write-Progress -Activity "Extracting diff hunks" -Completed
    }

    # 7a. Content chunks for fuzzy rename pairs (diff between blobs at different paths)
    $fuzzyChunks = @{}
    if (-not $SkipContentChunks -and $fuzzyRenames.Count -gt 0) {
        Write-Log "Extracting diff hunks for $($fuzzyRenames.Count) fuzzy rename pairs..." -Level VERBOSE
        $i = 0
        foreach ($fr in $fuzzyRenames) {
            $i++
            $label = "$($fr.BasePath) -> $($fr.ComparePath)"
            Write-Progress -Activity "Extracting fuzzy diff hunks" -Status $label -PercentComplete (($i / $fuzzyRenames.Count) * 100)
            Write-Log "Diffing blobs: $label" -Level DEBUG
            $baseBlob = $baseFilesAll[$fr.BasePath]
            $compareBlob = $compareFilesAll[$fr.ComparePath]
            if ($baseBlob -and $compareBlob -and $baseBlob -ne $compareBlob) {
                $output = Invoke-Git @('diff', '--unified=3', $baseBlob, $compareBlob)
                if ($output) {
                    $allLines = @($output)
                    if ($allLines.Count -gt $MaxDiffLines) {
                        $truncated = $allLines | Select-Object -First $MaxDiffLines
                        $remaining = $allLines.Count - $MaxDiffLines
                        $fuzzyChunks[$fr.BasePath] = (($truncated -join "`n") + "`n... ($remaining more lines truncated)")
                    }
                    else {
                        $fuzzyChunks[$fr.BasePath] = ($allLines -join "`n")
                    }
                }
            }
        }
        Write-Progress -Activity "Extracting fuzzy diff hunks" -Completed
    }

    # Assemble report data
    $reportData = @{
        Base                   = $Base
        CompareTo              = $CompareTo
        RepoPath               = $RepoPath
        GitVersion             = $gitVersion
        IncludePath            = $IncludePath
        CommitCounts           = $commitCounts
        BaseFileCount          = $baseFiles.Count
        CompareFileCount       = $compareFiles.Count
        SharedIdentical        = $sharedAnalysis.Identical.Count
        SharedModified         = $sharedAnalysis.Modified.Count
        SharedModifiedList     = $sharedAnalysis.Modified
        UniqueToBase           = $uniqueToBase.Count
        UniqueToCompare        = $uniqueToCompare.Count
        TrulyUniqueToBase      = $trulyUniqueToBase.Count
        TrulyUniqueToCompare   = $trulyUniqueToCompare.Count
        RenamesOnBase          = $renamesOnBase
        RenamesOnCompare       = $renamesOnCompare
        UniqueToBaseFiles      = $uniqueToBase
        UniqueToCompareFiles   = $uniqueToCompare
        BaseBlobMatches        = $baseBlobMatches
        CompareBlobMatches     = $compareBlobMatches
        FuzzyRenames           = $fuzzyRenames
        FuzzyChunks            = $fuzzyChunks
        DiffStat               = $diffStat
        NumStat                = $numStat
        NameStatus             = $nameStatus
        FileDetails            = $fileDetails
        ContentChunks          = $contentChunks
        GitHubBaseUrl          = $gitHubBaseUrl
        LocalBranch            = $currentBranch
    }

    # Finalize telemetry (before report generation so duration is available in the report)
    $script:Telemetry.EndTime = [datetime]::UtcNow
    $script:Telemetry.Duration = ($script:Telemetry.EndTime - $script:Telemetry.StartTime).ToString()

    # Format output
    Write-Log "Generating $Format report..." -Level VERBOSE
    $report = switch ($Format) {
        'Markdown'  { Format-Markdown -Data $reportData }
        'Text'      { Format-PlainText -Data $reportData }
    }

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
    if ($IncludePath) { Write-Host "  Scope:   $($IncludePath -join ', ')" -ForegroundColor Yellow }
    Write-Host "  Base:      $Base ($($baseFiles.Count) files)"
    Write-Host "  CompareTo: $CompareTo ($($compareFiles.Count) files)"
    Write-Host "  Shared identical: $($sharedAnalysis.Identical.Count) | Modified: $($sharedAnalysis.Modified.Count)"
    Write-Host "  Unique to $Base`: $($uniqueToBase.Count) (renames: $renamesOnBase, fuzzy: $($fuzzyRenames.Count), truly unique: $($trulyUniqueToBase.Count))"
    Write-Host "  Unique to $CompareTo`: $($uniqueToCompare.Count) (renames: $renamesOnCompare, truly unique: $($trulyUniqueToCompare.Count))"
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
    # Restore original console encoding
    [Console]::OutputEncoding = $script:PreviousOutputEncoding
}

#endregion
