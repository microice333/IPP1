#!/bin/bash

PASSED=0
ALL=0
PARAMETERS=
PROGRAM=
DIR=

if [ $# == 3 ]; then
	PARAMETERS=$1
	PROGRAM="./$2"
	DIR=$3
else
	PROGRAM="./$1"
	DIR=$2
fi

for file in $DIR/test*.in; do
	$PROGRAM $PARAMETERS < $file > out 2> err

	if diff out ${file%in}out; then
		if diff err ${file%in}err; then
			PASSED=$((PASSED+1))
			echo "[$file] OK"
		fi
	else
		echo "[$file] WRONG"
	fi

	ALL=$((ALL+1))
done

echo "Passed $PASSED from $ALL tests."

rm out
rm err

