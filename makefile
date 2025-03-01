#━━━━━━━━━━ Компиляторы ━━━━━━━━━━
CC  = gcc
CXX = g++
UIC = uic
MOC = moc

#━━━━━━━━━━ Флаги для компиляции ━━━━━━━━━━
CXXFLAGS = -std=c++17 -Wall -Wextra -fPIC $(shell pkg-config --cflags Qt5Widgets)
CFLAGS   = -Wall -Wextra -fPIC $(shell pkg-config --cflags Qt5Widgets)
LDFLAGS  = $(shell pkg-config --libs Qt5Widgets)

#━━━━━━━━━━ Директории ━━━━━━━━━━
SRC_DIR            = src
BUILD_DIR          = build
TETRIS_OBJ_DIR     = $(BUILD_DIR)/object_files_for_tetris
SNAKE_OBJ_DIR      = $(BUILD_DIR)/object_files_for_snake
DESKTOP_FILES_DIR  = $(BUILD_DIR)/desktop_files
TESTS_SRC_DIR      = tests
TESTS_BUILD_DIR    = $(BUILD_DIR)/tests
COVERAGE_DIR       = $(BUILD_DIR)/coverage
DESKTOP_DIR        = $(SRC_DIR)/gui/desktop

#━━━━━━━━━━ Исходные файлы ━━━━━━━━━━
TETRIS_BACKEND_FILE   = $(SRC_DIR)/BrickGame/tetris/tetris_backend.c
TETRIS_FRONTEND_FILE  = $(SRC_DIR)/gui/cli/front.c
TETRIS_CONTROLER_FILE = $(SRC_DIR)/gui/cli//controller_cli/controller_tetris_cli.c
SNAKE_BACKEND_FILE    = $(SRC_DIR)/BrickGame/snake/Backend_snake.cc
SNAKE_CONTROLER_FILE  = $(SRC_DIR)/gui/cli//controller_cli/controller_snake_cli.cc
CLI_MAIN_FILE         = $(SRC_DIR)/cli_main.cc
SNAKE_TESTS           = $(TESTS_SRC_DIR)/snake/s21_snake_tests.cc
TETRIS_TESTS          = $(TESTS_SRC_DIR)/tetris/run_tests.c

SRCS = $(SRC_DIR)/desktop_main.cc \
       $(DESKTOP_DIR)/mainwindow.cc \
       $(DESKTOP_DIR)/controller_desktop/controller_snake_desktop.cc \
       $(DESKTOP_DIR)/controller_desktop/controller_tetris_desktop.cc \
			 $(DESKTOP_DIR)/desktop_front.cc

HDRS = $(DESKTOP_DIR)/mainwindow.h \
       $(DESKTOP_DIR)/controller_desktop/controller_snake_desktop.h \
       $(DESKTOP_DIR)/controller_desktop/controller_tetris_desktop.h \
			 $(DESKTOP_DIR)/desktop_front.h

UI_FILES = $(DESKTOP_DIR)/mainwindow.ui

#━━━━━━━━━━ Объектные файлы ━━━━━━━━━━
TETRIS_OBJ_FILES      = $(TETRIS_OBJ_DIR)/tetris_backend.o
SNAKE_OBJ_FILES       = $(SNAKE_OBJ_DIR)/Backend_snake.o
TETRIS_FRONTEND_OBJ   = $(TETRIS_OBJ_DIR)/front.o
TETRIS_CONTROLER_OBJ  = $(TETRIS_OBJ_DIR)/controller_tetris_cli.o

MOC_SRCS = $(HDRS)
MOC_OUTS = $(MOC_SRCS:.h=.moc.cpp)

#━━━━━━━━━━ Архивы (статические библиотеки) ━━━━━━━━━━
TETRIS_LIB = $(BUILD_DIR)/tetris.a
SNAKE_LIB  = $(BUILD_DIR)/snake.a

#━━━━━━━━━━ Конфигурация тестов и покрытия кода ━━━━━━━━━━
TESTS_LINKER_FLAGS_CHECK  := -lcheck -lsubunit -lm
TESTS_LINKER_FLAGS_GTEST  := -lgtest_main -lgtest -pthread
COVERAGE_FLAGS            := -fprofile-arcs -ftest-coverage
GCOVR_THEME               := --html-theme github.dark-green
GCOVR_CONFIG_FLAGS        := --html --html-single-page=js-enabled --html-details
GCOVR_EXCLUDES            := --exclude-unreachable-branches --exclude-throw-branches --exclude-noncode-lines
GCOVR_FILTER              := --filter=src
GCOVR_FLAGS               := $(GCOVR_CONFIG_FLAGS) $(GCOVR_EXCLUDES) $(GCOVR_THEME) $(GCOVR_FILTER)

