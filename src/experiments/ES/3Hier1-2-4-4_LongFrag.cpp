#include "problem/LongFragProblem.hpp"

int main(void) {
	SelectionStrategy * strategy = new TournamentSelection(0.5);
	GenerationModel * model = new ESGeneration(strategy);

	Problem * problem = new LongFragProblem(model, 3, 2, 4, 4);
	problem->run();
}
