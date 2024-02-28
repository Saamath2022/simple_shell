#!/bin/bash

echo  "I was blind but ALX opened my eyes, I now have vision"

/*Print the provided arguments*/
echo "$1 $3 $5"

/*Loop through all arguments using 'shift'*/
while["$#" -gt 0]
do
	echo "$1"
	shift
done

