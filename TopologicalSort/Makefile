#Usage: after running make, run with ./secondFrequent
CFLAGS =  -std=c++11

topologicalSort: detectCycle.o
	g++ $(CFLAGS) detectCycle.o -o topologicalSort

detectCycle.o: src/detectCycle.cpp lib/detect_cycle.h
	g++ -c $(CFLAGS) src/detectCycle.cpp

clean:
	rm -f *.o



