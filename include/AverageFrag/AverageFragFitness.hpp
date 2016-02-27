#include <libHierGA/HierGA.hpp>
#include <string>
#pragma once

class AverageFragFitness : public FitnessFunction {
	private:

	protected:

	public:
	AverageFragFitness();
	PropertiesList * checkFitness(GenePool ** pools, int * indexes, int genomeLength);
};

class AverageFragToString : public ToStringFunction {
	private:

	protected:

	public:
	std::string toString(GenePool ** pools, int * indexes, int genomeLength);
};
