
# Variables
CXX = clang++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Source files
SRC = vertex.cpp player.cpp edge.cpp catan.cpp board.cpp main.cpp resource.cpp card.cpp knightCard.cpp promotionCard.cpp victoryPointCard.cpp
OBJ = $(SRC:.cpp=.o)  # Replace .cpp with .o in SOURCES

# Default target
all: catan

# Linking
catan: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Test target
test: TestCounter.o Test.o $(filter-out main.o, $(OBJ))
	$(CXX) $(CXXFLAGS) $^ -o test

# Clean up
clean:
	rm -f $(OBJ) catan test 

# Run the program
run: catan
	./catan

.PHONY: all clean run test


