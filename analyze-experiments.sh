#!/bin/bash

rm results.csv results.zip

categories=$(ls experiment-results | grep -v txt)

for cat in $categories
do
	experiments=$(ls experiment-results/$cat)

	for exper in $experiments
	do
		perl analyze-convergence.pl experiment-results/$cat/$exper experiment-results/output.txt 30
	done
done

zip -rv results.zip experiment-results results.csv
