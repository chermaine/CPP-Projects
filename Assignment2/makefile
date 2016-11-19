test: Item.o List.o validate.o menu.o main.o
	g++ -std=c++0x Item.o List.o validate.o menu.o main.o -o test

Item.o: Item.hpp Item.cpp
	g++ -c Item.cpp 

List.o: List.hpp List.cpp
	g++ -c List.cpp

validate.o: validate.hpp validate.cpp
	g++ -c validate.cpp

menu.o: menu.hpp menu.cpp
	g++ -c menu.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *o test
