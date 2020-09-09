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
		./proj0 driver.txt

run2:
		./mytest driver2.txt

val1:
		valgrind ./proj0 driver.txt

val2:
		valgrind ./mytest driver2.txt

gdb1:
		gdb --quiet -tui --args ./proj0 driver.txt

gdb2:
		gdb --quiet -tui --args ./mytest driver2.txt