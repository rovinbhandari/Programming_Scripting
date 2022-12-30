# TODO: Build caching!!!!!
# TODO: Doesn't work with (gc $file -TotalCount X)[Y..(X-1)] | Get-Meaning, where X > Y
Function Get-Meaning($keywords)
{
  # To insert a Line that will separate one meaning  from another
  $break = '--------------------------------------------------------------------------------------------'
  $uri = "https://wordsapiv1.p.rapidapi.com/words/{0}"
  $key = Get-Key
  $headers = @{}
  $headers.Add("X-RapidAPI-Key", $key)
  $headers.Add("Accept", "text/json")

  $keywords | %{
    $response = $null 
    $uriWithWord = $uri -f "$_"

    Do-Bookkeeping -content "$_"
    try {
      $response = Invoke-WebRequest -Uri $uriWithWord -Headers $headers
    }
    catch {
      Do-Bookkeeping -content "failed" -before $false
      throw "Couldn't get a response from the endpoint!"
    }
    Do-Bookkeeping -content $response.StatusCode -before $false

    Write-host "`nMeaning of $_" -ForegroundColor Yellow
    $response.Content | ConvertFrom-Json | ConvertTo-Json

    echo "$break"
    sleep 2
  }
} 

Function Do-Bookkeeping($content, $before = $true, $subpath = "APIs\WordAPI")
{
  $monthYear = Get-Date -UFormat "%m_%Y"
  $filename = "wordapi_rapidapi_{0}.log" -f $monthYear
  $path = Join-Path $env:OneDriveConsumer -ChildPath $subpath | Join-Path -ChildPath $filename
  $limit = 2000

  if ($before)
  {
    # verify file exists
    if (-not (Test-Path $path))
    {
      Write-Host "Creating new log file @ $path ..."
      echo "" | Out-File -Encoding ascii -Append $path -NoNewLine
    }

    # count lines of file and check against limit
    $measure = Get-Content $path | Measure-Object -Line
    if ($measure.Lines -ge $limit)
    {
      throw "Limit($limit) reached!"
    }

    $timestamp = Get-Date -Format o
    echo "$timestamp,$content" | Out-File -Encoding ascii -Append $path -NoNewLine
  }
  else
  {
    $timestamp = Get-Date -Format o
    echo ",$timestamp,$content" | Out-File -Encoding ascii -Append $path 
  }
}

Function Get-Key()
{
  $path = Join-Path $env:OneDriveConsumer -ChildPath "APIs\WordAPI" | Join-Path -ChildPath "rapidapi_words_key.txt"
  $key = Get-Content $path
  return $key
}
