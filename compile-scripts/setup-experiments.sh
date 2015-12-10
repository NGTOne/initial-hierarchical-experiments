#!/bin/bash -ex

rm -rf experiments-to-run

mkdir experiments-to-run

categories=$(ls src/experiments)

for cat in $categories
do
	mkdir experiments-to-run/$cat
	srcdir=src/experiments/$cat
	experiments=$(ls $srcdir)
	experiments=$(echo $experiments | sed 's/\.cpp//g')

	for exper in $experiments
	do
		g++ -c -g -std=gnu++0x -fPIC -Iinclude $srcdir/$exper.cpp -o obj/$cat/$exper.o
		g++ -std=gnu++0x -Iinclude -lHierGA -o experiments-to-run/$cat/$exper obj/*.o obj/$cat/$exper.o
	done
done
