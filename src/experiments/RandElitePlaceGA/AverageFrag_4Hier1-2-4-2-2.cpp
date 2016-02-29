#include "problem/AverageFragProblem.hpp"

int main(int argc, char* argv[]) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new GA(2, true, strategy);

	Problem * problem = new AverageFragProblem(model, 2, 4, 2, 2, false);
	problem->run(runSilent);
}
