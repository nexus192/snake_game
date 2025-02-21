#━━━━━━━━━━Компиляторы━━━━━━━━━━
CC = gcc
CXX = g++
UIC = uic
MOC = moc

#━━━━━━━━━━Флаги для компиляции━━━━━━━━━━
CXXFLAGS = -std=c++17 -Wall -Wextra -fPIC $(shell pkg-config --cflags Qt5Widgets)
CFLAGS = -Wall -Wextra -fPIC $(shell pkg-config --cflags Qt5Widgets)
LDFLAGS = $(shell pkg-config --libs Qt5Widgets)

#━━━━━━━━━━Директории━━━━━━━━━━
SRC_DIR = src
BUILD_DIR = build
TETRIS_OBJ_DIR = $(BUILD_DIR)/object_files_for_tetris
SNAKE_OBJ_DIR = $(BUILD_DIR)/object_files_for_snake
DESKTOP_FILES_DIR = $(BUILD_DIR)/desktop_files

#━━━━━━━━━━Исходные файлы━━━━━━━━━━
TETRIS_BACKEND_FILE = $(SRC_DIR)/BrickGame/tetris/back_end.c
TETRIS_FRONTEND_FILE = $(SRC_DIR)/gui/cli/front.c
TETRIS_CONTROLER_FILE = $(SRC_DIR)/controller/controller_tetris.c
SNAKE_BACKEND_FILE = $(SRC_DIR)/BrickGame/snake/Backend_snake.cc
SNAKE_CONTROLER_FILE = $(SRC_DIR)/controller/controller_snake.cc
CLI_MAIN_FILE = $(SRC_DIR)/cli_main.cc
SNAKE_TESTS = $(TESTS_SRC_DIR)/snake/s21_snake_tests.cc
TETRIS_TESTS = $(TESTS_SRC_DIR)/tetris/run_tests.c

# Исходники
DESKTOP_DIR = $(SRC_DIR)/gui/desktop

SRCS = $(DESKTOP_DIR)/main.cpp \
			$(DESKTOP_DIR)/mainwindow.cpp \
    	$(DESKTOP_DIR)/Snake/snakegamerender.cpp \
    	$(DESKTOP_DIR)/Tetris/tetrisgamerender.cpp

# Заголовочные файлы
HDRS = $(DESKTOP_DIR)/mainwindow.h \
  		$(DESKTOP_DIR)/Snake/snakegamerender.h \
    	$(DESKTOP_DIR)/Tetris/tetrisgamerender.h \
    	$(DESKTOP_DIR)/ui_mainwindow.h

# UI файлы
UI_FILES = $(DESKTOP_DIR)/mainwindow.ui

#━━━━━━━━━━Объектные файлы━━━━━━━━━━
TETRIS_OBJ_FILES = $(TETRIS_OBJ_DIR)/back_end.o
SNAKE_OBJ_FILES = $(SNAKE_OBJ_DIR)/Backend_snake.o
TETRIS_FRONTEND_OBJ = $(TETRIS_OBJ_DIR)/front_end.o
TETRIS_CONTROLER_OBJ = $(TETRIS_OBJ_DIR)/controller_tetris.o

DESKTOP_OBJS = $(SRCS:.cpp=.o)

# MOC - обработка файлов с макросом Q_OBJECT
MOC_SRCS = $(DESKTOP_DIR)/mainwindow.h $(DESKTOP_DIR)/Snake/snakegamerender.h $(DESKTOP_DIR)/Tetris/tetrisgamerender.h
MOC_OUTS = $(MOC_SRCS:.h=.moc.cpp)
MOC_OBJS = $(MOC_OUTS:.cpp=.o)

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

TARGET = my_project

#━━━━━━━━━━Цель по умолчанию━━━━━━━━━━
all: $(BUILD_DIR) $(TETRIS_LIB) $(SNAKE_LIB) ui_mainwindow.h install $(MOC_OUTS) $(TARGET)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR) $(TETRIS_OBJ_DIR) $(SNAKE_OBJ_DIR) $(DESKTOP_FILES_DIR)

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

# Генерация заголовков из .ui
ui_mainwindow.h: $(UI_FILES) | $(DESKTOP_FILES_DIR)
	$(UIC) $< -o $(DESKTOP_FILES_DIR)/ui_mainwindow.h

