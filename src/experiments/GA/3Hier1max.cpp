#include "problem/1maxProblem.hpp"

int main(void) {
	SelectionStrategy * strategy = new TournamentSelection(0.5);
	GenerationModel * model = new GAGeneration(0.5, strategy);

	Problem * problem = new OneMaxProblem(model, 3, 4, 4, 2);
	problem->run();
}
