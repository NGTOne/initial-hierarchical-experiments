#include "problem/LongFragProblem.hpp"

int main(void) {
	SelectionStrategy * strategy = new TournamentSelection(0.5);
	GenerationModel * model = new GAGeneration(0.5, strategy);

	Problem * problem = new LongFragProblem(model, 3, 2, 2, 8);
	problem->run();
}
