#include "back_end.h"

#include <stdio.h>
#include <stdlib.h>

void init_figur(int number_figur, Figur* figur) {
  Figur figur1 = {{1, 4, 1, 5, 1, 6, 1, 7}, 1, 0, 0, 3};  // палка
  // Figur figur1 = {{1, 4, 2, 4, 3, 4, 4, 4}, 1, 0, 1, 3};  // палка
  Figur figur2 = {{1, 5, 2, 5, 2, 6, 2, 7}, 2, 0, 0, 3};  // г
  Figur figur3 = {{1, 7, 2, 7, 2, 6, 2, 5}, 3, 0, 0, 3};  // обратное г
  Figur figur4 = {{1, 5, 1, 6, 2, 5, 2, 6}, 4, 0, 0, 3};  // квадрат
  Figur figur5 = {{1, 7, 1, 6, 2, 6, 2, 5}, 5, 0, 0, 3};  // зигзаг как 5
  Figur figur6 = {{1, 6, 2, 5, 2, 6, 2, 7}, 6, 0, 0, 3};  // как Т
  Figur figur7 = {{1, 5, 1, 6, 2, 6, 2, 7}, 7, 0, 0, 3};  // зиграг как 2

  switch (number_figur) {
    case 1:
      *figur = figur1;
      break;
    case 2:
      *figur = figur2;
      break;
    case 3:
      *figur = figur3;
      break;
    case 4:
      *figur = figur4;
      break;
    case 5:
      *figur = figur5;
      break;
    case 6:
      *figur = figur6;
      break;
    case 7:
      *figur = figur7;
      break;
  }
}

void init_next_figur(int number_figur, Figur* figur) {
  Figur figur1 = {{1, 1, 1, 2, 1, 3, 1, 4}, 1, 0, 0, 3};  // палка
  // Figur figur1 = {{1, 4, 2, 4, 3, 4, 4, 4}, 1, 0, 1, 3};  // палка
  Figur figur2 = {{1, 2, 2, 2, 2, 3, 2, 4}, 2, 0, 0, 3};  // г
  Figur figur3 = {{1, 4, 2, 4, 2, 3, 2, 2}, 3, 0, 0, 3};  // обратное г
  Figur figur4 = {{1, 2, 1, 3, 2, 2, 2, 3}, 4, 0, 0, 3};  // квадрат
  Figur figur5 = {{1, 4, 1, 3, 2, 3, 2, 2}, 5, 0, 0, 3};  // зигзаг как 5
  Figur figur6 = {{1, 3, 2, 2, 2, 3, 2, 4}, 6, 0, 0, 3};  // как Т
  Figur figur7 = {{1, 2, 1, 3, 2, 3, 2, 4}, 7, 0, 0, 3};  // зиграг как 2

  switch (number_figur) {
    case 1:
      *figur = figur1;
      break;
    case 2:
      *figur = figur2;
      break;
    case 3:
      *figur = figur3;
      break;
    case 4:
      *figur = figur4;
      break;
    case 5:
      *figur = figur5;
      break;
    case 6:
      *figur = figur6;
      break;
    case 7:
      *figur = figur7;
      break;
  }
}

void kill_figur(Figur* figur, Game_space* game_space) {
  game_space->space[figur->position[0]][figur->position[1]] = 0;
  game_space->space[figur->position[2]][figur->position[3]] = 0;
  game_space->space[figur->position[4]][figur->position[5]] = 0;
  game_space->space[figur->position[6]][figur->position[7]] = 0;
}

void check_line(Game_space* game_space, int i, int* check_linee) {
  for (int j = WIDTH - 1; j >= 0; j--) {
    if (game_space->space[i][j] == 3) {
      *check_linee += 1;
    }
  }
}

void kill_line(Game_space* game_space, int i, int* count_full_line,
               int* check_line) {
  if (*check_line == 10) {
    for (int k = 0; k < WIDTH; k++) {
      game_space->space[i][k] = 0;
    }
    for (int r = i; r > 1; r--) {
      for (int g = 0; g < WIDTH; g++) {
        game_space->space[r][g] = game_space->space[r - 1][g];
        game_space->space[r - 1][g] = 0;
      }
    }
    *count_full_line += 1;
  }
}

void find_full_line(Game_space* game_space, GameInfo_t* game_info) {
  int check_linee = 0;
  int count_full_line = 0;
  for (int l = 0; l < 4; l++) {
    for (int i = HEIGHT - 1; i >= 0; i--) {
      check_line(game_space, i, &check_linee);
      kill_line(game_space, i, &count_full_line, &check_linee);
      check_linee = 0;
    }
  }

  if (count_full_line == 1) {
    game_info->score += 100;
  } else if (count_full_line == 2) {
    game_info->score += 300;
  } else if (count_full_line == 3) {
    game_info->score += 700;
  } else if (count_full_line == 4) {
    game_info->score += 1500;
  }
}

bool check_on_game_over(Game_space game_space) {
  bool result = true;
  for (int i = 0; i < GAME_COL - 2; i++) {
    if (game_space.space[0][i] == 3) {
      result = false;
    }
  }
  return result;
}

bool traffic_permit_left(Game_space* game_space, Figur* figur) {
  bool code_result = false;
  if (figur->position[1] - 1 != -1 && figur->position[3] - 1 != -1 &&
      figur->position[5] - 1 != -1 && figur->position[7] - 1 != -1) {
    if (figur->figur_type == 1) {
      code_result = traffic_permit_left_for_figur_1(game_space, figur);
    } else if (figur->figur_type == 2) {
      code_result = traffic_permit_left_for_figur_2(game_space, figur);
    } else if (figur->figur_type == 3) {
      code_result = traffic_permit_left_for_figur_3(game_space, figur);
    } else if (figur->figur_type == 4) {
      code_result = traffic_permit_left_for_figur_4(game_space, figur);
    } else if (figur->figur_type == 5) {
      code_result = traffic_permit_left_for_figur_5(game_space, figur);
    } else if (figur->figur_type == 6) {
      code_result = traffic_permit_left_for_figur_6(game_space, figur);
    } else {
      code_result = traffic_permit_left_for_figur_7(game_space, figur);
    }
  }
  return code_result;
}
bool traffic_permit_right(Game_space* game_space, Figur* figur) {
  bool code_result = false;
  if (figur->position[1] + 1 != 10 && figur->position[3] + 1 != 10 &&
      figur->position[5] + 1 != 10 && figur->position[7] + 1 != 10) {
    if (figur->figur_type == 1) {
      code_result = traffic_permit_right_for_figur_1(game_space, figur);
    } else if (figur->figur_type == 2) {
      code_result = traffic_permit_right_for_figur_2(game_space, figur);
    } else if (figur->figur_type == 3) {
      code_result = traffic_permit_right_for_figur_3(game_space, figur);
    } else if (figur->figur_type == 4) {
      code_result = traffic_permit_right_for_figur_4(game_space, figur);
    } else if (figur->figur_type == 5) {
      code_result = traffic_permit_right_for_figur_5(game_space, figur);
    } else if (figur->figur_type == 6) {
      code_result = traffic_permit_right_for_figur_6(game_space, figur);
    } else {
      code_result = traffic_permit_right_for_figur_7(game_space, figur);
    }
  }
  return code_result;
}

