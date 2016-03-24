#!/bin/perl

use warnings;
use strict;

my @filenames;
my %times;
my %convergenceGenerations;

my $dir = $ARGV[0];
my $timeFile = $ARGV[1];
my $optimum = $ARGV[2];

open(my $fh, "<", $timeFile) or die "Could not open experiment output file";

while(<$fh>) {
	chomp;
	/^(.+) took (\d+)m (\d+)s$/;
	$times{$1} = $2*60 + $3;
}

close $fh;

opendir(DIR, $dir) or die "Could not open results directory $dir";

while ($_ = readdir(DIR)) {
	push @filenames, "$_" if (/^run-\d+\.txt$/);
}

sub sortFiles {
	$a =~ /run-(\d+)\.txt/;	my $num1 = $1;
	$b =~ /run-(\d+)\.txt/; my $num2 = $1;
	$num1 <=> $num2;
}

open(my $csv, '>', "$dir/summary.csv");
print $csv "Evolutionary System,Problem,Hierarchy Type,Structure,Run,Generations to Convergence,Highest Achieved Fitness,First Occurence Generation of Highest Fitness,Individuals Meeting Convergence Criteria\n" if (-z $csv);
my $experimentName = $dir;
$experimentName =~ s/^experiment-results\///;
my $experimentRegex =  '(.+)\/(1max|LongFrag|AverageFrag)_(?:\d(Coev|Hier))?(.+)';

print "Analyzing $experimentName\n";

open(my $gens, '>>', "generations.csv");
if (-z $gens) {
	print $gens "Evolutionary System,Problem,Hierarchy Type,Structure,Run,Generation,";

	for (my $i = 0; $i < 32; $i++) {
		print $gens "# With Fitness $i,";
	}
	print $gens "# With Fitness 32,";
	for (my $i = 0; $i < 32; $i++) {
		print $gens "# With HD $i,";
	}
	print $gens "# With HD 32\n";
}

