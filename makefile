CXX = g++
CXXFLAGS = -std=c++17 -Wall -g  -fno-omit-frame-pointer -Iinclude -Iinclude/board -Iinclude/obstacles
LDFLAGS = -lfltk 

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Inclure main.cpp et les autres fichiers sources
SOURCES = main.cpp $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/board/*.cpp) $(wildcard $(SRC_DIR)/obstacles/*.cpp)
OBJECTS = $(addprefix $(OBJ_DIR)/, $(notdir $(SOURCES:.cpp=.o)))
TARGET = $(BIN_DIR)/frogger

all: $(TARGET)

$(TARGET): $(OBJECTS)
	mkdir -p $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

# Règle pour compiler les fichiers objets, y compris ceux dans des sous-dossiers
$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/board/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/obstacles/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all c
