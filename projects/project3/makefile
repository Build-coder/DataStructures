CXX = g++
CXXFLAGS = -Wall -g -fmax-errors=1

proj3: pqueue.o driver.cpp
		$(CXX) $(CXXFLAGS) pqueue.o driver.cpp -o proj3

pqueue: pqueue.h pqueue.cpp
		$(CXX) $(CXXFLAGS) -c pqueue.cpp -o pqueue.o

clean:

		rm *.o
		rm *~
		rm *output*

run:
		./proj3

val:
		# valgrind --track-origins=yes --leak-check=full -s ./proj1
		valgrind ./proj3

gdb:
		gdb --quiet -tui --args ./proj3