bool traffic_permit_down(Game_space* game_space, Figur* figur) {
  bool code_result = false;
  if ((figur->position[0] + 2 != 20 && figur->position[2] + 2 != 20 &&
       figur->position[4] + 2 != 20 && figur->position[6] + 2 != 20) &&
      (figur->position[0] + 1 != 20 && figur->position[2] + 1 != 20 &&
       figur->position[4] + 1 != 20 && figur->position[6] + 1 != 20)) {
    if (figur->figur_type == 1) {
      code_result = traffic_permit_down_for_figur_1(game_space, figur);
    } else if (figur->figur_type == 2) {
      code_result = traffic_permit_down_for_figur_2(game_space, figur);
    } else if (figur->figur_type == 3) {
      code_result = traffic_permit_down_for_figur_3(game_space, figur);
    } else if (figur->figur_type == 4) {
      code_result = traffic_permit_down_for_figur_4(game_space, figur);
    } else if (figur->figur_type == 5) {
      code_result = traffic_permit_down_for_figur_5(game_space, figur);
    } else if (figur->figur_type == 6) {
      code_result = traffic_permit_down_for_figur_6(game_space, figur);
    } else {
      code_result = traffic_permit_down_for_figur_7(game_space, figur);
    }
  }
  return code_result;
}

bool traffic_permit_flip(Game_space* game_space, Figur* figur) {
  bool code_result = false;
  if (figur->figur_type == 1) {
    code_result = traffic_permit_flip_for_figur_1(game_space, figur);
  } else if (figur->figur_type == 2) {
    code_result = traffic_permit_flip_for_figur_2(game_space, figur);
  } else if (figur->figur_type == 3) {
    code_result = traffic_permit_flip_for_figur_3(game_space, figur);
  } else if (figur->figur_type == 5) {
    code_result = traffic_permit_flip_for_figur_5(game_space, figur);
  } else if (figur->figur_type == 6) {
    code_result = traffic_permit_flip_for_figur_6(game_space, figur);
  } else if (figur->figur_type == 7) {
    code_result = traffic_permit_flip_for_figur_7(game_space, figur);
  }

  return code_result;
}

void rotation_figurs(Figur* figur) {
  if (figur->figur_type == 1) {
    figure_rotation_1(figur);
  } else if (figur->figur_type == 2) {
    figure_rotation_2(figur);
  } else if (figur->figur_type == 3) {
    figure_rotation_3(figur);
  } else if (figur->figur_type == 5) {
    figure_rotation_5(figur);
  } else if (figur->figur_type == 6) {
    figure_rotation_6(figur);
  } else if (figur->figur_type == 7) {
    figure_rotation_7(figur);
  }
}

void remove_trash_on_poly(Figur* figur, Game_space* game_space) {
  if (end_space(figur) == false) {
    if (figur->figur_type == 1) {
      remove_trash_on_poly_for_figur_1(figur, game_space);
    } else if (figur->figur_type == 2) {
      remove_trash_on_poly_for_figur_2(figur, game_space);
    } else if (figur->figur_type == 3) {
      remove_trash_on_poly_for_figur_3(figur, game_space);
    } else if (figur->figur_type == 4) {
      remove_trash_on_poly_for_figur_4(figur, game_space);
    } else if (figur->figur_type == 5) {
      remove_trash_on_poly_for_figur_5(figur, game_space);
    } else if (figur->figur_type == 6) {
      remove_trash_on_poly_for_figur_6(figur, game_space);
    } else {
      remove_trash_on_poly_for_figur_7(figur, game_space);
    }
  }
}

bool conditions_of_falling_down(Figur figur, Game_space game_space) {
  bool code_result = false;
  if (figur.figur_type == 1) {
    code_result = conditions_of_falling_down_for_figur_1(figur, game_space);
  } else if (figur.figur_type == 2) {
    code_result = conditions_of_falling_down_for_figur_2(figur, game_space);
  } else if (figur.figur_type == 3) {
    code_result = conditions_of_falling_down_for_figur_3(figur, game_space);
  } else if (figur.figur_type == 4) {
    code_result = conditions_of_falling_down_for_figur_4(figur, game_space);
  } else if (figur.figur_type == 5) {
    code_result = conditions_of_falling_down_for_figur_5(figur, game_space);
  } else if (figur.figur_type == 6) {
    code_result = conditions_of_falling_down_for_figur_6(figur, game_space);
  } else {
    code_result = conditions_of_falling_down_for_figur_7(figur, game_space);
  }

  return code_result;
}

