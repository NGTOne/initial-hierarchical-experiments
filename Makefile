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
	$(CPPC) $(OBJCPPFLAGS) $(INCLUDE) src/common/experiment/FiveLevelExperiment.cpp -o obj/FiveLevelExperiment.o

problem:
	$(CPPC) $(OBJCPPFLAGS) $(INCLUDE) src/common/problem/Problem.cpp -o obj/Problem.o
	$(CPPC) $(OBJCPPFLAGS) $(INCLUDE) src/common/problem/1maxProblem.cpp -o obj/1maxProblem.o
	$(CPPC) $(OBJCPPFLAGS) $(INCLUDE) src/common/problem/LongFragProblem.cpp -o obj/LongFragProblem.o
	$(CPPC) $(OBJCPPFLAGS) $(INCLUDE) src/common/problem/AverageFragProblem.cpp -o obj/AverageFragProblem.o

fitnesses:
	$(CPPC) $(OBJCPPFLAGS) $(INCLUDE) src/common/1max/1maxFitness.cpp -o obj/1maxFitness.o
	$(CPPC) $(OBJCPPFLAGS) $(INCLUDE) src/common/1max/Hier1maxFitness.cpp -o obj/Hier1maxFitness.o
	$(CPPC) $(OBJCPPFLAGS) $(INCLUDE) src/common/LongFrag/LongFragFitness.cpp -o obj/LongFragFitness.o
	$(CPPC) $(OBJCPPFLAGS) $(INCLUDE) src/common/LongFrag/HierLongFragFitness.cpp -o obj/HierLongFragFitness.o
	$(CPPC) $(OBJCPPFLAGS) $(INCLUDE) src/common/AverageFrag/AverageFragFitness.cpp -o obj/AverageFragFitness.o
	$(CPPC) $(OBJCPPFLAGS) $(INCLUDE) src/common/AverageFrag/HierAverageFragFitness.cpp -o obj/HierAverageFragFitness.o

experiments:
	./compile-scripts/setup-experiments.sh

clean:
	rm -rf obj/*
	rm -rf experiments
