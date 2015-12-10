CPPC = g++
CPPFLAGS = -c -g -std=gnu++0x -fPIC
INCLUDE = -Iinclude

SHAREDLIB = -lHierGA

info:
	@echo "Usage:"

common: experiment problem

experiment:
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/common/experiment/HierExperiment.cpp -o obj/HierExperiment.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/common/experiment/ClassicalExperiment.cpp -o obj/ClassicalExperiment.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/common/experiment/TwoLevelExperiment.cpp -o obj/TwoLevelExperiment.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/common/experiment/ThreeLevelExperiment.cpp -o obj/ThreeLevelExperiment.o

problem:
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/common/problem/Problem.cpp -o obj/Problem.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/common/problem/1maxProblem.cpp -o obj/1maxProblem.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/common/problem/LongFragProblem.cpp -o obj/LongFragProblem.o
	

clean:
	find obj -name *.o | xargs rm -f