void figure_rotation_1(Figur* figur) {  // палка
  // Figur figur1 = {{1, 4, 1, 5, 1, 6, 1, 7}, 1, 0, 1, 3};
  Figur new_figur = {0};
  if (figur->rotations_position == 0) {  // 4 5 const
    new_figur.position[0] = figur->position[4] - 2;
    new_figur.position[1] = figur->position[5];
    new_figur.position[2] = figur->position[4] - 1;
    new_figur.position[3] = figur->position[5];
    new_figur.position[4] = figur->position[4];
    new_figur.position[5] = figur->position[5];
    new_figur.position[6] = figur->position[4] + 1;
    new_figur.position[7] = figur->position[5];
    new_figur.rotations_position = 1;
    new_figur.code = 3;
    new_figur.figur_type = 1;
  } else {
    new_figur.position[0] = figur->position[4];
    new_figur.position[1] = figur->position[5] - 2;
    new_figur.position[2] = figur->position[4];
    new_figur.position[3] = figur->position[5] - 1;
    new_figur.position[4] = figur->position[4];
    new_figur.position[5] = figur->position[5];
    new_figur.position[6] = figur->position[4];
    new_figur.position[7] = figur->position[5] + 1;
    new_figur.rotations_position = 0;
    new_figur.code = 3;
    new_figur.figur_type = 1;
  }
  *figur = new_figur;
}
void figure_rotation_2(Figur* figur) {  // г
  // Figur figur2 = {{1, 5, 2, 5, 2, 6, 2, 7}, 2, 0, 0, 3};  // г
  Figur new_figur = {0};
  if (figur->rotations_position == 0) {  // 4 5 const
    new_figur.position[0] = figur->position[4] - 1;
    new_figur.position[1] = figur->position[5] + 1;
    new_figur.position[2] = figur->position[4] - 1;
    new_figur.position[3] = figur->position[5];
    new_figur.position[4] = figur->position[4];
    new_figur.position[5] = figur->position[5];
    new_figur.position[6] = figur->position[4] + 1;
    new_figur.position[7] = figur->position[5];
    new_figur.rotations_position = 1;
  } else if (figur->rotations_position == 1) {
    new_figur.position[0] = figur->position[4] + 1;
    new_figur.position[1] = figur->position[5] + 1;
    new_figur.position[2] = figur->position[4];
    new_figur.position[3] = figur->position[5] + 1;
    new_figur.position[4] = figur->position[4];
    new_figur.position[5] = figur->position[5];
    new_figur.position[6] = figur->position[4];
    new_figur.position[7] = figur->position[5] - 1;
    new_figur.rotations_position = 2;
  } else if (figur->rotations_position == 2) {
    new_figur.position[0] = figur->position[4] + 1;
    new_figur.position[1] = figur->position[5] - 1;
    new_figur.position[2] = figur->position[4] + 1;
    new_figur.position[3] = figur->position[5];
    new_figur.position[4] = figur->position[4];
    new_figur.position[5] = figur->position[5];
    new_figur.position[6] = figur->position[4] - 1;
    new_figur.position[7] = figur->position[5];
    new_figur.rotations_position = 3;
  } else {
    new_figur.position[0] = figur->position[4] - 1;
    new_figur.position[1] = figur->position[5] - 1;
    new_figur.position[2] = figur->position[4];
    new_figur.position[3] = figur->position[5] - 1;
    new_figur.position[4] = figur->position[4];
    new_figur.position[5] = figur->position[5];
    new_figur.position[6] = figur->position[4];
    new_figur.position[7] = figur->position[5] + 1;
    new_figur.rotations_position = 0;
  }
  new_figur.code = 3;
  new_figur.figur_type = 2;
  *figur = new_figur;
}
void figure_rotation_3(Figur* figur) {  // обратное г
  // Figur figur3 = {{1, 7, 2, 7, 2, 6, 2, 5}, 3, 0, 0, 3};  // обратное г
  Figur new_figur = {0};
  if (figur->rotations_position == 0) {  // 4 5 const
    new_figur.position[0] = figur->position[4] + 1;
    new_figur.position[1] = figur->position[5] + 1;
    new_figur.position[2] = figur->position[4] + 1;
    new_figur.position[3] = figur->position[5];
    new_figur.position[4] = figur->position[4];
    new_figur.position[5] = figur->position[5];
    new_figur.position[6] = figur->position[4] - 1;
    new_figur.position[7] = figur->position[5];
    new_figur.rotations_position = 1;
  } else if (figur->rotations_position == 1) {
    new_figur.position[0] = figur->position[4] + 1;
    new_figur.position[1] = figur->position[5] - 1;
    new_figur.position[2] = figur->position[4];
    new_figur.position[3] = figur->position[5] - 1;
    new_figur.position[4] = figur->position[4];
    new_figur.position[5] = figur->position[5];
    new_figur.position[6] = figur->position[4];
    new_figur.position[7] = figur->position[5] + 1;
    new_figur.rotations_position = 2;
  } else if (figur->rotations_position == 2) {
    new_figur.position[0] = figur->position[4] - 1;
    new_figur.position[1] = figur->position[5] - 1;
    new_figur.position[2] = figur->position[4] - 1;
    new_figur.position[3] = figur->position[5];
    new_figur.position[4] = figur->position[4];
    new_figur.position[5] = figur->position[5];
    new_figur.position[6] = figur->position[4] + 1;
    new_figur.position[7] = figur->position[5];
    new_figur.rotations_position = 3;
  } else {
    new_figur.position[0] = figur->position[4] - 1;
    new_figur.position[1] = figur->position[5] + 1;
    new_figur.position[2] = figur->position[4];
    new_figur.position[3] = figur->position[5] + 1;
    new_figur.position[4] = figur->position[4];
    new_figur.position[5] = figur->position[5];
    new_figur.position[6] = figur->position[4];
    new_figur.position[7] = figur->position[5] - 1;
    new_figur.rotations_position = 0;
  }
  new_figur.code = 3;
  new_figur.figur_type = 3;
  *figur = new_figur;
}

void figure_rotation_5(Figur* figur) {
  // Figur figur5 = {{1, 7, 1, 6, 2, 6, 2, 5}, 5, 0, 0, 3};
  Figur new_figur = {0};
  if (figur->rotations_position == 0) {  // 4 5 const
    new_figur.position[0] = figur->position[4] - 1;
    new_figur.position[1] = figur->position[5] - 1;
    new_figur.position[2] = figur->position[4];
    new_figur.position[3] = figur->position[5] - 1;
    new_figur.position[4] = figur->position[4];
    new_figur.position[5] = figur->position[5];
    new_figur.position[6] = figur->position[4] + 1;
    new_figur.position[7] = figur->position[5];
    new_figur.rotations_position = 1;
  } else {
    new_figur.position[0] = figur->position[4] - 1;
    new_figur.position[1] = figur->position[5] + 1;
    new_figur.position[2] = figur->position[4] - 1;
    new_figur.position[3] = figur->position[5];
    new_figur.position[4] = figur->position[4];
    new_figur.position[5] = figur->position[5];
    new_figur.position[6] = figur->position[4];
    new_figur.position[7] = figur->position[5] - 1;
    new_figur.rotations_position = 0;
  }
  new_figur.code = 3;
  new_figur.figur_type = 5;
  *figur = new_figur;
}

void figure_rotation_6(Figur* figur) {
  Figur new_figur = {0};
  if (figur->rotations_position == 0) {  // 4 5 const
    new_figur.position[0] = figur->position[4];
    new_figur.position[1] = figur->position[5] + 1;
    new_figur.position[2] = figur->position[4] - 1;
    new_figur.position[3] = figur->position[5];
    new_figur.position[4] = figur->position[4];
    new_figur.position[5] = figur->position[5];
    new_figur.position[6] = figur->position[4] + 1;
    new_figur.position[7] = figur->position[5];
    new_figur.rotations_position = 1;
  } else if (figur->rotations_position == 1) {
    new_figur.position[0] = figur->position[4] + 1;
    new_figur.position[1] = figur->position[5];
    new_figur.position[2] = figur->position[4];
    new_figur.position[3] = figur->position[5] + 1;
    new_figur.position[4] = figur->position[4];
    new_figur.position[5] = figur->position[5];
    new_figur.position[6] = figur->position[4];
    new_figur.position[7] = figur->position[5] - 1;
    new_figur.rotations_position = 2;
  } else if (figur->rotations_position == 2) {
    new_figur.position[0] = figur->position[4];
    new_figur.position[1] = figur->position[5] - 1;
    new_figur.position[2] = figur->position[4] + 1;
    new_figur.position[3] = figur->position[5];
    new_figur.position[4] = figur->position[4];
    new_figur.position[5] = figur->position[5];
    new_figur.position[6] = figur->position[4] - 1;
    new_figur.position[7] = figur->position[5];
    new_figur.rotations_position = 3;
  } else {
    new_figur.position[0] = figur->position[4] - 1;
    new_figur.position[1] = figur->position[5];
    new_figur.position[2] = figur->position[4];
    new_figur.position[3] = figur->position[5] - 1;
    new_figur.position[4] = figur->position[4];
    new_figur.position[5] = figur->position[5];
    new_figur.position[6] = figur->position[4];
    new_figur.position[7] = figur->position[5] + 1;
    new_figur.rotations_position = 0;
  }
  new_figur.code = 3;
  new_figur.figur_type = 6;
  *figur = new_figur;
}

