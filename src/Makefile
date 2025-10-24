CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall
TARGET = slm
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

run: $(TARGET)
	./$(TARGET) $(ARGS)

clean:
	rm -f $(OBJ) $(TARGET)
