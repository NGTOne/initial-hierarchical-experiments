#include "problem/LongFragProblem.hpp"

int main(int argc, char* argv) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new GA(2, false, strategy);

	Problem * problem = new LongFragProblem(model, 4, 8, false);
	problem->run();
}
