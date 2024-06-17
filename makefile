# Variables
CXX = clang++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
# Source files
SRC = vertex.cpp player.cpp edge.cpp catan.cpp board.cpp main.cpp resource.cpp
OBJ=$(subst .cpp,.o,$(SRC)) # replace .cpp with .o in SOURCES
# Default target
all: catan

# Linking
catan: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJ) catan

# Run the program
run: catan
	./catan

.PHONY: all clean run
