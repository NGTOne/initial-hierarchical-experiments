#include "problem/LongFragProblem.hpp"

int main(void) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new ESGeneration(strategy);

	Problem * problem = new LongFragProblem(model, 4, 2, 2, 2, false);
	problem->run();
}
