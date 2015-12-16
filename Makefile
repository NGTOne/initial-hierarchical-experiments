CPPC = g++
OBJCPPFLAGS = -c -g -std=gnu++0x -fPIC
EXPCPPFLAGS = -std=gnu++0x
INCLUDE = -Iinclude

SHAREDLIB = -lHierGA

info:
	@echo "Usage:"

all: common experiments

common: experiment problem fitnesses

experiment:
	$(CPPC) $(OBJCPPFLAGS) $(INCLUDE) src/common/experiment/HierExperiment.cpp -o obj/HierExperiment.o
	$(CPPC) $(OBJCPPFLAGS) $(INCLUDE) src/common/experiment/ClassicalExperiment.cpp -o obj/ClassicalExperiment.o
	$(CPPC) $(OBJCPPFLAGS) $(INCLUDE) src/common/experiment/TwoLevelExperiment.cpp -o obj/TwoLevelExperiment.o
	$(CPPC) $(OBJCPPFLAGS) $(INCLUDE) src/common/experiment/ThreeLevelExperiment.cpp -o obj/ThreeLevelExperiment.o
	$(CPPC) $(OBJCPPFLAGS) $(INCLUDE) src/common/experiment/FourLevelExperiment.cpp -o obj/FourLevelExperiment.o

problem:
	$(CPPC) $(OBJCPPFLAGS) $(INCLUDE) src/common/problem/Problem.cpp -o obj/Problem.o
	$(CPPC) $(OBJCPPFLAGS) $(INCLUDE) src/common/problem/1maxProblem.cpp -o obj/1maxProblem.o
	$(CPPC) $(OBJCPPFLAGS) $(INCLUDE) src/common/problem/LongFragProblem.cpp -o obj/LongFragProblem.o

fitnesses:
	$(CPPC) $(OBJCPPFLAGS) $(INCLUDE) src/common/1max/1maxFitness.cpp -o obj/1maxFitness.o
	$(CPPC) $(OBJCPPFLAGS) $(INCLUDE) src/common/1max/Hier1maxFitness.cpp -o obj/Hier1maxFitness.o
	$(CPPC) $(OBJCPPFLAGS) $(INCLUDE) src/common/LongFrag/LongFragFitness.cpp -o obj/LongFragFitness.o
	$(CPPC) $(OBJCPPFLAGS) $(INCLUDE) src/common/LongFrag/HierLongFragFitness.cpp -o obj/HierLongFragFitness.o

experiments:
	./compile-scripts/setup-experiments.sh

clean:
	rm -rf obj/*
	rm -rf experiments
