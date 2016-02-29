#include <libHierGA/HierGA.hpp>
#pragma once

// Not pretty, but simpler than doing it with a function
// Doesn't matter as much because this is more-or-less throwaway experiment
// code (especially with libHierGAv2 in the pipeline)
#define getNode(popSize, coevolutionary) ((!coevolutionary) ? new HierarchicalGenePool(popSize*2, templateIndividual, 100, 1, model, NULL, new NonPropagator()) : new NonEvolvingPopulationNode(popSize*2, templateIndividual, 100, 1, NULL, new NonPropagator()))

class HierExperiment {
	private:

	protected:
	HierarchicalGenePool * topLevelPool;

	public:
	void run(bool silent);
};
