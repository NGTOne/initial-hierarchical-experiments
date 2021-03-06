#include "problem/Problem.hpp"
#pragma once

class OneMaxProblem : public Problem {
	private:

	protected:
	void getFunctions(int hierarchyDepth);

	public:
	OneMaxProblem(GenerationModel * model, int libraries);
	OneMaxProblem(GenerationModel * model, int secondLevelNodes, int libraries, bool coevolutionary);
	OneMaxProblem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int libraries, bool coevolutionary);
	OneMaxProblem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int fourthLevelNodes, int libraries, bool coevolutionary);
	OneMaxProblem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int fourthLevelNodes, int fifthLevelNodes, int libraries, bool coevolutionary);
};