void figure_rotation_7(Figur* figur) {  // зиграг как 2
  // Figur figur7 = {{1, 5, 1, 6, 2, 6, 2, 7}, 7, 0, 0, 3};  // зиграг как 2
  Figur new_figur = {0};
  if (figur->rotations_position == 0) {  // 4 5 const
    new_figur.position[0] = figur->position[4] - 1;
    new_figur.position[1] = figur->position[5] + 1;
    new_figur.position[2] = figur->position[4];
    new_figur.position[3] = figur->position[5] + 1;
    new_figur.position[4] = figur->position[4];
    new_figur.position[5] = figur->position[5];
    new_figur.position[6] = figur->position[4] + 1;
    new_figur.position[7] = figur->position[5];
    new_figur.rotations_position = 1;
  } else {
    new_figur.position[0] = figur->position[4] - 1;
    new_figur.position[1] = figur->position[5] - 1;
    new_figur.position[2] = figur->position[4] - 1;
    new_figur.position[3] = figur->position[5];
    new_figur.position[4] = figur->position[4];
    new_figur.position[5] = figur->position[5];
    new_figur.position[6] = figur->position[4];
    new_figur.position[7] = figur->position[5] + 1;
    new_figur.rotations_position = 0;
  }
  new_figur.code = 3;
  new_figur.figur_type = 7;
  *figur = new_figur;
}

bool conditions_of_falling_down_for_figur_1(Figur figur,
                                            Game_space game_space) {
  bool code_result = true;
  if (figur.rotations_position == 0) {
    if ((end_space(&figur) == true) ||
        (game_space.space[figur.position[0]][figur.position[1]] == figur.code ||
         game_space.space[figur.position[2]][figur.position[3]] == figur.code ||
         game_space.space[figur.position[4]][figur.position[5]] == figur.code ||
         game_space.space[figur.position[6]][figur.position[7]] ==
             figur.code)) {
      code_result = false;
    }
  } else if (figur.rotations_position == 1) {
    if ((end_space(&figur) == true) ||
        (game_space.space[figur.position[4] + 1][figur.position[5]] ==
         figur.code)) {
      code_result = false;
    }
  }
  return code_result;
}

bool conditions_of_falling_down_for_figur_2(Figur figur,
                                            Game_space game_space) {
  bool code_result = true;
  if (figur.rotations_position == 0) {
    if ((end_space(&figur) == true) ||
        (game_space.space[figur.position[2]][figur.position[3]] == figur.code ||
         game_space.space[figur.position[4]][figur.position[5]] == figur.code ||
         game_space.space[figur.position[6]][figur.position[7]] ==
             figur.code)) {
      code_result = false;
    }
  } else if (figur.rotations_position == 1) {
    if ((end_space(&figur) == true) ||
        (game_space.space[figur.position[0]][figur.position[1]] == figur.code ||
         game_space.space[figur.position[6]][figur.position[7]] ==
             figur.code)) {
      code_result = false;
    }
  } else if (figur.rotations_position == 2) {
    if ((end_space(&figur) == true) ||
        (game_space.space[figur.position[0]][figur.position[1]] == figur.code ||
         game_space.space[figur.position[4]][figur.position[5]] == figur.code ||
         game_space.space[figur.position[6]][figur.position[7]] ==
             figur.code)) {
      code_result = false;
    }
  } else {
    if ((end_space(&figur) == true) ||
        (game_space.space[figur.position[0]][figur.position[1]] == figur.code ||
         game_space.space[figur.position[2]][figur.position[3]] ==
             figur.code)) {
      code_result = false;
    }
  }
  return code_result;
}

bool conditions_of_falling_down_for_figur_3(Figur figur,
                                            Game_space game_space) {
  bool code_result = true;
  if (figur.rotations_position == 0) {
    if ((end_space(&figur) == true) ||
        (game_space.space[figur.position[2]][figur.position[3]] == figur.code ||
         game_space.space[figur.position[4]][figur.position[5]] == figur.code ||
         game_space.space[figur.position[6]][figur.position[7]] ==
             figur.code)) {
      code_result = false;
    }
  } else if (figur.rotations_position == 1) {
    if ((end_space(&figur) == true) ||
        (game_space.space[figur.position[0]][figur.position[1]] == figur.code ||
         game_space.space[figur.position[2]][figur.position[3]] ==
             figur.code)) {
      code_result = false;
    }
  } else if (figur.rotations_position == 2) {
    if ((end_space(&figur) == true) ||
        (game_space.space[figur.position[0]][figur.position[1]] == figur.code ||
         game_space.space[figur.position[4]][figur.position[5]] == figur.code ||
         game_space.space[figur.position[6]][figur.position[7]] ==
             figur.code)) {
      code_result = false;
    }
  } else {
    if ((end_space(&figur) == true) ||
        (game_space.space[figur.position[0]][figur.position[1]] == figur.code ||
         game_space.space[figur.position[6]][figur.position[7]] ==
             figur.code)) {
      code_result = false;
    }
  }
  return code_result;
}

bool conditions_of_falling_down_for_figur_4(Figur figur,
                                            Game_space game_space) {
  bool code_result = true;
  if ((end_space(&figur) == true) ||
      (game_space.space[figur.position[4]][figur.position[5]] == figur.code ||
       game_space.space[figur.position[6]][figur.position[7]] == figur.code)) {
    code_result = false;
  }
  return code_result;
}

bool conditions_of_falling_down_for_figur_5(Figur figur,
                                            Game_space game_space) {
  bool code_result = true;
  if (figur.rotations_position == 0) {
    if ((end_space(&figur) == true) ||
        (game_space.space[figur.position[0]][figur.position[1]] == figur.code ||
         game_space.space[figur.position[4]][figur.position[5]] == figur.code ||
         game_space.space[figur.position[6]][figur.position[7]] ==
             figur.code)) {
      code_result = false;
    }
  } else {
    if ((end_space(&figur) == true) ||
        (game_space.space[figur.position[2]][figur.position[3]] == figur.code ||
         game_space.space[figur.position[6]][figur.position[7]] ==
             figur.code)) {
      code_result = false;
    }
  }
  return code_result;
}

bool conditions_of_falling_down_for_figur_6(Figur figur,
                                            Game_space game_space) {
  bool code_result = true;
  if (figur.rotations_position == 0) {
    if ((end_space(&figur) == true) ||
        (game_space.space[figur.position[2]][figur.position[3]] == figur.code ||
         game_space.space[figur.position[4]][figur.position[5]] == figur.code ||
         game_space.space[figur.position[6]][figur.position[7]] ==
             figur.code)) {
      code_result = false;
    }
  } else if (figur.rotations_position == 1) {
    if ((end_space(&figur) == true) ||
        (game_space.space[figur.position[0]][figur.position[1]] == figur.code ||
         game_space.space[figur.position[6]][figur.position[7]] ==
             figur.code)) {
      code_result = false;
    }
  } else if (figur.rotations_position == 2) {
    if ((end_space(&figur) == true) ||
        (game_space.space[figur.position[0]][figur.position[1]] == figur.code ||
         game_space.space[figur.position[2]][figur.position[3]] == figur.code ||
         game_space.space[figur.position[6]][figur.position[7]] ==
             figur.code)) {
      code_result = false;
    }
  } else {
    if ((end_space(&figur) == true) ||
        (game_space.space[figur.position[0]][figur.position[1]] == figur.code ||
         game_space.space[figur.position[2]][figur.position[3]] ==
             figur.code)) {
      code_result = false;
    }
  }
  return code_result;
}

