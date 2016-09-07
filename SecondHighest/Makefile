#Usage: after running make, run with ./secondFrequent
CFLAGS = -Wall -Werror -std=c++11

secondFrequent: secondFrequent.o
	g++ $(CFLAGS) secondFrequent.o -o secondFrequent

secondFrequent.o: src/secondFrequent.cpp lib/second_frequent.h
	g++ -c $(CFLAGS) src/secondFrequent.cpp

clean:
	rm -f *.o
