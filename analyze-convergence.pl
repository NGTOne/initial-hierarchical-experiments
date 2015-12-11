#!/bin/perl

use warnings;
use strict;

my @filenames;
my %convergenceGenerations;

my $dir = $ARGV[0];
my $optimum = $ARGV[1];

opendir(DIR, $dir) or die "Could not open results directory $dir";

while ($_ = readdir(DIR)) {
	push @filenames, "$_" if (/^run-\d+\.txt$/);
}

foreach (@filenames) {
	my $converged = 0;
	my $populationSize = 0;
	my $generation = 0;
	my @lines;
	my @members;

	open(my $fh, "<", "$dir/$_") or die "Could not open results file $_";
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
				foreach my $fitness (@members) {
					$optimal++ if ($fitness >= $optimum);
				}
				if ($optimal/$populationSize >= 0.5) {
					$convergenceGenerations{"Run $run"} = $generation;
					$converged = 1;
					last;
				}
			}

			# Reset for the next generation
			$generation = $1;
			undef(@members);
		}

		if (/^Member (\d+): .+ Fitness: (\d+)$/) {
			push @members, $2;
		}
	}

	if (!$converged) {
		$convergenceGenerations{"Run $run"} = "Failed to converge"
	}
}

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

open(my $fh, '>', "$dir/results.txt");

print $fh "Mean convergence time: $mean generations\n";
print $fh "Fastest convergence time: $fastest generations\n";
print $fh "Slowest convergence time: $slowest generations\n";
print $fh "================================================\n";
print $fh "Convergence generations by run:\n";

sub sortRuns {
	$a =~ /^Run (\d+)$/;
	my $num1 = $1;
	$b =~ /^Run (\d+)$/;
	my $num2 = $1;

	$num1 <=> $num2;
}

foreach my $run (sort sortRuns keys %convergenceGenerations) {
	printf $fh "%-8s: %s\n", $run, $convergenceGenerations{$run};
}

close $fh;
