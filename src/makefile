CXX = g++
FLAGS = -Wall -Werror -Wextra -std=c++17

all: inslall

inslall: 
	$(CXX) $(FLAGS) ./BrickGame/Backend_Snake/*.cpp ./gui/cli/*.cpp -o snake -lncurses

clear: 
	rm -f snake