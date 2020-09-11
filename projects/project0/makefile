CXX = g++
CXXFLAGS = -Wall -g -fmax-errors=1
# proj0: driver.cpp queue.h
# 		$(CXX) $(CXXFLAGS) driver.cpp queue.h -o proj0

# mytest: mytest.cpp queue.h
# 		$(CXX) $(CXXFLAGS) mytest.cpp queue.h -o mytest

mytest2: driver2.cpp queue.h
		$(CXX) $(CXXFLAGS) driver2.cpp queue.h -o mytest2

clean:

		rm *.o
		m *~
		rm *output*

run1:
		./proj0

run2:
		./mytest

run3:
		./mytest2

val1:
		valgrind --track-origins=yes --leak-check=full -s ./proj0

val2:
		valgrind --track-origins=yes --leak-check=full -s ./mytest

val3:
		valgrind --track-origins=yes --leak-check=full -s ./mytest2

gdb1:
		gdb --quiet -tui --args ./proj0

gdb2:
		gdb --quiet -tui --args ./mytest

gdb3:
		gdb --quiet -tui --args ./mytest2