bool conditions_of_falling_down_for_figur_7(Figur figur,
                                            Game_space game_space) {
  bool code_result = true;
  if (figur.rotations_position == 0) {
    if ((end_space(&figur) == true) ||
        (game_space.space[figur.position[0]][figur.position[1]] == figur.code ||
         game_space.space[figur.position[4]][figur.position[5]] == figur.code ||
         game_space.space[figur.position[6]][figur.position[7]] ==
             figur.code)) {
      code_result = false;
    }
  } else {
    if ((end_space(&figur) == true) ||
        (game_space.space[figur.position[2]][figur.position[3]] == figur.code ||
         game_space.space[figur.position[6]][figur.position[7]] ==
             figur.code)) {
      code_result = false;
    }
  }
  return code_result;
}

bool traffic_permit_left_for_figur_1(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[0]][figur->position[1] - 1] !=
        figur->code) {
      result = true;
    }
  } else {
    if (game_space->space[figur->position[0]][figur->position[1] - 1] !=
            figur->code &&
        game_space->space[figur->position[2]][figur->position[3] - 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] - 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] - 1] !=
            figur->code) {
      result = true;
    }
  }

  return result;
}
bool traffic_permit_left_for_figur_2(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[0]][figur->position[1] - 1] !=
            figur->code &&
        game_space->space[figur->position[2]][figur->position[3] - 1] !=
            figur->code) {
      result = true;
    }
  } else if (figur->rotations_position == 1) {
    if (game_space->space[figur->position[2]][figur->position[3] - 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] - 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] - 1] !=
            figur->code) {
      result = true;
    }
  } else if (figur->rotations_position == 2) {
    if (game_space->space[figur->position[0]][figur->position[1] - 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] - 1] !=
            figur->code) {
      result = true;
    }
  } else {
    if (game_space->space[figur->position[0]][figur->position[1] - 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] - 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] - 1] !=
            figur->code) {
      result = true;
    }
  }

  return result;
}
bool traffic_permit_left_for_figur_3(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[0]][figur->position[1] - 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] - 1] !=
            figur->code) {
      result = true;
    }
  } else if (figur->rotations_position == 1) {
    if (game_space->space[figur->position[2]][figur->position[3] - 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] - 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] - 1] !=
            figur->code) {
      result = true;
    }
  } else if (figur->rotations_position == 2) {
    if (game_space->space[figur->position[0]][figur->position[1] - 1] !=
            figur->code &&
        game_space->space[figur->position[2]][figur->position[3] - 1] !=
            figur->code) {
      result = true;
    }
  } else {
    if (game_space->space[figur->position[0]][figur->position[1] - 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] - 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] - 1] !=
            figur->code) {
      result = true;
    }
  }

  return result;
}
bool traffic_permit_left_for_figur_4(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[0]][figur->position[1] - 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] - 1] !=
            figur->code) {
      result = true;
    }
  }
  return result;
}
bool traffic_permit_left_for_figur_5(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[2]][figur->position[3] - 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] - 1] !=
            figur->code) {
      result = true;
    }
  } else {
    if (game_space->space[figur->position[0]][figur->position[1] - 1] !=
            figur->code &&
        game_space->space[figur->position[2]][figur->position[3] - 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] - 1] !=
            figur->code) {
      result = true;
    }
  }

  return result;
}
bool traffic_permit_left_for_figur_6(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[0]][figur->position[1] - 1] !=
            figur->code &&
        game_space->space[figur->position[2]][figur->position[3] - 1] !=
            figur->code) {
      result = true;
    }
  } else if (figur->rotations_position == 1) {
    if (game_space->space[figur->position[2]][figur->position[3] - 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] - 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] - 1] !=
            figur->code) {
      result = true;
    }
  } else if (figur->rotations_position == 2) {
    if (game_space->space[figur->position[0]][figur->position[1] - 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] - 1] !=
            figur->code) {
      result = true;
    }
  } else {
    if (game_space->space[figur->position[0]][figur->position[1] - 1] !=
            figur->code &&
        game_space->space[figur->position[2]][figur->position[3] - 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] - 1] !=
            figur->code) {
      result = true;
    }
  }

  return result;
}
bool traffic_permit_left_for_figur_7(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[0]][figur->position[1] - 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] - 1] !=
            figur->code) {
      result = true;
    }
  } else {
    if (game_space->space[figur->position[0]][figur->position[1] - 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] - 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] - 1] !=
            figur->code) {
      result = true;
    }
  }

  return result;
}

bool traffic_permit_right_for_figur_1(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[6]][figur->position[7] + 1] !=
        figur->code) {
      result = true;
    }
  } else {
    if (game_space->space[figur->position[0]][figur->position[1] + 1] !=
            figur->code &&
        game_space->space[figur->position[2]][figur->position[3] + 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] + 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] + 1] !=
            figur->code) {
      result = true;
    }
  }

  return result;
}
bool traffic_permit_right_for_figur_2(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[0]][figur->position[1] + 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] + 1] !=
            figur->code) {
      result = true;
    }
  } else if (figur->rotations_position == 1) {
    if (game_space->space[figur->position[0]][figur->position[1] + 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] + 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] + 1] !=
            figur->code) {
      result = true;
    }
  } else if (figur->rotations_position == 2) {
    if (game_space->space[figur->position[0]][figur->position[1] + 1] !=
            figur->code &&
        game_space->space[figur->position[2]][figur->position[3] + 1] !=
            figur->code) {
      result = true;
    }
  } else {
    if (game_space->space[figur->position[2]][figur->position[3] + 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] + 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] + 1] !=
            figur->code) {
      result = true;
    }
  }
  return result;
}
bool traffic_permit_right_for_figur_3(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[0]][figur->position[1] + 1] !=
            figur->code &&
        game_space->space[figur->position[2]][figur->position[3] + 1] !=
            figur->code) {
      result = true;
    }
  } else if (figur->rotations_position == 1) {
    if (game_space->space[figur->position[0]][figur->position[1] + 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] + 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] + 1] !=
            figur->code) {
      result = true;
    }
  } else if (figur->rotations_position == 2) {
    if (game_space->space[figur->position[0]][figur->position[1] + 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] + 1] !=
            figur->code) {
      result = true;
    }
  } else {
    if (game_space->space[figur->position[2]][figur->position[3] + 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] + 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] + 1] !=
            figur->code) {
      result = true;
    }
  }
  return result;
}
bool traffic_permit_right_for_figur_4(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (game_space->space[figur->position[2]][figur->position[3] + 1] !=
          figur->code &&
      game_space->space[figur->position[6]][figur->position[7] + 1] !=
          figur->code) {
    result = true;
  }
  return result;
}
bool traffic_permit_right_for_figur_5(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[0]][figur->position[1] + 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] + 1] !=
            figur->code) {
      result = true;
    }
  } else {
    if (game_space->space[figur->position[0]][figur->position[1] + 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] + 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] + 1] !=
            figur->code) {
      result = true;
    }
  }

  return result;
}
bool traffic_permit_right_for_figur_6(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[0]][figur->position[1] + 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] + 1] !=
            figur->code) {
      result = true;
    }
  } else if (figur->rotations_position == 1) {
    if (game_space->space[figur->position[0]][figur->position[1] + 1] !=
            figur->code &&
        game_space->space[figur->position[2]][figur->position[3] + 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] + 1] !=
            figur->code) {
      result = true;
    }
  } else if (figur->rotations_position == 2) {
    if (game_space->space[figur->position[0]][figur->position[1] + 1] !=
            figur->code &&
        game_space->space[figur->position[2]][figur->position[3] + 1] !=
            figur->code) {
      result = true;
    }
  } else {
    if (game_space->space[figur->position[2]][figur->position[3] + 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] + 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] + 1] !=
            figur->code) {
      result = true;
    }
  }
  return result;
}
bool traffic_permit_right_for_figur_7(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[2]][figur->position[3] + 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] + 1] !=
            figur->code) {
      result = true;
    }
  } else {
    if (game_space->space[figur->position[0]][figur->position[1] + 1] !=
            figur->code &&
        game_space->space[figur->position[2]][figur->position[3] + 1] !=
            figur->code &&
        game_space->space[figur->position[6]][figur->position[7] + 1] !=
            figur->code) {
      result = true;
    }
  }

  return result;
}

