#ifndef SRC_BACK_END_H_
#define SRC_BACK_END_H_

#include <math.h>

#include "../../gui/cli/Tetris/front_end.h"
#include "tetris.h"

void init_figur(int number_figur, Figur* figur);
void init_next_figur(int number_figur, Figur* figur);
void kill_figur(Figur* figur, Game_space* game_space);
void find_full_line(Game_space* game_space, GameInfo_t* game_info);
void check_line(Game_space* game_space, int i, int* check_linee);
void kill_line(Game_space* game_space, int i, int* count_full_line,
               int* check_line);
bool check_on_game_over(Game_space game_space);
void control_key(Figur* figur, WINDOW* window, Game_space* game_space,
                 UserAction_t* user_actions);
void rotation_figurs(Figur* figur);
void remove_trash_on_poly(Figur* figur, Game_space* game_space);
bool conditions_of_falling_down(Figur figur, Game_space game_space);
bool traffic_permit_left(Game_space* game_space, Figur* figur);
bool traffic_permit_right(Game_space* game_space, Figur* figur);
bool traffic_permit_down(Game_space* game_space, Figur* figur);
bool traffic_permit_flip(Game_space* game_space, Figur* figur);
bool end_space(Figur* figur);
void remove_tresh(Figur* figur, Game_space* game_space);
void game_level_and_speed(GameInfo_t* game_info);
int readNumberFromFile();
void writeNumberToFile(int number);
void figur_falling_down(Figur* figur);
void game_pause(WINDOW* window, UserAction_t* us_sct);
int get_random_number();
void get_figur(Figur* figur, GameInfo_t game_info);
void restart_game(UserAction_t* user_actions, GameInfo_t* game_info,
                  WINDOW* window);

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

void remove_trash_on_poly_for_figur_1(Figur* figur, Game_space* game_space);
void remove_trash_on_poly_for_figur_2(Figur* figur, Game_space* game_space);
void remove_trash_on_poly_for_figur_3(Figur* figur, Game_space* game_space);
void remove_trash_on_poly_for_figur_4(Figur* figur, Game_space* game_space);
void remove_trash_on_poly_for_figur_5(Figur* figur, Game_space* game_space);
void remove_trash_on_poly_for_figur_6(Figur* figur, Game_space* game_space);
void remove_trash_on_poly_for_figur_7(Figur* figur, Game_space* game_space);

#endif  // SRC_BACK_END_H_
