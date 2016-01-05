param([parameter(Mandatory=$false)]$ToCSV=$true)

Write-Progress -Activity "Looking for files..."
# get all files (not folders) in the current directory (including subdirectories)
$allFiles = gci . -recurse | Where-Object {$_.PSIsContainer -eq $False} | % {$_.FullName}
$totalFiles = $allFiles.Count
$extensionSizeMap = @{}
$extensionNumMap = @{}
$typeSizeMap = @{"text" = 0; "binary" = 0}
$typeNumMap = @{"text" = 0; "binary" = 0}
$csvFilename = ""
$csvDelim = ";"

Write-Host -ForegroundColor Yellow "TotalFiles: $totalFiles"

function IsBinary([string] $path)
{
	# encoding variable
	$encoding = ""

	# Get the first 1024 bytes from the file
	$byteArray = Get-Content -Path $path -Encoding Byte -TotalCount 1024

	if( ($byteArray.Length -ge 3) -and (("{0:X}{1:X}{2:X}" -f $byteArray) -eq "EFBBBF") )
	{
		# Test for UTF-8 BOM
		$encoding = "UTF-8"
	}
	elseif( ($byteArray.Length -ge 2) -and (("{0:X}{1:X}" -f $byteArray) -eq "FFFE") )
	{
		# Test for the UTF-16
		$encoding = "UTF-16"
	}
	elseif( ($byteArray.Length -ge 2) -and (("{0:X}{1:X}" -f $byteArray) -eq "FEFF") )
	{
		# Test for the UTF-16 Big Endian
		$encoding = "UTF-16 BE"
	}
	elseif( ($byteArray.Length -ge 4) -and (("{0:X}{1:X}{2:X}{3:X}" -f $byteArray) -eq "FFFE0000") )
	{
		# Test for the UTF-32
		$encoding = "UTF-32"
	}
	elseif( ($byteArray.Length -ge 4) -and (("{0:X}{1:X}{2:X}{3:X}" -f $byteArray) -eq "0000FEFF") )
	{
		# Test for the UTF-32 Big Endian
		$encoding = "UTF-32 BE"
	}
       

	if($encoding)
	{
		# File is text encoded
		return @($false, $encoding)
	}
    

	# So now we're done with Text encodings that commonly have '0's
	# in their byte steams.  ASCII may have the NUL or '0' code in
	# their streams but that's rare apparently.

	# Both GNU Grep and Diff use variations of this heuristic

	if( $byteArray -contains 0 )
	{
		# Test for binary
		return ($true, "BINARY")
	}

	# This should be ASCII encoded 
	$encoding = "ASCII"

	return ($false, $encoding)
}

$progress = 0
$i = 0
foreach($file in $allFiles)
{
	$name = [System.IO.Path]::GetFileNameWithoutExtension($file)
	$ext = [System.IO.Path]::GetExtension($file)
	if(-not $extensionSizeMap.ContainsKey($ext))
    {
        $extensionSizeMap.Add($ext, 0)
        $extensionNumMap.Add($ext, 0)
    }
    $extensionSizeMap[$ext] += (Get-Item $file).Length
    $extensionNumMap[$ext] += 1
    $type = IsBinary($file)
    if($type[0])
    {
        $typeSizeMap["binary"] += (Get-Item $file).Length
        $typeNumMap["binary"] += 1
    }
    else
    {
        $typeSizeMap["text"] += (Get-Item $file).Length
        $typeNumMap["text"] += 1
    }
    $i += 1
    $progress = $($($i / $totalFiles) * 100)
    Write-Progress -Activity "Processing Files..." -PercentComplete $progress -CurrentOperation "$("{0:N0}" -f $progress)% of $totalFiles files processed."
}

function WriteLine($filename, $text)
{
    if("$filename" -eq "")
    {
        Echo "$text"
    }
    else
    {
        "$text" >> "$filename"
    }    
}

function PrintMap
{
    param ($numMap, $sizeMap, $filename)

    foreach($ext in $numMap.Keys)
    {
        $line = "$ext" + $csvDelim + "$($numMap.Get_Item($ext))" + $csvDelim + ("$($("{0:N2}" -f $($sizeMap.Get_Item($ext) / 1KB)))")
        WriteLine $filename $line
    }
}

if("$ToCSV" -eq "$true")
{
    $csvFilename = "Analysis_" + $(Get-Date -Format "yyyy-MM-dd-HH-mm-ss") + ".csv"
    Write-Host -ForegroundColor Yellow ("Writing to file: " + "$csvFilename")
}
WriteLine $csvFilename ("Type" + $csvDelim + "Num" + $csvDelim + "Size")

PrintMap $typeNumMap $typeSizeMap $csvFilename
PrintMap $extensionNumMap $extensionSizeMap $csvFilename

