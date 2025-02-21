#━━━━━━━━━━Компиляторы━━━━━━━━━━
CC = gcc
CXX = g++

#━━━━━━━━━━Флаги для компиляции━━━━━━━━━━
CFLAGS = -Wall -Wextra -Werror
CXXFLAGS = -Wall -Werror -Wextra -std=c++17

#━━━━━━━━━━Директории━━━━━━━━━━
SRC_DIR = src
BUILD_DIR = build
TETRIS_OBJ_DIR = $(BUILD_DIR)/object_files_for_tetris
SNAKE_OBJ_DIR = $(BUILD_DIR)/object_files_for_snake

#━━━━━━━━━━Исходные файлы━━━━━━━━━━
TETRIS_BACKEND_FILE = $(SRC_DIR)/BrickGame/tetris/back_end.c
TETRIS_FRONTEND_FILE = $(SRC_DIR)/gui/cli/front.c
TETRIS_CONTROLER_FILE = $(SRC_DIR)/controller/controller_tetris.c
SNAKE_BACKEND_FILE = $(SRC_DIR)/BrickGame/snake/Backend_snake.cc
SNAKE_CONTROLER_FILE = $(SRC_DIR)/controller/controller_snake.cc
CLI_MAIN_FILE = $(SRC_DIR)/cli_main.cc
SNAKE_TESTS = $(TESTS_SRC_DIR)/snake/s21_snake_tests.cc
TETRIS_TESTS = $(TESTS_SRC_DIR)/tetris/run_tests.c

#━━━━━━━━━━Объектные файлы━━━━━━━━━━
TETRIS_OBJ_FILES = $(TETRIS_OBJ_DIR)/back_end.o
SNAKE_OBJ_FILES = $(SNAKE_OBJ_DIR)/Backend_snake.o
TETRIS_FRONTEND_OBJ = $(TETRIS_OBJ_DIR)/front_end.o
TETRIS_CONTROLER_OBJ = $(TETRIS_OBJ_DIR)/controller_tetris.o

#━━━━━━━━━━Архивы (статические библиотеки)━━━━━━━━━━
TETRIS_LIB = $(BUILD_DIR)/tetris.a
SNAKE_LIB = $(BUILD_DIR)/snake.a

#━━━━━━━━━━Конфигурация тестов и покрытия кода━━━━━━━━━━
TESTS_LINKER_FLAGS_CHECK:= -lcheck -lsubunit -lm
TESTS_LINKER_FLAGS_GTEST := -lgtest_main -lgtest -pthread
COVERAGE_FLAGS := -fprofile-arcs -ftest-coverage
GCOVR_THEME := --html-theme github.dark-green
GCOVR_CONFIG_FLAGS := --html --html-single-page=js-enabled --html-details
GCOVR_EXCLUDES := --exclude-unreachable-branches --exclude-throw-branches --exclude-noncode-lines
GCOVR_FILTER := --filter=src
GCOVR_FLAGS := $(GCOVR_CONFIG_FLAGS) $(GCOVR_EXCLUDES) $(GCOVR_THEME) $(GCOVR_FILTER)

#━━━━━━━━━━Структура директорий━━━━━━━━━━
TESTS_SRC_DIR := tests
BUILD_DIR := build
TESTS_BUILD_DIR := $(BUILD_DIR)/tests
COVERAGE_DIR := $(BUILD_DIR)/coverage

#━━━━━━━━━━Цель по умолчанию━━━━━━━━━━
all: $(BUILD_DIR) $(TETRIS_LIB) $(SNAKE_LIB) install

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR) $(TETRIS_OBJ_DIR) $(SNAKE_OBJ_DIR)

#━━━━━━━━━━Компиляция объектных файлов━━━━━━━━━━
$(TETRIS_OBJ_DIR)/back_end.o: $(TETRIS_BACKEND_FILE) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TETRIS_OBJ_DIR)/front_end.o: $(TETRIS_FRONTEND_FILE) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TETRIS_OBJ_DIR)/controller_tetris.o: $(TETRIS_CONTROLER_FILE) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(SNAKE_OBJ_DIR)/Backend_snake.o: $(SNAKE_BACKEND_FILE) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

#━━━━━━━━━━Создание статических библиотек━━━━━━━━━━
$(TETRIS_LIB): $(TETRIS_OBJ_FILES)
	ar rcs $@ $^

$(SNAKE_LIB): $(SNAKE_OBJ_FILES)
	ar rcs $@ $^

#━━━━━━━━━━Установка━━━━━━━━━━
install: $(TETRIS_FRONTEND_OBJ) $(TETRIS_CONTROLER_OBJ) $(TETRIS_LIB) $(SNAKE_LIB)
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/BrickGame $(CLI_MAIN_FILE) $(TETRIS_CONTROLER_OBJ) $(TETRIS_FRONTEND_OBJ) $(SNAKE_CONTROLER_FILE) $(TETRIS_LIB) $(SNAKE_LIB) -lncurses -lm

#━━━━━━━━━━Тестирование━━━━━━━━━━
test: $(BUILD_DIR)/cli_snake_tests $(BUILD_DIR)/cli_tetris_tests
	$(BUILD_DIR)/cli_snake_tests
	$(BUILD_DIR)/cli_tetris_tests

$(BUILD_DIR)/cli_snake_tests: $(SNAKE_TESTS) $(SNAKE_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(TESTS_LINKER_FLAGS_GTEST)

$(BUILD_DIR)/cli_tetris_tests: $(TETRIS_TESTS) tests/tetris/backend_tests.c $(TETRIS_LIB)
	$(CC) $(CFLAGS) -o $@ $^ $(TESTS_LINKER_FLAGS_CHECK) -lncurses

#━━━━━━━━━━Покрытие кода (Coverage)━━━━━━━━━━
coverage: CXXFLAGS += $(COVERAGE_FLAGS)
coverage: CFLAGS += $(COVERAGE_FLAGS)
coverage: clean test $(BUILD_DIR)/cli_snake_tests $(BUILD_DIR)/cli_tetris_tests
	./$(BUILD_DIR)/cli_snake_tests
	./$(BUILD_DIR)/cli_tetris_tests
	mkdir -p $(COVERAGE_DIR)
	@gcovr -o $(COVERAGE_DIR)/gcov_report.html $(GCOVR_FLAGS)
	open $(COVERAGE_DIR)/gcov_report.html

#━━━━━━━━━━Очистка━━━━━━━━━━
clean:
	rm -rf $(BUILD_DIR)
