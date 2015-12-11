#!/bin/bash

rm results.csv

categories=$(ls experiment-results)

for cat in $categories
do
	experiments=$(ls experiment-results/$cat)

	for exper in $experiments
	do
		perl analyze-convergence.pl experiment-results/$cat/$exper 30
	done
done
