#!/bin/perl

use warnings;
use strict;

my @filenames;
my @convergenceGenerations;

my $dir = $ARGV[0];
my $optimum = $ARGV[1];

opendir(DIR, $dir) or die "Could not open results directory $dir";

while ($_ = readdir(DIR)) {
	push @filenames, "$dir/$_" if (/^run-\d+\.txt$/);
}

foreach (@filenames) {
	my $populationSize = 0;
	my $generation = 0;
	my @lines;
	my @members;

	open(my $fh, "<", $_) or die "Could not open results file $_";

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
					$optimal++ if ($fitness == $optimum);
				}
				if ($optimal/$populationSize >= 0.5) {
					push @convergenceGenerations, $generation;
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
}
