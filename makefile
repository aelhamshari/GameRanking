GameRank: main.o Executive.o Game.o
	g++ -std=c++11 -g -Wall main.o Executive.o Game.o -o GameRank

main.o: main.cpp Executive.h Game.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

Game.o: Game.h Game.cpp
	g++ -std=c++11 -g -Wall -c Game.cpp
clean:
	rm *.o GameRank
