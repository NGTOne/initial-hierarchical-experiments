#include "problem/LongFragProblem.hpp"

int main(int argc, char* argv[]) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new ES(0.5, 0.5, strategy);

	Problem * problem = new LongFragProblem(model, 2, 8, 2, false);
	problem->run(runSilent);
}
