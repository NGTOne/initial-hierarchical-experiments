#include "problem/Problem.hpp"
#pragma once

class LongFragProblem : public Problem {
	private:

	protected:
	void getFunctions(int hierarchyDepth);

	public:
	LongFragProblem(GenerationModel * model, int libraries);
	LongFragProblem(GenerationModel * model, int secondLevelNodes, int libraries, bool coevolutionary);
	LongFragProblem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int libraries, bool coevolutionary);
	LongFragProblem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int fourthLevelNodes, int libraries, bool coevolutionary);
	LongFragProblem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int fourthLevelNodes, int fifthLevelNodes, int libraries, bool coevolutionary);
};
