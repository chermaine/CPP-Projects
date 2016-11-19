test: Space.o Office.o Lobby.o Cafeteria.o BreakRoom.o ConferenceRoom.o Kitchen.o Basement.o Rooftop.o Object.o Character.o utility.o game.o main.o
	g++ -std=c++0x Space.o Office.o Lobby.o Cafeteria.o BreakRoom.o ConferenceRoom.o Kitchen.o Basement.o Rooftop.o Object.o Character.o utility.o game.o main.o -o test

Space.o: Space.hpp Space.cpp
	g++ -c Space.cpp 

Office.o: Office.hpp Office.cpp
	g++ -c Office.cpp

Lobby.o: Lobby.hpp Lobby.cpp
	g++ -c Lobby.cpp

Cafeteria.o: Cafeteria.hpp Cafeteria.cpp
	g++ -c Cafeteria.cpp

BreakRoom.o: BreakRoom.hpp BreakRoom.cpp
	g++ -c BreakRoom.cpp

ConferenceRoom.o: ConferenceRoom.hpp ConferenceRoom.cpp
	g++ -c ConferenceRoom.cpp

Kitchen.o: Kitchen.hpp Kitchen.cpp
	g++ -c Kitchen.cpp

Basement.o: Basement.hpp Basement.cpp
	g++ -c Basement.cpp

Rooftop.o: Rooftop.hpp Rooftop.cpp
	g++ -c Rooftop.cpp

Object.o: Object.hpp Object.cpp
	g++ -c Object.cpp

Character.o: Character.hpp Character.cpp
	g++ -c Character.cpp

utility.o: utility.hpp utility.cpp
	g++ -c utility.cpp

game.o: game.hpp game.cpp
	g++ -c game.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *o test
