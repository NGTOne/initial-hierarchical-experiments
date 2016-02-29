#include "problem/1maxProblem.hpp"

int main(int argc, char* argv) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new SSGAGeneration(strategy);

	Problem * problem = new OneMaxProblem(model, 32);
	problem->run();
}
