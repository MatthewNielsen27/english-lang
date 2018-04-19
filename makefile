CC=g++
CFLAGS=-I. -std=c++11

#All source files used by main test file
_SRC = translate.cpp filestructure.cpp control_flow.cpp io.cpp variables.cpp native.cpp function.cpp data_structure.cpp
SRC= $(patsubst %,src/%,$(_SRC))

#Name of main test file
MAIN = src/compile.cpp

compile: $(MAIN) $(SRC)
	g++ -o $@ $^ $(CFLAGS)