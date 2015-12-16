#include "problem/Problem.hpp"
#pragma once

class LongFragProblem : public Problem {
	private:

	protected:
	void getFunctions(int hierarchyDepth);

	public:
	LongFragProblem(GenerationModel * model, int libraries) : Problem(model, libraries) {}
	LongFragProblem(GenerationModel * model, int secondLevelNodes, int libraries) : Problem(model, secondLevelNodes, libraries) {}
	LongFragProblem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int libraries) : Problem(model, secondLevelNodes, thirdLevelNodes, libraries) {}
	LongFragProblem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int fourthLevelNodes, int libraries) : Problem(model, secondLevelNodes, thirdLevelNodes, fourthLevelNodes, libraries) {}
};
