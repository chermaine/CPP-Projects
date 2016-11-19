test: Creature.o Barbarian.o HarryPotter.o Medusa.o BabaYaga.o BlueMen.o Queue.o Stack.o utility.o game.o main.o
	g++ -std=c++0x Creature.o Barbarian.o HarryPotter.o Medusa.o BabaYaga.o BlueMen.o Queue.o Stack.o utility.o game.o main.o -o test

Creature.o: Creature.hpp Creature.cpp
	g++ -c Creature.cpp 

Barbarian.o: Barbarian.hpp Barbarian.cpp
	g++ -c Barbarian.cpp

HarryPotter.o: HarryPotter.hpp HarryPotter.cpp
	g++ -c HarryPotter.cpp

Medusa.o: Medusa.hpp Medusa.cpp
	g++ -c Medusa.cpp

BabaYaga.o: BabaYaga.hpp BabaYaga.cpp
	g++ -c BabaYaga.cpp

BlueMen.o: BlueMen.hpp BlueMen.cpp
	g++ -c BlueMen.cpp

Queue.o: Queue.hpp Queue.cpp
	g++ -c Queue.cpp

Stack.o: Stack.hpp Stack.cpp
	g++ -c Stack.cpp

utility.o: utility.hpp utility.cpp
	g++ -c utility.cpp

game.o: game.hpp game.cpp
	g++ -c game.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *o test
