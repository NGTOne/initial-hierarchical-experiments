#include "problem/Problem.hpp"
#pragma once

class OneMaxProblem : public Problem {
	private:

	protected:
	void getFunctions(int hierarchyDepth);

	public:
	OneMaxProblem(GenerationModel * model, int libraries) : Problem(model, libraries) {}
	OneMaxProblem(GenerationModel * model, int secondLevelNodes, int libraries) : Problem(model, secondLevelNodes, libraries) {}
	OneMaxProblem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int libraries) : Problem(model, secondLevelNodes, thirdLevelNodes, libraries) {}
	OneMaxProblem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int fourthLevelNodes, int libraries) : Problem(model, secondLevelNodes, thirdLevelNodes, fourthLevelNodes, libraries) {}
};
