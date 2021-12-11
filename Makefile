CXX = g++
CXXFLAGS = -Wall -std=c++14 -MMD -g

EXEC = myexec
LDLIBS = -lncurses

AGE = age
ARLG = arlg
ROOT = .

vpath %.cc $(AGE) $(ARLG)

SOURCES := $(wildcard $(AGE)/*.cc $(ARLG)/*.cc)
SOURCES := $(notdir $(SOURCES))
OBJECTS = ${SOURCES:.cc=.o}
DEPENDS = ${OBJECTS:.o=.d}

all: ${OBJECTS} ${EXEC}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC} ${LDLIBS}

-include ${DEPENDS}

$(ROOT)/%.o: %.cc
	$(CXX) -c $(CXXFLAGS) -I ./age $< -o $@ ${LDLIBS} 

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}