bool traffic_permit_down_for_figur_1(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[0] + 2][figur->position[1]] !=
            figur->code &&
        game_space->space[figur->position[2] + 2][figur->position[3]] !=
            figur->code &&
        game_space->space[figur->position[4] + 2][figur->position[5]] !=
            figur->code &&
        game_space->space[figur->position[6] + 2][figur->position[7]] !=
            figur->code) {
      result = true;
    }
  } else {
    if (game_space->space[figur->position[6] + 2][figur->position[7]] !=
        figur->code) {
      result = true;
    }
  }
  return result;
}
bool traffic_permit_down_for_figur_2(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[2] + 2][figur->position[3]] !=
            figur->code &&
        game_space->space[figur->position[4] + 2][figur->position[5]] !=
            figur->code &&
        game_space->space[figur->position[6] + 2][figur->position[7]] !=
            figur->code) {
      result = true;
    }
  } else if (figur->rotations_position == 1) {
    if (game_space->space[figur->position[0] + 2][figur->position[1]] !=
            figur->code &&
        game_space->space[figur->position[6] + 2][figur->position[7]] !=
            figur->code) {
      result = true;
    }
  } else if (figur->rotations_position == 2) {
    if (game_space->space[figur->position[0] + 2][figur->position[1]] !=
            figur->code &&
        game_space->space[figur->position[4] + 2][figur->position[5]] !=
            figur->code &&
        game_space->space[figur->position[6] + 2][figur->position[7]] !=
            figur->code) {
      result = true;
    }
  } else {
    if (game_space->space[figur->position[0] + 2][figur->position[1]] !=
            figur->code &&
        game_space->space[figur->position[2] + 2][figur->position[3]] !=
            figur->code) {
      result = true;
    }
  }
  return result;
}
bool traffic_permit_down_for_figur_3(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[2] + 2][figur->position[3]] !=
            figur->code &&
        game_space->space[figur->position[4] + 2][figur->position[5]] !=
            figur->code &&
        game_space->space[figur->position[6] + 2][figur->position[7]] !=
            figur->code) {
      result = true;
    }
  } else if (figur->rotations_position == 1) {
    if (game_space->space[figur->position[0] + 2][figur->position[1]] !=
            figur->code &&
        game_space->space[figur->position[2] + 2][figur->position[3]] !=
            figur->code) {
      result = true;
    }
  } else if (figur->rotations_position == 2) {
    if (game_space->space[figur->position[0] + 2][figur->position[1]] !=
            figur->code &&
        game_space->space[figur->position[4] + 2][figur->position[5]] !=
            figur->code &&
        game_space->space[figur->position[6] + 2][figur->position[7]] !=
            figur->code) {
      result = true;
    }
  } else {
    if (game_space->space[figur->position[0] + 2][figur->position[1]] !=
            figur->code &&
        game_space->space[figur->position[6] + 2][figur->position[7]] !=
            figur->code) {
      result = true;
    }
  }
  return result;
}
bool traffic_permit_down_for_figur_4(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (game_space->space[figur->position[4] + 2][figur->position[5]] !=
          figur->code &&
      game_space->space[figur->position[6] + 2][figur->position[7]] !=
          figur->code) {
    result = true;
  }

  return result;
}
bool traffic_permit_down_for_figur_5(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[0] + 2][figur->position[1]] !=
            figur->code &&
        game_space->space[figur->position[4] + 2][figur->position[5]] !=
            figur->code &&
        game_space->space[figur->position[6] + 2][figur->position[7]] !=
            figur->code) {
      result = true;
    }
  } else {
    if (game_space->space[figur->position[0] + 2][figur->position[1]] !=
            figur->code &&
        game_space->space[figur->position[4] + 2][figur->position[5]] !=
            figur->code) {
      result = true;
    }
  }
  return result;
}
bool traffic_permit_down_for_figur_6(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[2] + 2][figur->position[3]] !=
            figur->code &&
        game_space->space[figur->position[4] + 2][figur->position[5]] !=
            figur->code &&
        game_space->space[figur->position[6] + 2][figur->position[7]] !=
            figur->code) {
      result = true;
    }
  } else if (figur->rotations_position == 1) {
    if (game_space->space[figur->position[0] + 2][figur->position[1]] !=
            figur->code &&
        game_space->space[figur->position[6] + 2][figur->position[7]] !=
            figur->code) {
      result = true;
    }
  } else if (figur->rotations_position == 2) {
    if (game_space->space[figur->position[0] + 2][figur->position[1]] !=
            figur->code &&
        game_space->space[figur->position[2] + 2][figur->position[3]] !=
            figur->code &&
        game_space->space[figur->position[6] + 2][figur->position[7]] !=
            figur->code) {
      result = true;
    }
  } else {
    if (game_space->space[figur->position[0] + 2][figur->position[1]] !=
            figur->code &&
        game_space->space[figur->position[2] + 2][figur->position[3]] !=
            figur->code) {
      result = true;
    }
  }
  return result;
}
bool traffic_permit_down_for_figur_7(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[0] + 2][figur->position[1]] !=
            figur->code &&
        game_space->space[figur->position[4] + 2][figur->position[5]] !=
            figur->code &&
        game_space->space[figur->position[6] + 2][figur->position[7]] !=
            figur->code) {
      result = true;
    }
  } else {
    if (game_space->space[figur->position[2] + 2][figur->position[3]] !=
            figur->code &&
        game_space->space[figur->position[6] + 2][figur->position[7]] !=
            figur->code) {
      result = true;
    }
  }
  return result;
}

