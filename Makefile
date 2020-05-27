# Makefile for uwufy

CXX = g++
CXXFLAGS = -Wall -o2 -g -std=c++17 -Werror

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

uwufy: $(OBJ)
	mkdir -p build
	$(CXX) $(CXXFLAGS) -o build/$@ $^
	rm -f $(OBJ)