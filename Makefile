CXX = g++
CXXFLAGS = -Wall -std=c++14 -MMD -g

LDLIBS = -lncurses

AGE = age
ARLG = arlg
FLOB = floppybrad
ROOT = .

vpath %.cc $(AGE) $(ARLG) $(FLOB)

GAME1_SOURCES := $(wildcard $(AGE)/*.cc $(ARLG)/*.cc)
GAME1_SOURCES := $(notdir $(GAME1_SOURCES))
GAME1_OBJECTS = ${GAME1_SOURCES:.cc=.o}
GAME1_DEPENDS = ${GAME1_OBJECTS:.o=.d}

GAME2_SOURCES := $(wildcard $(AGE)/*.cc $(FLOB)/*.cc)
GAME2_SOURCES := $(notdir $(GAME2_SOURCES))
GAME2_OBJECTS = ${GAME2_SOURCES:.cc=.o}
GAME2_DEPENDS = ${GAME2_OBJECTS:.o=.d}

all: ${GAME1_OBJECTS} ${GAME2_OBJECTS} game1 game2

game1: ${GAME1_OBJECTS}
	${CXX} ${GAME1_OBJECTS} -o game1 ${LDLIBS}

-include ${GAME1_DEPENDS}

game2: ${GAME2_OBJECTS}
	${CXX} ${GAME2_OBJECTS} -o game2 ${LDLIBS}

-include ${GAME2_DEPENDS}

$(ROOT)/%.o: %.cc
	$(CXX) -c $(CXXFLAGS) -I ./age $< -o $@ ${LDLIBS} 

.PHONY: clean

clean:
	rm ${GAME1_OBJECTS} ${GAME1_DEPENDS} ${GAME2_OBJECTS} ${GAME2_DEPENDS} game1 game2

