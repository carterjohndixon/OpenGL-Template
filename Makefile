SRC_DIR = src
BUILD_DIR = build/debug
RELEASE_DIR = build/release
CC = g++
SRC_FILES = $(wildcard src/*.cpp) $(wildcard src/utils/*.cpp) $(wildcard glad/*.cpp)
OBJ_NAME = GlTest
INCLUDE_PATHS = -Iinclude
LIBRARY_PATHS = -Llib
COMPILER_FLAGS = -std=c++20 -Wall -O0 -g
RELEASE_FLAGS = -std=c++20 -Wall -O3 -g
LINKER_FLAGS = -lglfw -lGLEW -framework OpenGL

all:
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)
run:
	./$(BUILD_DIR)/$(OBJ_NAME)
release:
	$(CC) $(RELEASE_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(RELEASE_DIR)/$(OBJ_NAME)
release_run:
	./$(RELEASE_DIR)/$(OBJ_NAME)
