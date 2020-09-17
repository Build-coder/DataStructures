CXX = g++
CXXFLAGS = -Wall -g -fmax-errors=1

mytest: mytest.cpp queue.h
		$(CXX) $(CXXFLAGS) mytest.cpp queue.h -o mytest

clean:

		rm *.o
		rm *~
		rm *output*

run:
		./mytest

val:
		valgrind --track-origins=yes --leak-check=full -s ./mytest

gdb:
		gdb --quiet -tui --args ./mytest