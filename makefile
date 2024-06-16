#id:206698359    mail:shoamivgi1234@gmail.com

CXX=clang++
CXXFLAGS=-std=c++11 -Werror
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

# Define the sources
SOURCES = Board.cpp Catan.cpp City.cpp Deck.cpp Edge.cpp Hexagon.cpp Knight.cpp \
          Monopoly.cpp Player.cpp Point.cpp Road_building.cpp Road.cpp \
          Settlement.cpp VictoryPoint.cpp Year_Of_Plenty.cpp main.cpp

# Define the test sources
TEST_SOURCES = Test.cpp

# Define the headers
HEADERS = Board.hpp Catan.hpp City.hpp Deck.hpp Edge.hpp Hexagon.hpp Knight.hpp \
          Monopoly.hpp Player.hpp Point.hpp Road_building.hpp Road.hpp Settlement.hpp \
          VictoryPoint.hpp Year_Of_Plenty.hpp doctest.h

# Define the object files
OBJECTS = $(SOURCES:.cpp=.o)
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

# Define the executables
EXECUTABLE = catan_game
TEST_EXECUTABLE = run_tests

# Default rule
all: $(EXECUTABLE) $(TEST_EXECUTABLE)

# Rule for linking the main executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule for linking the test executable
$(TEST_EXECUTABLE): $(OBJECTS) $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule for compiling object files
%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule for compiling test object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJECTS) $(TEST_OBJECTS) $(EXECUTABLE) $(TEST_EXECUTABLE)

# Run tests rule
test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)