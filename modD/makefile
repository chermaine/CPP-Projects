CXX = g++
CXXFLAGS = -std=c++0x

test: Critter.o Ant.o Doodlebug.o Grid.o main.o
	${CXX} ${CXXFLAGS} Critter.o Ant.o Doodlebug.o Grid.o main.o -o test

Critter.o: Critter.cpp Critter.hpp
	${CXX} -c Critter.cpp

Ant.o: Ant.cpp Ant.hpp
	${CXX} -c Ant.cpp

Doodlebug.o: Doodlebug.cpp Doodlebug.hpp
	${CXX} -c Doodlebug.cpp

Grid.o: Grid.cpp Grid.hpp
	${CXX} -c Grid.cpp

main.o: main.cpp
	${CXX} -c main.cpp

clean:
	rm *o test
