#!/bin/bash

rm results.csv results.zip summary.csv

categories=$(ls experiment-results | grep -v txt)

for cat in $categories
do
	experiments=$(ls experiment-results/$cat)

	for exper in $experiments
	do
		perl analyze-convergence.pl experiment-results/$cat/$exper experiment-results/output.txt 30
	done
done

cat $(find . -name summary.csv) > summary.csv
zip -rv results.zip experiment-results results.csv summary.csv
