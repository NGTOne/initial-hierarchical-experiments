#include "problem/LongFragProblem.hpp"

int main(int argc, char* argv[]) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new GA(2, true, strategy);

	Problem * problem = new LongFragProblem(model, 2, 4, 4, true);
	problem->run(runSilent);
}
