folder="/home/rovin/Programming/Shell/scripts/missionxkcd"
htmls="htmls/xkcd"
name=1
total=$(ls "$folder/$htmls/" | wc -l)
cd "$folder"
echo "<html><body>" > links.html
while [ $name -lt $total ]
do
	line=$(cat "$htmls/$name" | head -n 75 | tail -n 10 | grep "<img src=") #>> temp_links
	src=${line#*\"}
	src=${src%%\"*}
	src="$src<br />"
	echo $src >> links.html
	name=$((name+1))
done
echo "</body></html>" >> links.html

