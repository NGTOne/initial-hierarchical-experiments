#include "problem/LongFragProblem.hpp"

int main(void) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new GA(2, false, strategy);

	Problem * problem = new LongFragProblem(model, 2, 2, 4, 2, true);
	problem->run();
}
