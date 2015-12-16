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

		SECONDS=0

		for i in $(seq 1 $count)
		do
			echo -n "Running $cat/$exper... $i/$count"
			if [[ $i -ne $count ]]
			then
				echo -n R | tr 'R' '\r'
			else
				echo " Took $(($SECONDS / 60)) m $(($SECONDS % 60))s"
			fi
			experiments-to-run/$cat/$exper > experiment-results/$cat/$exper/run-$i.txt
		done

		perl analyze-convergence.pl experiment-results/$cat/$exper 30
	done
done
