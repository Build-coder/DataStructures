CXX = g++
CXXFLAGS = -Wall -g -fmax-errors=1
# proj0: driver.cpp queue.h
# 		$(CXX) $(CXXFLAGS) driver.cpp queue.h -o proj0

mytest: mytest.cpp queue.h
		$(CXX) $(CXXFLAGS) mytest.cpp queue.h -o mytest

clean:

		rm *.o
		m *~
		rm *output*

run1:
		./proj0

run2:
		./mytest

val1:
		valgrind --leak-check=full ./proj0

val2:
		valgrind --track-origins=yes --leak-check=full ./mytest

gdb1:
		gdb --quiet -tui --args ./proj0

gdb2:
		gdb --quiet -tui --args ./mytest