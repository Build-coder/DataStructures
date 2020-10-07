CXX = g++
CXXFLAGS = -Wall -g -fmax-errors=1

proj2: bNode.o wordTree.o bookTree.o driver.cpp
		$(CXX) $(CXXFLAGS) bNode.o wordTree.o bookTree.o driver.cpp -o proj2		

# splay tree
bookTree.o: bookTree.h bookTree.cpp wordTree.o
		$(CXX) $(CXXFLAGS) -c bookTree.cpp

# avl tree
wordTree.o: wordTree.h wordTree.cpp bNode.o
		$(CXX) $(CXXFLAGS) -c wordTree.cpp

bNode.o: bNode.h bNode.cpp
		$(CXX) $(CXXFLAGS) -c bNode.cpp

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