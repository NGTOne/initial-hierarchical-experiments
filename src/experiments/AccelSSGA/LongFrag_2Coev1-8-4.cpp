#include "problem/LongFragProblem.hpp"

int main(void) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new AccelSSGA(strategy);

	Problem * problem = new LongFragProblem(model, 8, 4, true);
	problem->run();
}