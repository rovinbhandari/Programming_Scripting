if (Test-Path $PSHOME\Profile.ps1)
{
  . $PSHOME\Profile.ps1
  exit
}

function Get-RandomOmpTheme($themesPath)
{
  if (Test-Path $themesPath)
  {
    $allThemes = ls $themesPath\*.omp.json
    $numThemes = $allThemes.Count
    $seed = (Get-Date).Millisecond
    $themeIndex = Get-Random -SetSeed $seed -Minimum 0 -Maximum $numThemes
    return $allThemes[$themeIndex].FullName
  }
}

function Set-Aliases($aliasesPath)
{
  # Machine specific aliases
  if (Test-Path $aliasesPath)
  {
    . $aliasesPath
  }

  # General aliases (in addition to those from other places.)
  $csiPath = 'C:\Program Files\Microsoft Visual Studio\2022\Enterprise\MSBuild\Current\bin\Roslyn\csi.exe'
  if (Test-Path $csiPath)
  {
    Set-Alias -Name csi -Value $csiPath
  }  
}

$global:order = -1
function Run-WithMessageAndMeasurements([String]$m, [ScriptBlock]$sb)
{
  $global:order += 1
  $ttr = (Measure-Command { & $sb } | select TotalSeconds).TotalSeconds
  return @{Message=$m; Seconds=$ttr; Order=$order}
}

$result = @()

$result += Run-WithMessageAndMeasurements -m "Set PSReadLine options" -sb { Import-Module -Name CompletionPredictor; Set-PSReadLineOption -PredictionViewStyle ListView }

# $result += Run-WithMessageAndMeasurements -m "Importing machine specific powershell module" -sb { Import-Module -WarningAction SilentlyContinue R:\...\blah.psm1 }

$global:chosenTheme
$result += Run-WithMessageAndMeasurements -m "Getting a random theme" -sb { $global:chosenTheme = Get-RandomOmpTheme $env:POSH_THEMES_PATH }

# Probably need to install PSReadLine and NerdFonts for this:
$result += Run-WithMessageAndMeasurements -m "Initializing oh-my-posh with theme" -sb { oh-my-posh init pwsh --config "$chosenTheme" | Invoke-Expression }

$result += Run-WithMessageAndMeasurements -m "Importing posh-git" -sb { Import-Module posh-git }

$result += Run-WithMessageAndMeasurements -m "Setting additional aliases" -sb { Set-Aliases -aliasesPath "~\Documents\PowerShell\Aliases.ps1" }

Write-Host -ForegroundColor Yellow "Theme: $chosenTheme"
$result | Sort -Property Seconds | Select Message, Seconds, Order 
