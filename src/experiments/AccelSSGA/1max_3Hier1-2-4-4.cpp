#include "problem/1maxProblem.hpp"

int main(void) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new AccelSSGA(strategy);

	Problem * problem = new OneMaxProblem(model, 2, 4, 4, false);
	problem->run();
}
