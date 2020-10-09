CXX = g++
CXXFLAGS = -Wall -g -fmax-errors=1

avlTree: node.o driver.cpp
		$(CXX) $(CXXFLAGS) node.o driver.cpp -o avlTree		

node.o: node.h node.cpp
		$(CXX) $(CXXFLAGS) -c node.cpp

clean:
		rm *.o
		rm *~
		rm *output*

run:
		./avlTree

val:
		valgrind --track-origins=yes --leak-check=full -s ./run
		valgrind ./run

gdb:
		gdb --quiet -tui --args ./run
