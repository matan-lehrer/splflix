#######################################################
# GENERIC MAKEFILE

# Prepare the following:
#		Create 2 folders:
#		* Source - move the source code to folder.
#		* Headers - move the header files to folder.
#	Modify <TARGET> - Name of executable

# RUN - "make compile" instead of "make"
#######################################################

TARGET = output
CXX = g++
CXXFLAGS = -g -Wall -Weffc++ -std=c++11 -I $(HDR_DIR)

HDR_DIR = Headers/
SRC_DIR = Source
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_DIR = Objects
OBJ = $(patsubst $(SRC_DIR/%.cpp),$(OBJ_DIR/%.o),$(SRC))


$(TARGET): $(OBJ)
		$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR): 
	mkdir -p $(OBJ_DIR)

compile: $(OBJ_DIR) $(OBJ) $(TARGET)


clean:
		rm -rf $(OBJ_DIR) $(TARGET)
