CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
LIBS = -lncurses
TARGET = main
BIN_DIR = bin

# Find all C++ source files across directories
SRCS = main.cpp $(wildcard frontend/*.cpp) $(wildcard backend/*.cpp)

# Place all object files (intermediate binaries) into the bin folder
OBJS = $(addprefix $(BIN_DIR)/, $(notdir $(SRCS:.cpp=.o)))

# Tell Make where to look for source files in subdirectories
vpath %.cpp . frontend backend

all: $(BIN_DIR) $(TARGET)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LIBS)

# Pattern rule handling builds into the bin folder correctly
$(BIN_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(TARGET) $(BIN_DIR)