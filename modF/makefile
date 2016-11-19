CXX = g++
CXXFLAGS = -std=c++0x

test: Queue.o State.o validate.o main.o
	${CXX} ${CXXFLAGS} State.o Queue.o validate.o main.o -o test

Queue.o: Queue.hpp Queue.cpp
	${CXX} -c Queue.cpp

State.o: State.cpp State.hpp
	${CXX} -c State.cpp

validate.o: validate.hpp validate.cpp
	${CXX} -c validate.cpp

main.o: main.cpp
	${CXX} -c main.cpp

clean:
	rm *o test
