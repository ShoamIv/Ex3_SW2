CXX=clang++
CXXFLAGS=-std=c++11 -Werror
VALGRIND_FLAGS=--leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --error-exitcode=99

# Define the sources
SOURCES = Board.cpp Catan.cpp City.cpp Deck.cpp Edge.cpp Hexagon.cpp Knight.cpp \
          Monopoly.cpp Player.cpp Point.cpp Road_building.cpp Road.cpp \
          Settlement.cpp VictoryPoint.cpp Year_Of_Plenty.cpp

# Define the headers
HEADERS = Board.hpp Catan.hpp City.hpp Deck.hpp Edge.hpp Hexagon.hpp Knight.hpp \
          Monopoly.hpp Player.hpp Point.hpp Road_building.hpp Road.hpp Settlement.hpp \
          VictoryPoint.hpp Year_Of_Plenty.hpp 

# Define the main sources (including main.cpp)
MAIN_SOURCES = $(SOURCES) main.cpp

# Define the test sources (excluding main.cpp)
TEST_SOURCES = $(SOURCES) Test.cpp TestCounter.cpp

# Define the object files
MAIN_OBJECTS = $(MAIN_SOURCES:.cpp=.o)
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

# Define the executables
EXECUTABLE = catan_game
TEST_EXECUTABLE = run_tests

# Default rule
all: $(EXECUTABLE)

# Run tests rule
test: $(TEST_EXECUTABLE)
#	./$(TEST_EXECUTABLE)

# Rule for linking the main executable
$(EXECUTABLE): $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule for linking the test executable
$(TEST_EXECUTABLE): $(filter-out main.o,$(TEST_OBJECTS))
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule for compiling object files with corresponding headers
%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule for compiling object files without corresponding headers
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

valgrind_test: $(TEST_EXECUTABLE)
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./run_tests 


valgrind_catan: $(EXECUTABLE)
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./catan_game
#2>&1 | { egrep "lost| at " || true; }


# Clean rule
clean:
	rm -f $(MAIN_OBJECTS) $(TEST_OBJECTS) $(EXECUTABLE) $(TEST_EXECUTABLE)
