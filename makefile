CC=g++
CFLAGS=-I.

#All source files used by main test file
_SRC = input_parse_en.cpp process_en.cpp function_en.cpp
SRC= $(patsubst %,src/%,$(_SRC))

#Name of main test file
MAIN = src/compile_en.cpp

compile: $(MAIN) $(SRC)
	g++ -o $@ $^ $(CFLAGS)