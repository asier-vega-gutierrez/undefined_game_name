CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
LIBS = -lncurses
TARGET = main

# Find all C++ source files across directories
SRCS = main.cpp $(wildcard frontend/*.cpp) $(wildcard backend/*.cpp)

# Automatically derive object files from source files
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LIBS)

# Pattern rule handling builds in subdirectories correctly
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)