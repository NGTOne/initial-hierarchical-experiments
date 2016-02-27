#include "problem/AverageFragProblem.hpp"

int main(void) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new GA(2, true, strategy);

	Problem * problem = new AverageFragProblem(model, 2, 2, 8, false);
	problem->run();
}
