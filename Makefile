main: main.o Utility.o Space.o Bedroom.o Bathroom.o Hallway.o Kitchen.o \
	  LivingRoom.o PointOfInterest.o Player.o Game.o
	g++ -g main.o Utility.o Space.o Bedroom.o Bathroom.o Hallway.o \
		Kitchen.o LivingRoom.o PointOfInterest.o Player.o Game.o -o main

main.o: main.cpp
	g++ -c main.cpp

Utility.o: Utility.cpp Utility.hpp
	g++ -c Utility.cpp

Space.o: Space.cpp Space.hpp
	g++ -c Space.cpp

Bedroom.o: Bedroom.cpp Bedroom.hpp
	g++ -c Bedroom.cpp

Bathroom.o: Bathroom.cpp Bathroom.hpp
	g++ -c Bathroom.cpp

Hallway.o: Hallway.cpp Hallway.hpp
	g++ -c Hallway.cpp

Kitchen.o: Kitchen.cpp Kitchen.hpp
	g++ -c Kitchen.cpp

LivingRoom.o: LivingRoom.cpp LivingRoom.hpp
	g++ -c LivingRoom.cpp

PointOfInterest.o: PointOfInterest.cpp PointOfInterest.hpp
	g++ -c PointOfInterest.cpp

Player.o: Player.cpp Player.hpp
	g++ -c Player.cpp

Game.o: Game.cpp Game.hpp
	g++ -c Game.cpp

clean:
	rm *.o main
