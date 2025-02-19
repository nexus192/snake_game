# Компиляторы
CC = gcc
CXX = g++

# Флаги для компиляции
CFLAGS = -Wall -Wextra -Werror
CXXFLAGS = -Wall -Werror -Wextra -std=c++17

# Директории
SRC_DIR = src
BUILD_DIR = build
TETRIS_OBJ_DIR = $(BUILD_DIR)/object_files_for_tetris
SNAKE_OBJ_DIR = $(BUILD_DIR)/object_files_for_snake

# Исходные файлы
TETRIS_BACKEND_FILE = $(SRC_DIR)/BrickGame/BackEnd_Tetris/back_end.c
TETRIS_FRONTEND_FILE = $(SRC_DIR)/gui/cli/front.c
TETRIS_CONTROLER_FILE = $(SRC_DIR)/controller/controller_tetris.c
SNAKE_BACKEND_FILE = $(SRC_DIR)/BrickGame/BackEnd_Snake/Backend_snake.cc
SNAKE_CONTROLER_FILE = $(SRC_DIR)/controller/controller_snake.cc
MAIN_FILE = $(SRC_DIR)/BrickGame/main.cc

# Объектные файлы
TETRIS_OBJ_FILES = $(TETRIS_OBJ_DIR)/back_end.o
SNAKE_OBJ_FILES = $(SNAKE_OBJ_DIR)/Backend_snake.o
TETRIS_FRONTEND_OBJ = $(TETRIS_OBJ_DIR)/front_end.o
TETRIS_CONTROLER_OBJ = $(TETRIS_OBJ_DIR)/controller_tetris.o

# Архивы (статические библиотеки)
TETRIS_LIB = $(BUILD_DIR)/tetris.a
SNAKE_LIB = $(BUILD_DIR)/snake.a

# Цель по умолчанию
all: $(BUILD_DIR) $(TETRIS_LIB) $(SNAKE_LIB) install

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR) $(TETRIS_OBJ_DIR) $(SNAKE_OBJ_DIR)


$(TETRIS_OBJ_DIR)/back_end.o: $(TETRIS_BACKEND_FILE) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TETRIS_OBJ_DIR)/front_end.o: $(TETRIS_FRONTEND_FILE) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TETRIS_OBJ_DIR)/controller_tetris.o:	$(TETRIS_CONTROLER_FILE) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@	

$(SNAKE_OBJ_DIR)/Backend_snake.o: $(SNAKE_BACKEND_FILE) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@


$(TETRIS_LIB): $(TETRIS_OBJ_FILES)
	ar rcs $@ $^


$(SNAKE_LIB): $(SNAKE_OBJ_FILES)
	ar rcs $@ $^

install: $(TETRIS_FRONTEND_OBJ) $(TETRIS_CONTROLER_OBJ) $(TETRIS_LIB) $(SNAKE_LIB)
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/tetris $(MAIN_FILE) $(TETRIS_CONTROLER_OBJ)  $(TETRIS_FRONTEND_OBJ) $(SNAKE_CONTROLER_FILE) $(TETRIS_LIB) $(SNAKE_LIB) -lncurses -lm

clean:
	rm -rf $(BUILD_DIR)
