CXX = g++
CXXFLAGS = -Wall -g -fmax-errors=1

proj2: bNode.o wordTree.o bookTree.o myTest.cpp
		$(CXX) $(CXXFLAGS) bNode.o wordTree.o bookTree.o myTest.cpp -o proj2

# splay tree
bookTree: bookTree.h bookTree.cpp bNode.o
		$(CXX) $(CXXFLAGS) -c bookTree.cpp

# avl tree
bNode: bNode.h bNode.cpp wordTree.o
		$(CXX) $(CXXFLAGS) -c bNode.cpp

wordTree: wordTree.h wordTree.cpp
		$(CXX) $(CXXFLAGS) -c wordTree.cpp -o wordTree.o

clean:

		rm *.o
		rm *~
		rm *output*

run:
		./proj2

val:
		# valgrind --track-origins=yes --leak-check=full -s ./proj1
		valgrind ./proj2

gdb:
		gdb --quiet -tui --args ./proj2