TARGET = run_desktop

#━━━━━━━━━━ Цель по умолчанию ━━━━━━━━━━
all: $(BUILD_DIR) $(TETRIS_LIB) $(SNAKE_LIB) ui_mainwindow.h install $(MOC_OUTS) $(TARGET)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR) $(TETRIS_OBJ_DIR) $(SNAKE_OBJ_DIR) $(DESKTOP_FILES_DIR)

#━━━━━━━━━━ Компиляция объектных файлов ━━━━━━━━━━
$(TETRIS_OBJ_DIR)/tetris_backend.o: $(TETRIS_BACKEND_FILE) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TETRIS_OBJ_DIR)/front.o: $(TETRIS_FRONTEND_FILE) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TETRIS_OBJ_DIR)/controller_tetris_cli.o: $(TETRIS_CONTROLER_FILE) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(SNAKE_OBJ_DIR)/Backend_snake.o: $(SNAKE_BACKEND_FILE) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

#━━━━━━━━━━ Создание статических библиотек ━━━━━━━━━━
$(TETRIS_LIB): $(TETRIS_OBJ_FILES)
	ar rcs $@ $^

$(SNAKE_LIB): $(SNAKE_OBJ_FILES)
	ar rcs $@ $^

#━━━━━━━━━━ Генерация заголовков из .ui ━━━━━━━━━━
ui_mainwindow.h: $(UI_FILES) | $(DESKTOP_FILES_DIR)
	$(UIC) $< -o $(DESKTOP_FILES_DIR)/ui_mainwindow.h

#━━━━━━━━━━ Генерация .moc.cpp файлов ━━━━━━━━━━
$(MOC_OUTS): %.moc.cpp: %.h | $(DESKTOP_FILES_DIR)
	$(MOC) $< -o $(DESKTOP_FILES_DIR)/$(notdir $@)

#━━━━━━━━━━ Линковка исполнимого файла ━━━━━━━━━━
$(TARGET): $(TETRIS_LIB) $(SNAKE_LIB)
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$(TARGET) $(SRCS) $(DESKTOP_FILES_DIR)/*.cpp $(TETRIS_LIB) $(SNAKE_LIB) $(LDFLAGS)

#━━━━━━━━━━ Установка ━━━━━━━━━━
install: $(TETRIS_FRONTEND_OBJ) $(TETRIS_CONTROLER_OBJ) $(TETRIS_LIB) $(SNAKE_LIB)
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/run_cli $(CLI_MAIN_FILE) $(TETRIS_CONTROLER_OBJ) $(TETRIS_FRONTEND_OBJ) $(SNAKE_CONTROLER_FILE) $(TETRIS_LIB) $(SNAKE_LIB) -lncurses -lm

#━━━━━━━━━━ Тестирование ━━━━━━━━━━
test: $(BUILD_DIR)/cli_snake_tests $(BUILD_DIR)/cli_tetris_tests
	$(BUILD_DIR)/cli_snake_tests
	$(BUILD_DIR)/cli_tetris_tests

$(BUILD_DIR)/cli_snake_tests: $(SNAKE_TESTS) $(SNAKE_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(TESTS_LINKER_FLAGS_GTEST)

$(BUILD_DIR)/cli_tetris_tests: $(TETRIS_TESTS) tests/tetris/backend_tests.c $(TETRIS_LIB)
	$(CC) $(CFLAGS) -o $@ $^ $(TESTS_LINKER_FLAGS_CHECK) -lncurses

#━━━━━━━━━━ Покрытие кода (Coverage) ━━━━━━━━━━
coverage: CXXFLAGS += $(COVERAGE_FLAGS)
coverage: CFLAGS += $(COVERAGE_FLAGS)
coverage: clean test
	mkdir -p $(COVERAGE_DIR)
	@gcovr -o $(COVERAGE_DIR)/gcov_report.html $(GCOVR_FLAGS)
	open $(COVERAGE_DIR)/gcov_report.html

#━━━━━━━━━━ Очистка ━━━━━━━━━━
clean:
	rm -rf $(BUILD_DIR)

# dvi:
# 	doxygen -g Doxyfile.txt ./brick_game/tetris/*.c ./gui/cli/*.c

# dist:
# 	mkdir dist
# 	cp -a ./brick_game/ ./dist/
# 	cp -a ./Makefile ./dist/ 
# 	cp -a ./gui/ ./dist/ 
# 	tar -czf tetris_1_0.tar.gz ./dist/
# 	rm -rf ./dist/
