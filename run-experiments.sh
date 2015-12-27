#!/bin/bash

# Run each experiment this many times
count=$1
categories=$(ls experiments-to-run)

rm results.csv
rm results.zip
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
				runTime=$SECONDS
				echo " Took $(($runTime / 60))m $(($runTime % 60))s"
				echo "$cat/$exper took $(($runTime / 60))m $(($runTime % 60))s" >> experiment-results/output.txt
			fi
			experiments-to-run/$cat/$exper > experiment-results/$cat/$exper/run-$i.txt
		done

		perl analyze-convergence.pl experiment-results/$cat/$exper experiment-results/output.txt 30
	done
done

zip -rv results.zip experiment-results results.csv