foreach (sort sortFiles @filenames) {
	my $converged = 0;
	my $populationSize = 0;
	my $generation = 0;
	my @lines;
	my @members;
	my $bestFitness = 0;
	my $bestGeneration = 0;
	my $convergedMembers = 0;
	my @allFitnesses;
	my @allDistances;
	my @hammingDistances = (0) x 33;

	open($fh, "<", "$dir/$_") or die "Could not open results file $_";
	/^run-(\d+)\.txt$/;
	my $run = $1;

	while(<$fh>) {
		chomp;
		push @lines, $_;
	}

	close $fh;

	foreach (@lines) {
		$populationSize = $1 if (!$populationSize and /^Population size: (\d+)$/);
		if (/^Before generation (\d+):$/) {
			if (@members) {
				my $optimal = 0;
				my $bestMember = 0;
				my @fitnesses = (0) x 33;
				foreach my $fitness (@members) {
					$optimal++ if ($fitness >= $optimum);
					if ($fitness > $bestFitness) {
						$bestFitness = $fitness;
						$bestGeneration = $generation;
					}
					$fitnesses[$fitness] += 1;
				}
				my @temp = @hammingDistances;
				push @allFitnesses, \@fitnesses;
				push @allDistances, \@temp;
				if ($optimal > 0 && !$converged) {
					$convergenceGenerations{"Run $run"} = $generation;
					$convergedMembers = $optimal;
					$converged = 1;
					last;
				}
			}

			# Reset for the next generation
			$generation = $1-1;
			undef(@members);
			@hammingDistances = (0) x 33;
		}

		if (/^Member (\d+): ([01]+) Fitness: (\d+)$/ && $converged == 0) {
			push @members, $3;
			my $distance = ($2 =~ tr/0//);
			$hammingDistances[$distance]++;
		}
	}

	if (!$converged) {
		$convergenceGenerations{"Run $run"} = "Failed to converge"
	}

	$experimentName =~ /$experimentRegex/;
	print $csv "$1,$2,".($3 || "N/A").",$4,"; #Info about the experiment
	print $csv "$run,".($converged ? $convergenceGenerations{"Run $run"} : "Failed").",$bestFitness,$bestGeneration,$convergedMembers\n";

	for (my $i=0; $i <= $bestGeneration; $i++) {
		print $gens "$1,$2,".($3 || "N/A").",$4,$run,$i,";
		for (my $k=0; $k < 32; $k++) {
			print $gens "$allFitnesses[$i][$k],";
		}
		print $gens "$allFitnesses[$i][32],";
		for (my $k=0; $k < 32; $k++) {
			print $gens "$allDistances[$i][$k],";
		}
		print $gens "$allDistances[$i][32]\n";
	}
}

close ($gens);
close ($csv);

my $mean = 0;
my $slowest = 0;
my $sum = 0;
my $fastest = 100;
my $runCount = 0;#keys %convergenceGenerations;

foreach my $run (keys %convergenceGenerations) {
	my $gen = $convergenceGenerations{$run};
	if ($gen ne "Failed to converge") {
		$runCount++;
		$sum += $gen;
		$slowest = $gen if $gen > $slowest;
		$fastest = $gen if $gen < $fastest;
	}
}

$mean = $sum/$runCount if $runCount;

open($fh, '>', "$dir/results.txt");

sub sortRuns {
	$a =~ /^Run (\d+)$/;
	my $num1 = $1;
	$b =~ /^Run (\d+)$/;
	my $num2 = $1;

	$num1 <=> $num2;
}

print $fh "Experiment: $experimentName\n";
print $fh "================================================\n";

open($csv, '>>', "results.csv");
print $csv "Evolutionary System, Problem, Hierarchy Type, Structure, Run Time (seconds), Success, Mean, Fastest, Slowest, 25th %tile, Med, 75th %tile, IQR, Variance, StdDev, StdErr\n" if (-z $csv);
$experimentName =~ /$experimentRegex/;
print $csv "$1,$2,".($3 || "N/A").",$4,"; #Information about the experiment

print $csv $times{$experimentName}.",";

if ($runCount) {
	print $fh "Successful runs: $runCount\n";
	print $fh "Run time: $times{$experimentName} seconds\n";
	print $fh "Mean convergence time: $mean generations\n";
	print $fh "Fastest convergence time: $fastest generations\n";
	print $fh "Slowest convergence time: $slowest generations\n";

	my ($median, $twentyFifth, $seventyFifth);
	my @convergences;

	foreach my $run (keys %convergenceGenerations) {
		my $value = $convergenceGenerations{$run};
		push @convergences, $value if $value ne "Failed to converge";
	}

	@convergences = sort {$a <=> $b} @convergences;
	if ($runCount >= 50) {
		$median = $convergences[49];
	} else {
		$median = 'Inf';
	}

	if ($runCount >= 25) {
		$twentyFifth = $convergences[24];
	} else {
		$twentyFifth = 'Inf';
	}

	if ($runCount >= 75) {
		$seventyFifth = $convergences[74];
	} else {
		$seventyFifth = 'Inf';
	}

	print $fh "Twenty-fifth percentile: $twentyFifth generations\n";
	print $fh "Median: $median generations\n";
	print $fh "Seventy-fifth percentile: $seventyFifth generations\n";
	print $fh "Interquartile range: ".(my $iqRange = $seventyFifth - $twentyFifth)." generations\n";

	#Calculate the variance and standard deviation
	my $variance=0;
	$variance += ($_-$mean)**2 foreach (@convergences);
	$variance = $variance/$runCount;
	my $stdDev = sqrt($variance);
	my $stdError = $stdDev/sqrt($runCount);
	print $fh "Variance: $variance\n";
	print $fh "Standard deviation: $stdDev\n";
	print $fh "Standard error: $stdError\n";
	print $csv "$runCount,$mean,$fastest,$slowest,$twentyFifth,$median,$seventyFifth,$iqRange, $variance, $stdDev, $stdError\n";
} else {
	print $fh "All runs failed to converge in 100 generations.\n";
	print $csv "All runs failed to converge\n";
}
close $csv;

print $fh "================================================\n";
print $fh "Convergence generations by run:\n";

foreach my $run (sort sortRuns keys %convergenceGenerations) {
	printf $fh "%-8s: %s\n", $run, $convergenceGenerations{$run};
}

close $fh;
