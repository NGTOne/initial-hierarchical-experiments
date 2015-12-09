#include <libHierGA/HierGA.hpp>

class HierExperiment {
	private:

	protected:
	HierarchicalGenePool * topLevelPool;

	public:
	virtual HierExperiment(FitnessFunction * objective, FitnessFunction * promise, GenerationModel * model)=0;

	void run();
};
