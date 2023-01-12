# Makefile
# Build rules for EECS 280 midterm

# Compiler
CXX ?= g++

# Compiler flags
# CXXFLAGS ?= --std=c++11 -Wall -pedantic -g
# CXXFLAGS ?= --std=c++11 -Wall -Werror -pedantic -g -Wno-sign-compare -Wno-comment
CXXFLAGS ?= --std=c++11 -Wall -Werror -pedantic -g -fsanitize=address -fsanitize=undefined

output_main: main.exe
	./main.exe > main_output.out

main.exe: main.cpp board.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

.SUFFIXES:

.PHONY: clean

clean:
	rm -rvf *.out *.exe *.dSYM *.stackdump