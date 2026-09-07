CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
LIBS = -lncurses
TARGET = main
OBJS = main.o frontend/*.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) main.o frontend/*.o