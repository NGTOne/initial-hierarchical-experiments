#include <libHierGA/HierGA.hpp>
#include <string>
#pragma once

class HierAverageFragFitness : public FitnessFunction {
	private:

	protected:

	public:
	HierAverageFragFitness();
	PropertiesList * checkFitness(GenePool ** pools, int * indexes, int genomeLength);
};

class HierAverageFragToString : public ToStringFunction {
	private:

	protected:

	public:
	std::string toString(GenePool ** pools, int * indexes, int genomeLength);
};
