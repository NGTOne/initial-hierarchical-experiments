#include "problem/LongFragProblem.hpp"

int main(void) {
	SelectionStrategy * strategy = new TournamentSelection(0.5);
	GenerationModel * model = new ESGeneration(strategy);

	Problem * problem = new LongFragProblem(model, 3, 8, 2, 2);
	problem->run();
}
