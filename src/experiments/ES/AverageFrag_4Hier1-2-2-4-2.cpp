#include "problem/AverageFragProblem.hpp"

int main(int argc, char* argv[]) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new ES(0.5, 0.5, strategy);

	Problem * problem = new AverageFragProblem(model, 2, 2, 4, 2, false);
	problem->run(runSilent);
}