bool traffic_permit_flip_for_figur_1(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[4] - 2][figur->position[5]] !=
            figur->code &&
        game_space->space[figur->position[4] - 1][figur->position[5]] !=
            figur->code &&
        game_space->space[figur->position[4] + 1][figur->position[5]] !=
            figur->code) {
      result = true;
    }
  } else {
    if (game_space->space[figur->position[4]][figur->position[5] - 2] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] - 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] + 1] !=
            figur->code) {
      result = true;
    }
  }
  return result;
}
bool traffic_permit_flip_for_figur_2(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[4] - 1][figur->position[5] + 1] !=
            figur->code &&
        game_space->space[figur->position[4] - 1][figur->position[5]] !=
            figur->code &&
        game_space->space[figur->position[4] + 1][figur->position[5]] !=
            figur->code) {
      result = true;
    }
  } else if (figur->rotations_position == 1) {
    if (game_space->space[figur->position[4] + 1][figur->position[5] + 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] + 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] - 1] !=
            figur->code) {
      result = true;
    }
  } else if (figur->rotations_position == 2) {
    if (game_space->space[figur->position[4] + 1][figur->position[5] - 1] !=
            figur->code &&
        game_space->space[figur->position[4] + 1][figur->position[5]] !=
            figur->code &&
        game_space->space[figur->position[4] - 1][figur->position[5]] !=
            figur->code) {
      result = true;
    }
  } else {
    if (game_space->space[figur->position[4] - 1][figur->position[5] - 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] - 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] + 1] !=
            figur->code) {
      result = true;
    }
  }
  return result;
}
bool traffic_permit_flip_for_figur_3(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[4] + 1][figur->position[5] + 1] !=
            figur->code &&
        game_space->space[figur->position[4] + 1][figur->position[5]] !=
            figur->code &&
        game_space->space[figur->position[4] - 1][figur->position[5]] !=
            figur->code) {
      result = true;
    }
  } else if (figur->rotations_position == 1) {
    if (game_space->space[figur->position[4] + 1][figur->position[5] - 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] - 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] + 1] !=
            figur->code) {
      result = true;
    }
  } else if (figur->rotations_position == 2) {
    if (game_space->space[figur->position[4] - 1][figur->position[5] - 1] !=
            figur->code &&
        game_space->space[figur->position[4] - 1][figur->position[5]] !=
            figur->code &&
        game_space->space[figur->position[4] + 1][figur->position[5]] !=
            figur->code) {
      result = true;
    }
  } else {
    if (game_space->space[figur->position[4] - 1][figur->position[5] + 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] + 1] !=
            figur->code &&
        game_space->space[figur->position[4]][figur->position[5] - 1] !=
            figur->code) {
      result = true;
    }
  }
  return result;
}
bool traffic_permit_flip_for_figur_5(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[4] - 1][figur->position[5] - 1] !=
            figur->code &&
        game_space->space[figur->position[4] + 1][figur->position[5]] !=
            figur->code) {
      result = true;
    }
  } else {
    if (game_space->space[figur->position[4] - 1][figur->position[5] + 1] !=
            figur->code &&
        game_space->space[figur->position[4] - 1][figur->position[5]] !=
            figur->code) {
      result = true;
    }
  }
  return result;
}
bool traffic_permit_flip_for_figur_6(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[4] + 1][figur->position[5]] !=
        figur->code) {
      result = true;
    }
  } else if (figur->rotations_position == 1) {
    if (game_space->space[figur->position[4]][figur->position[5] - 1] !=
        figur->code) {
      result = true;
    }
  } else if (figur->rotations_position == 2) {
    if (game_space->space[figur->position[4] - 1][figur->position[5]] !=
        figur->code) {
      result = true;
    }
  } else {
    if (game_space->space[figur->position[4]][figur->position[5] + 1] !=
        figur->code) {
      result = true;
    }
  }
  return result;
}
bool traffic_permit_flip_for_figur_7(Game_space* game_space, Figur* figur) {
  bool result = false;
  if (figur->rotations_position == 0) {
    if (game_space->space[figur->position[4] - 1][figur->position[5] + 1] !=
            figur->code &&
        game_space->space[figur->position[4] + 1][figur->position[5]] !=
            figur->code) {
      result = true;
    }
  } else {
    if (game_space->space[figur->position[4] - 1][figur->position[5] - 1] !=
            figur->code &&
        game_space->space[figur->position[4] - 1][figur->position[5]] !=
            figur->code) {
      result = true;
    }
  }
  return result;
}

bool end_space(Figur* figur) {
  bool code_result = false;
  if (figur->position[0] == 20 || figur->position[2] == 20 ||
      figur->position[4] == 20 || figur->position[6] == 20) {
    code_result = true;
  }

  return code_result;
}

void remove_tresh(Figur* figur, Game_space* game_space) {
  game_space->space[figur->position[0] - 1][figur->position[1]] = 0;
  game_space->space[figur->position[2] - 1][figur->position[3]] = 0;
  game_space->space[figur->position[4] - 1][figur->position[5]] = 0;
  game_space->space[figur->position[6] - 1][figur->position[7]] = 0;
}

void remove_trash_on_poly_for_figur_1(Figur* figur, Game_space* game_space) {
  if (figur->rotations_position == 0) {
    if ((game_space->space[figur->position[0]][figur->position[1]] !=
             figur->code &&
         game_space->space[figur->position[2]][figur->position[3]] !=
             figur->code &&
         game_space->space[figur->position[4]][figur->position[5]] !=
             figur->code &&
         game_space->space[figur->position[6]][figur->position[7]] !=
             figur->code)) {
      remove_tresh(figur, game_space);
    }
  } else {
    if ((game_space->space[figur->position[6]][figur->position[7]] !=
         figur->code)) {
      remove_tresh(figur, game_space);
    }
  }
}

void remove_trash_on_poly_for_figur_2(Figur* figur, Game_space* game_space) {
  if (figur->rotations_position == 0) {
    if ((game_space->space[figur->position[2]][figur->position[3]] !=
             figur->code &&
         game_space->space[figur->position[4]][figur->position[5]] !=
             figur->code &&
         game_space->space[figur->position[6]][figur->position[7]] !=
             figur->code)) {
      remove_tresh(figur, game_space);
    }
  } else if (figur->rotations_position == 1) {
    if ((game_space->space[figur->position[0]][figur->position[1]] !=
             figur->code &&
         game_space->space[figur->position[6]][figur->position[7]] !=
             figur->code)) {
      remove_tresh(figur, game_space);
    }
  } else if (figur->rotations_position == 2) {
    if ((game_space->space[figur->position[0]][figur->position[1]] !=
             figur->code &&
         game_space->space[figur->position[4]][figur->position[5]] !=
             figur->code &&
         game_space->space[figur->position[6]][figur->position[7]] !=
             figur->code)) {
      remove_tresh(figur, game_space);
    }
  } else {
    if ((game_space->space[figur->position[0]][figur->position[1]] !=
             figur->code &&
         game_space->space[figur->position[2]][figur->position[3]] !=
             figur->code)) {
      remove_tresh(figur, game_space);
    }
  }
}

