#!/bin/bash

# Run each experiment this many times
count=$1
categories=$(ls experiments-to-run)

rm -rf experiment-results
mkdir experiment-results

for cat in $categories
do
	mkdir experiment-results/$cat
	experiments=$(ls experiments-to-run/$cat)

	for exper in $experiments
	do
		mkdir experiment-results/$cat/$exper

		for i in $(seq 1 $count)
		do
			echo -n "Running $cat/$exper... $i/$count"
			echo -n R | tr 'R' '\r'
			experiments-to-run/$cat/$exper > experiment-results/$cat/$exper/run-$i.txt
		done

		echo ""

		perl analyze-convergence.pl experiment-results/$cat/$exper 30
	done
done
