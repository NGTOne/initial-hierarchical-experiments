#include <libHierGA/HierGA.hpp>
#include <string>
#pragma once

class LongFragFitness : public FitnessFunction {
	private:

	protected:

	public:
	LongFragFitness();
	PropertiesList * checkFitness(GenePool ** pools, int * indexes, int genomeLength);
};

class LongFragToString : public ToStringFunction {
	private:

	protected:

	public:
	std::string toString(GenePool ** pools, int * indexes, int genomeLength);
};
