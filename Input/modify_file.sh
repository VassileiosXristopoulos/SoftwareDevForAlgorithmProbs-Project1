#!/bin/bash
filename=$1
outputfile=new_query_small
num=1
while read -r line
do
	name="$line"
	echo "item_idS$num $line" >> "$outputfile"
	let num=num+1
done < "$filename"

	

