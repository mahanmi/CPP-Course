SRC_DIR = src
BUILD_DIR = build/debug
CC = g++
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_NAME = output
INCLUDE_PATHS = -Iinc
LIBRARY_PATHS = -Llib/SDL2 -Llib/SDL2_image -Llib/SDL2_mixer -Llib/SDL2_ttf -Llib/SDL2_gfx
COMPILER_FLAGS = -std=c++11 -Wall -o0 -g
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lSDL2_gfx

all: 
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)