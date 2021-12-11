CXX = g++
CXXFLAGS = -Wall -std=c++2a -MMD -g # std=c++2a <=> std=c++20

SRC = ./age
GAME1 = ./arlg

SOURCES = $(shell find $(SRC) -name '*.cc')
GAME1_SOURCES = $(shell find $(GAME1) -name '*.cc')
OBJECTS = ${SOURCES:.cc=.o}
GAME1_OBJECTS = ${GAME1_SOURCES:.cc=.o}
DEPENDS = ${OBJECTS:.o=.d}
GAME1_DEPENDS = ${GAME1_OBJECTS:.o=.d}

all: game1

game1: $(OBJECTS) $(GAME1_OBJECTS)
    $(CXX) $(OBJECTS) $(GAME1_OBJECTS) -o arlg -lncurses

-include ${DEPENDS} $(GAME1_DEPENDS)

.PHONY: clean

clean:
    rm ${OBJECTS} ${DEPENDS} ${GAME1_OBJECTS} ${GAME1_DEPENDS} game1