void remove_trash_on_poly_for_figur_3(Figur* figur, Game_space* game_space) {
  if (figur->rotations_position == 0) {
    if ((game_space->space[figur->position[2]][figur->position[3]] !=
             figur->code &&
         game_space->space[figur->position[4]][figur->position[5]] !=
             figur->code &&
         game_space->space[figur->position[6]][figur->position[7]] !=
             figur->code)) {
      remove_tresh(figur, game_space);
    }
  } else if (figur->rotations_position == 1) {
    if ((game_space->space[figur->position[0]][figur->position[1]] !=
             figur->code &&
         game_space->space[figur->position[2]][figur->position[3]] !=
             figur->code)) {
      remove_tresh(figur, game_space);
    }
  } else if (figur->rotations_position == 2) {
    if ((game_space->space[figur->position[0]][figur->position[1]] !=
             figur->code &&
         game_space->space[figur->position[4]][figur->position[5]] !=
             figur->code &&
         game_space->space[figur->position[6]][figur->position[7]] !=
             figur->code)) {
      remove_tresh(figur, game_space);
    }
  } else {
    if ((game_space->space[figur->position[0]][figur->position[1]] !=
             figur->code &&
         game_space->space[figur->position[6]][figur->position[7]] !=
             figur->code)) {
      remove_tresh(figur, game_space);
    }
  }
}

void remove_trash_on_poly_for_figur_4(Figur* figur, Game_space* game_space) {
  if ((game_space->space[figur->position[4]][figur->position[5]] !=
           figur->code &&
       game_space->space[figur->position[6]][figur->position[7]] !=
           figur->code)) {
    remove_tresh(figur, game_space);
  }
}

void remove_trash_on_poly_for_figur_5(Figur* figur, Game_space* game_space) {
  if (figur->rotations_position == 0) {
    if ((game_space->space[figur->position[0]][figur->position[1]] !=
             figur->code &&
         game_space->space[figur->position[4]][figur->position[5]] !=
             figur->code &&
         game_space->space[figur->position[6]][figur->position[7]] !=
             figur->code)) {
      remove_tresh(figur, game_space);
    }
  } else {
    if ((game_space->space[figur->position[2]][figur->position[3]] !=
             figur->code &&
         game_space->space[figur->position[6]][figur->position[7]] !=
             figur->code)) {
      remove_tresh(figur, game_space);
    }
  }
}

void remove_trash_on_poly_for_figur_6(Figur* figur, Game_space* game_space) {
  if (figur->rotations_position == 0) {
    if ((game_space->space[figur->position[2]][figur->position[3]] !=
             figur->code &&
         game_space->space[figur->position[4]][figur->position[5]] !=
             figur->code &&
         game_space->space[figur->position[6]][figur->position[7]] !=
             figur->code)) {
      remove_tresh(figur, game_space);
    }
  } else if (figur->rotations_position == 1) {
    if ((game_space->space[figur->position[0]][figur->position[1]] !=
             figur->code &&
         game_space->space[figur->position[6]][figur->position[7]] !=
             figur->code)) {
      remove_tresh(figur, game_space);
    }
  } else if (figur->rotations_position == 2) {
    if ((game_space->space[figur->position[0]][figur->position[1]] !=
             figur->code &&
         game_space->space[figur->position[2]][figur->position[3]] !=
             figur->code &&
         game_space->space[figur->position[6]][figur->position[7]] !=
             figur->code)) {
      remove_tresh(figur, game_space);
    }
  } else {
    if ((game_space->space[figur->position[0]][figur->position[1]] !=
             figur->code &&
         game_space->space[figur->position[2]][figur->position[3]] !=
             figur->code)) {
      remove_tresh(figur, game_space);
    }
  }
}

void remove_trash_on_poly_for_figur_7(Figur* figur, Game_space* game_space) {
  if (figur->rotations_position == 0) {
    if ((game_space->space[figur->position[0]][figur->position[1]] !=
             figur->code &&
         game_space->space[figur->position[4]][figur->position[5]] !=
             figur->code &&
         game_space->space[figur->position[6]][figur->position[7]] !=
             figur->code)) {
      remove_tresh(figur, game_space);
    }
  } else {
    if ((game_space->space[figur->position[2]][figur->position[3]] !=
             figur->code &&
         game_space->space[figur->position[6]][figur->position[7]] !=
             figur->code)) {
      remove_tresh(figur, game_space);
    }
  }
}

void game_level_and_speed(GameInfo_t* game_info) {
  if (game_info->score >= LEVEL_UP * game_info->level) {
    float level_up = game_info->score / LEVEL_UP;
    level_up = floor(level_up);
    if (level_up > 0 && game_info->level + (int)level_up <= 10) {
      game_info->level += (int)level_up;
      game_info->speed -= 50 * (int)level_up;
    } else {
      game_info->level = 10;
      game_info->speed = 150;
    }
  }
}

int readNumberFromFile() {
  FILE* file = fopen("./src/game_state/state.txt", "r");
  int number = 0;
  fscanf(file, "%d", &number);

  fclose(file);
  return number;
}

void writeNumberToFile(int number) {
  FILE* file = fopen("./src/game_state/state.txt", "w");

  fprintf(file, "%d", number);
  fclose(file);
}

void figur_falling_down(Figur* figur) {
  figur->position[0]++;
  figur->position[2]++;
  figur->position[4]++;
  figur->position[6]++;
}

int get_random_number() {
  int rand_number = rand() % 7 + 1;
  return rand_number;
}

void get_figur(Figur* figur, GameInfo_t game_info) {
  init_figur(game_info.next_figur, figur);
}

void print_figur_in_game_poly(Game_space* game_space, Figur* figur) {
  game_space->space[figur->position[0]][figur->position[1]] = figur->code;
  game_space->space[figur->position[2]][figur->position[3]] = figur->code;
  game_space->space[figur->position[4]][figur->position[5]] = figur->code;
  game_space->space[figur->position[6]][figur->position[7]] = figur->code;
}

void print_next_figur(GameInfo_t* game_info) {
  Figur next_figur;
  init_next_figur(game_info->next_figur, &next_figur);
  game_info->next[next_figur.position[0]][next_figur.position[1]] =
      next_figur.code;
  game_info->next[next_figur.position[2]][next_figur.position[3]] =
      next_figur.code;
  game_info->next[next_figur.position[4]][next_figur.position[5]] =
      next_figur.code;
  game_info->next[next_figur.position[6]][next_figur.position[7]] =
      next_figur.code;
}

void clean_space_game(Game_space* game_space) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (game_space->space[i][j] == 3) {
        game_space->space[i][j] = 0;
      }
    }
  }
}

void init_space_game(Game_space* game_space) {
  game_space->space = (int**)malloc(HEIGHT * sizeof(int*));

  for (int i = 0; i < HEIGHT; i++) {
    game_space->space[i] = (int*)malloc(WIDTH * sizeof(int));
  }

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      game_space->space[i][j] = 0;
    }
  }
}

void init_game_info(GameInfo_t* game_info) {
  game_info->next = (int**)malloc(4 * sizeof(int*));

  for (int i = 0; i < 4; i++) {
    game_info->next[i] = (int*)malloc(6 * sizeof(int));
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 6; j++) {
      if (i == 0 || i == 3) {
        game_info->next[i][j] = 1;
      } else {
        game_info->next[i][j] = 0;
      }
    }
  }
}

void game_remove(Game_space* game_space, GameInfo_t* game_info) {
  for (int i = 0; i < HEIGHT; i++) {
    free(game_space->space[i]);
  }
  free(game_space->space);

  for (int i = 0; i < 4; i++) {
    free(game_info->next[i]);
  }
  free(game_info->next);
}
