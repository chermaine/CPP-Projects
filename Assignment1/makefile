test: Grid.o Ant.o validate.o menu.o main.o
	g++ -std=c++0x Grid.o Ant.o validate.o menu.o main.o -o test

Grid.o: Grid.hpp Grid.cpp
	g++ -c Grid.cpp 

Ant.o: Ant.hpp Ant.cpp
	g++ -c Ant.cpp

validate.o: validate.hpp validate.cpp
	g++ -c validate.cpp

menu.o: menu.hpp menu.cpp
	g++ -c menu.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *o test
