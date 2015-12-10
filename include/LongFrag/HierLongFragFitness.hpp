#include <libHierGA/HierGA.hpp>
#include <string>
#pragma once

class HierLongFragFitness : public FitnessFunction {
	private:

	protected:

	public:
	HierLongFragFitness();
	PropertiesList * checkFitness(GenePool ** pools, int * indexes, int genomeLength);
};

class HierLongFragToString : public ToStringFunction {
	private:

	protected:

	public:
	std::string toString(GenePool ** pools, int * indexes, int genomeLength);
};
