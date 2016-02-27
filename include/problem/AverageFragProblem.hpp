#include "problem/Problem.hpp"
#pragma once

class AverageFragProblem : public Problem {
	private:

	protected:
	void getFunctions(int hierarchyDepth);

	public:
	AverageFragProblem(GenerationModel * model, int libraries);
	AverageFragProblem(GenerationModel * model, int secondLevelNodes, int libraries, bool coevolutionary);
	AverageFragProblem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int libraries, bool coevolutionary);
	AverageFragProblem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int fourthLevelNodes, int libraries, bool coevolutionary);
	AverageFragProblem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int fourthLevelNodes, int fifthLevelNodes, int libraries, bool coevolutionary);
};
