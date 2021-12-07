CXX = g++
CXXFLAGS = -std=c++14 -Wall -g -MMD
LDLIBS = -lncurses
EXEC = myexec
SRC = .
SOURCES = $(wildcard $(SRC)/*.cc)
OBJECTS = ${SOURCES:.cc=.o}
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC} ${LDLIBS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
