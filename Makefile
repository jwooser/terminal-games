CXX = g++
CXXFLAGS = -Wall -std=c++14 -MMD -g

LDLIBS = -lncurses

AGE = age
ARLG = arlg
FLOB = floppybrad
ROOT = .

vpath %.cc $(AGE) $(ARLG) $(FLOB)

GAME1_SOURCES := $(wildcard $(AGE)/*.cc $(ARLG)/*.cc)
GAME1_SOURCES := $(notdir $(SOURCES))
GAME1_OBJECTS = ${SOURCES:.cc=.o}
GAME1_DEPENDS = ${OBJECTS:.o=.d}

GAME2_SOURCES := $(wildcard $(AGE)/*.cc $(FLOB)/*.cc)
GAME2_SOURCES := $(notdir $(SOURCES))
GAME2_OBJECTS = ${SOURCES:.cc=.o}
GAME2_DEPENDS = ${OBJECTS:.o=.d}

all: ${OBJECTS} game1 game2

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
	rm ${OBJECTS} ${DEPENDS} ${EXEC}

