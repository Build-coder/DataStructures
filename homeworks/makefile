CXX = g++
CXXFLAGS = -Wall -g -fmax-errors=1

hw1: hw1.cpp 
		$(CXX) $(CXXFLAGS) hw1.cpp -o hw1

clean:

		rm *.o
		m *~
		rm *output*

run:
		./hw1

val:
		valgrind --track-origins=yes --leak-check=full ./hw1

gdb:
		gdb --quiet -tui --args ./hw1