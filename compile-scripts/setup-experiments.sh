#!/bin/bash

rm -rf experiments

mkdir experiments

categories=$(ls src/experiments)

for cat in $categories
do
	mkdir experiments/$cat
	srcdir=src/experiments/$cat
	experiments=$(ls $srcdir)
	experiments=$(echo $experiments | sed 's/\.cpp//g')

	for exper in $experiments
	do
		g++ -c -g -std=gnu++0x -fPIC -Iinclude $srcdir/$exper.cpp -o obj/$cat/$exper.o
		g++ -std=gnu++0x -Iinclude -lHierGA -o experiments/$cat/$exper obj/*.o obj/$cat/$exper.o
	done
done
