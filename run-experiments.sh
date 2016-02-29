#!/bin/bash

# Run each experiment this many times
count=$1
shift

if [[ "$1" == "--silent" ]]
then
	silent=1
	shift
else
	silent=0
fi

if [[ "$#" -eq 0 ]]
then
	categories=$(ls experiments-to-run)
else
	categories=""
	for cat in $@
	do
		categories="$categories $cat"
	done
fi

if [[ $silent -ne 1 ]]
then
	rm -rf experiment-results
	mkdir experiment-results
fi

for cat in $categories
do
	if [[ $silent -ne 1 ]]; then mkdir experiment-results/$cat; fi
	experiments=$(ls experiments-to-run/$cat)

	for exper in $experiments
	do
		if [[ $silent -ne 1 ]]
		then
			mkdir experiment-results/$cat/$exper
		fi

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

			if [[ $silent -eq 1 ]]
			then
				experiments-to-run/$cat/$exper silent
			else
				experiments-to-run/$cat/$exper loud > experiment-results/$cat/$exper/run-$i.txt
			fi
		done
	done
done

if [[ $silent -ne 1 ]]
then
	./analyze-experiments.sh
fi
