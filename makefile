CXX = g++
CXXFLAGS += -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g#

OBJS = inputValidation.o Menu.o Creature.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o PlayGame.o main.o

SRCS = inputValidation.cpp Menu.cpp Creature.cpp Vampire.cpp Barbarian.cpp BlueMen.cpp Medusa.cpp HarryPotter.cpp PlayGame.cpp main.cpp

HEADERS = inputValidation.h Menu.h Creature.h Vampire.h Barbarian.h BlueMen.h Medusa.h HarryPotter.h PlayGame.h

fantasyCombat: ${OBJS} ${HEADERS}
		${CXX} ${OBJS} -o fantasyCombat

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o fantasyCombat
