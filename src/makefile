CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -Werror -std=c11
FLAGS = -Wall -Werror -Wextra -std=c++17

TETRIS_BACKEND_FILE = $(wildcard BrickGame/BackEnd_Tetris/back_end.c)
TETRIS_FRONTEND_FILE = $(wildcard gui/cli/Tetris/front_end.c)
TETRIS_OBJ_DIR = object_files_for_tetris
TETRIS_OBJ_FILES = $(addprefix $(TETRIS_OBJ_DIR)/, $(notdir $(TETRIS_BACKEND_FILE:.c=.o)))
TETRIS_LIB = tetris.a

SNAKE_BACKEND_FILE = $(wildcard BrickGame/BackEnd_Snake/Backend_snake.cpp)
SNAKE_FRONTEND_FILE = $(wildcard gui/cli/Snake/Frontend_Snake.cpp)
SNAKE_OBJ_DIR = object_files_for_snake
SNAKE_OBJ_FILES = $(addprefix $(SNAKE_OBJ_DIR)/, $(notdir $(SNAKE_BACKEND_FILE:.cpp=.o)))
SNAKE_LIB = snake.a

all: $(TETRIS_LIB) $(SNAKE_LIB) install

install: 
	$(CC) $(CFLAGS) -o tetris ./BrickGame/BackEnd_Tetris/tetris.c tetris.a $(TETRIS_FRONTEND_FILE) -lncurses -lm
	$(CXX) $(FLAGS) -o snake ./BrickGame/BackEnd_Snake/snake_game.cpp snake.a $(SNAKE_FRONTEND_FILE) -lncurses
	rm -rf $(TETRIS_OBJ_DIR)
	rm -rf $(SNAKE_OBJ_DIR)

$(TETRIS_LIB): $(TETRIS_OBJ_FILES)
	@ar rcs $@ $^ 

$(SNAKE_LIB): $(SNAKE_OBJ_FILES)
	@ar rcs $@ $^ 

$(TETRIS_OBJ_DIR)/%.o: ./BrickGame/BackEnd_Tetris/%.c
	@mkdir -p $(TETRIS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(SNAKE_OBJ_DIR)/%.o: ./BrickGame/BackEnd_Snake/%.cpp
	@mkdir -p $(SNAKE_OBJ_DIR)
	$(CXX) $(FLAGS) -c $< -o $@

clean: 
	rm -f ./snake
	rm -f ./tetris
	rm -f $(TETRIS_LIB)
	rm -f $(SNAKE_LIB)
	rm -rf $(TETRIS_OBJ_DIR)
	rm -rf $(SNAKE_OBJ_DIR)