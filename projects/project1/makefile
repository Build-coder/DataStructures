CXX = g++
CXXFLAGS = -Wall -g -fmax-errors=1

# proj1: csr.o csrlist.o driver.cpp
# 		$(CXX) $(CXXFLAGS) csr.o csrlist.o driver.cpp -o proj1

proj1: csr.o csrlist.o mytest.cpp
		$(CXX) $(CXXFLAGS) csr.o csrlist.o mytest.cpp -o proj1		

csrlist.o: csrlist.h csrlist.cpp csr.o
		$(CXX) $(CXXFLAGS) -c csrlist.cpp

csr.o: csr.h csr.cpp
		$(CXX) $(CXXFLAGS) -c csr.cpp

clean:

		rm *.o
		rm *~
		rm *output*

rm_h:

		rm *.h

run:
		./proj1

val:
		# valgrind --track-origins=yes --leak-check=full -s ./proj1
		valgrind ./proj1

gdb:
		gdb --quiet -tui --args ./proj1