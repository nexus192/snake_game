#ifndef SRC_BACK_END_H_
#define SRC_BACK_END_H_
#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>
#include <stdbool.h>

#include "./../common/common.h"

#define COUNT_BLOCS_IN_FIGUR 4

#define LEVEL_UP 600

#define SPEED_STEP 25

#define NEXT_WIDTH 6
#define NEXT_HEIGHT 4

#define CODE_CLEAR_SPACE 0
#define CODE_BARRIER 1
#define CODE_FIGURE 3

typedef enum UserAction_t {
  Start,
  Pause,
  Terminate,
  Action,
  Game_over,
  Restart
} UserAction_t;

typedef struct Game_space {
  int** space;
  int row;
  int col;
} Game_space;

typedef struct GameInfo_t {
  int** next;
  int next_figur;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

typedef struct Figur {
  int position[COUNT_BLOCS_IN_FIGUR * 2];
  int figur_type;
  int move_triger;
  int rotations_position;
  int code;
} Figur;

void init_figur(int number_figur, Figur* figur);
void init_next_figur(int number_figur, Figur* figur);
void kill_figur(Figur* figur, Game_space* game_space);
void find_full_line(Game_space* game_space, GameInfo_t* game_info);
void check_line(Game_space* game_space, int i, int* check_linee);
void kill_line(Game_space* game_space, int i, int* count_full_line,
               int* check_line);
bool check_on_game_over(Game_space game_space);
void rotation_figurs(Figur* figur);
void MoveFigurLeft(Figur* figur);
void MoveFigurRight(Figur* figur);
void MoveFigurDown(Figur* figur);
bool conditions_of_falling_down(Figur figur, Game_space game_space);
bool traffic_permit_left(Game_space* game_space, Figur* figur);
bool traffic_permit_right(Game_space* game_space, Figur* figur);
bool traffic_permit_down(Game_space* game_space, Figur* figur);
bool traffic_permit_flip(Game_space* game_space, Figur* figur);
bool end_space(Figur* figur);
void game_level_and_speed(GameInfo_t* game_info);
int readNumberFromFile();
void writeNumberToFile(int number);
void figur_falling_down(Figur* figur, Game_space* game_space,
                        VectorDirection* direction);
int get_random_number();
void get_figur(Figur* figur, GameInfo_t game_info);
void print_figur_in_game_poly(Game_space* game_space, Figur* figur);
void print_next_figur(GameInfo_t* game_info);
void clean_space_game(Game_space* game_space);
void init_space_game(Game_space* game_space);
void init_game_info(GameInfo_t* game_info);
void CleanGameInfo(GameInfo_t* game_info);
void game_remove(Game_space* game_space, GameInfo_t* game_info);

bool traffic_permit_left_for_figur_1(Game_space* game_space, Figur* figur);
bool traffic_permit_left_for_figur_2(Game_space* game_space, Figur* figur);
bool traffic_permit_left_for_figur_3(Game_space* game_space, Figur* figur);
bool traffic_permit_left_for_figur_4(Game_space* game_space, Figur* figur);
bool traffic_permit_left_for_figur_5(Game_space* game_space, Figur* figur);
bool traffic_permit_left_for_figur_6(Game_space* game_space, Figur* figur);
bool traffic_permit_left_for_figur_7(Game_space* game_space, Figur* figur);

bool traffic_permit_right_for_figur_1(Game_space* game_space, Figur* figur);
bool traffic_permit_right_for_figur_2(Game_space* game_space, Figur* figur);
bool traffic_permit_right_for_figur_3(Game_space* game_space, Figur* figur);
bool traffic_permit_right_for_figur_4(Game_space* game_space, Figur* figur);
bool traffic_permit_right_for_figur_5(Game_space* game_space, Figur* figur);
bool traffic_permit_right_for_figur_6(Game_space* game_space, Figur* figur);
bool traffic_permit_right_for_figur_7(Game_space* game_space, Figur* figur);

bool traffic_permit_down_for_figur_1(Game_space* game_space, Figur* figur);
bool traffic_permit_down_for_figur_2(Game_space* game_space, Figur* figur);
bool traffic_permit_down_for_figur_3(Game_space* game_space, Figur* figur);
bool traffic_permit_down_for_figur_4(Game_space* game_space, Figur* figur);
bool traffic_permit_down_for_figur_5(Game_space* game_space, Figur* figur);
bool traffic_permit_down_for_figur_6(Game_space* game_space, Figur* figur);
bool traffic_permit_down_for_figur_7(Game_space* game_space, Figur* figur);

bool traffic_permit_flip_for_figur_1(Game_space* game_space, Figur* figur);
bool traffic_permit_flip_for_figur_2(Game_space* game_space, Figur* figur);
bool traffic_permit_flip_for_figur_3(Game_space* game_space, Figur* figur);
bool traffic_permit_flip_for_figur_5(Game_space* game_space, Figur* figur);
bool traffic_permit_flip_for_figur_6(Game_space* game_space, Figur* figur);
bool traffic_permit_flip_for_figur_7(Game_space* game_space, Figur* figur);

void figure_rotation_1(Figur* figur);
void figure_rotation_2(Figur* figur);
void figure_rotation_3(Figur* figur);
void figure_rotation_5(Figur* figur);
void figure_rotation_6(Figur* figur);
void figure_rotation_7(Figur* figur);

bool conditions_of_falling_down_for_figur_1(Figur figur, Game_space game_space);
bool conditions_of_falling_down_for_figur_2(Figur figur, Game_space game_space);
bool conditions_of_falling_down_for_figur_3(Figur figur, Game_space game_space);
bool conditions_of_falling_down_for_figur_4(Figur figur, Game_space game_space);
bool conditions_of_falling_down_for_figur_5(Figur figur, Game_space game_space);
bool conditions_of_falling_down_for_figur_6(Figur figur, Game_space game_space);
bool conditions_of_falling_down_for_figur_7(Figur figur, Game_space game_space);

#ifdef __cplusplus
}
#endif

#endif  // SRC_BACK_END_H_