# Генерация .moc.cpp файлов
$(MOC_OUTS): %.moc.cpp: %.h | $(DESKTOP_FILES_DIR)
	$(MOC) $< -o $(DESKTOP_FILES_DIR)/$(notdir $@)

# Компиляция .cpp файлов
$(DESKTOP_OBJS): $(SRCS) $(MOC_OUTS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Линковка исполнимого файла
$(TARGET): $(DESKTOP_OBJS) $(TETRIS_LIB) $(SNAKE_LIB) 
	$(CXX) $(CXXFLAGS) -c -o $(DESKTOP_FILES_DIR)/mainwindow.o $(DESKTOP_DIR)/mainwindow.cpp $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -c -o $(DESKTOP_FILES_DIR)/snakegamerender.o $(DESKTOP_DIR)/Snake/snakegamerender.cpp $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -c -o $(DESKTOP_FILES_DIR)/tetrisgamerender.o $(DESKTOP_DIR)/Tetris/tetrisgamerender.cpp $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -c -o $(DESKTOP_FILES_DIR)/main.o $(DESKTOP_DIR)/main.cpp $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$(TARGET) $(DESKTOP_FILES_DIR)/*.o $(DESKTOP_FILES_DIR)/*.cpp $(TETRIS_LIB) $(SNAKE_LIB) $(LDFLAGS)

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
	rm -rf $(BUILD_DIR) *.moc.cpp *.moc.o














# # Компилятор
# CXX = g++
# CC = gcc
# UIC = uic

# # Флаги компиляции
# CXXFLAGS = -std=c++17 -Wall -Wextra -fPIC $(shell pkg-config --cflags Qt5Widgets)
# CFLAGS = -Wall -Wextra -fPIC $(shell pkg-config --cflags Qt5Widgets)
# LDFLAGS = $(shell pkg-config --libs Qt5Widgets)

# # Исходники
# SRCS_CPP = main.cpp mainwindow.cpp \
#     ../../BrickGame/snake/Backend_snake.cc \
#     Snake/snakegamerender.cpp \
#     Tetris/tetrisgamerender.cpp

# SRCS_C = ../../BrickGame/tetris/back_end.c

# # Заголовочные файлы
# HDRS = mainwindow.h \
#     ../../BrickGame/snake/Snake.h \
#     Snake/snakegamerender.h \
#     Tetris/tetrisgamerender.h \
#     ../../BrickGame/tetris/back_end.h \
#     ui_mainwindow.h

# # UI файлы
# UI_FILES = mainwindow.ui

# # Объектные файлы
# OBJS_CPP = $(SRCS_CPP:.cpp=.o)
# OBJS_C = $(SRCS_C:.c=.o)

# # Исполняемый файл
# TARGET = my_project

# # Генерация заголовков из .ui
# ui_mainwindow.h: mainwindow.ui
# 	$(UIC) mainwindow.ui -o ui_mainwindow.h

# # MOC - обработка файлов с макросом Q_OBJECT
# MOC = moc
# MOC_SRCS = mainwindow.h Snake/snakegamerender.h Tetris/tetrisgamerender.h
# MOC_OUTS = $(MOC_SRCS:.h=.moc.cpp)
# MOC_OBJS = $(MOC_OUTS:.cpp=.o)

# # Компиляция .moc.cpp файлов
# %.moc.cpp: %.h
# 	$(MOC) $< -o $@

# # Цель по умолчанию
# all: $(MOC_OUTS) $(TARGET)

# # Линковка исполнимого файла
# $(TARGET): $(OBJS_CPP) $(OBJS_C) $(MOC_OBJS)
# 	$(CXX) $(OBJS_CPP) $(OBJS_C) $(MOC_OBJS) -o $(TARGET) $(LDFLAGS)

# # Компиляция .cpp файлов
# %.o: %.cpp $(HDRS)
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# # Компиляция .c файлов
# %.o: %.c $(HDRS)
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Очистка временных файлов
# clean:
# 	rm -f *.o $(TARGET) ui_mainwindow.h $(MOC_OUTS) $(MOC_OBJS)

