BUILD_DIR = build
CC = g++
SRC_DIR ?= src
FILE_NAME ?= main.cpp
SRC_FILES = $(wildcard $(SRC_DIR)/$(FILE_NAME))
OBJ_NAMES = $(patsubst $(SRC_DIR)/%.cpp,%,$(SRC_FILES))
INCLUDE_PATHS = -I/Users/mahan/Documents/VS\ Code/C++/SDL/include
LIB_DIR = /Users/mahan/Documents/VS\ Code/C++/SDL/lib
LIBRARY_PATHS = -L${LIB_DIR}/SDL2 -L${LIB_DIR}/SDL2_image -L${LIB_DIR}/SDL2_mixer -L${LIB_DIR}/SDL2_ttf -L${LIB_DIR}/SDL2_gfx
COMPILER_FLAGS = -std=c++11 -Wall -O0 -g
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lSDL2_gfx

all: $(OBJ_NAMES)

$(OBJ_NAMES): %: $(SRC_DIR)/%.cpp
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $< -o $(BUILD_DIR)/$@
