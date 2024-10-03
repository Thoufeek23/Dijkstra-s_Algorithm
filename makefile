CXX = g++
CXXFLAGS = -Wall -g
TARGET = dijkstra_program
OBJ = main.o dijkstra.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

main.o: main.cpp dijkstra.h
	$(CXX) $(CXXFLAGS) -c main.cpp

dijkstra.o: dijkstra.cpp dijkstra.h
	$(CXX) $(CXXFLAGS) -c dijkstra.cpp

clean:
	rm -f $(OBJ) $(TARGET)
