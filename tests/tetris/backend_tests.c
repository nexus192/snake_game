#include "../../src/BrickGame/tetris/tetris_backend.h"
#include "run_tests.h"

START_TEST(test_backend_1) {
  Figur test_figur = {0};
  init_figur(1, &test_figur);
}
END_TEST

START_TEST(test_backend_2) {
  Figur test_figur = {0};
  init_figur(2, &test_figur);
}
END_TEST

START_TEST(test_backend_3) {
  Figur test_figur = {0};
  init_figur(3, &test_figur);
}
END_TEST

START_TEST(test_backend_4) {
  Figur test_figur = {0};
  init_figur(4, &test_figur);
}
END_TEST

START_TEST(test_backend_5) {
  Figur test_figur = {0};
  init_figur(5, &test_figur);
}
END_TEST

START_TEST(test_backend_6) {
  Figur test_figur = {0};
  init_figur(6, &test_figur);
}
END_TEST

START_TEST(test_backend_7) {
  Figur test_figur = {0};
  init_figur(7, &test_figur);
}
END_TEST

START_TEST(test_backend_1_1) {
  Figur test_figur = {0};
  init_next_figur(1, &test_figur);
}
END_TEST

START_TEST(test_backend_2_1) {
  Figur test_figur = {0};
  init_next_figur(2, &test_figur);
}
END_TEST

START_TEST(test_backend_3_1) {
  Figur test_figur = {0};
  init_next_figur(3, &test_figur);
}
END_TEST

START_TEST(test_backend_4_1) {
  Figur test_figur = {0};
  init_next_figur(4, &test_figur);
}
END_TEST

START_TEST(test_backend_5_1) {
  Figur test_figur = {0};
  init_next_figur(5, &test_figur);
}
END_TEST

START_TEST(test_backend_6_1) {
  Figur test_figur = {0};
  init_next_figur(6, &test_figur);
}
END_TEST

START_TEST(test_backend_7_1) {
  Figur test_figur = {0};
  init_next_figur(7, &test_figur);
}
END_TEST

START_TEST(test_backend_kill_figur) {
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_figur(7, &test_figur);
  init_game_info(&game_info);
  init_space_game(&game_spase);
  print_figur_in_game_poly(&game_spase, &test_figur);
  kill_figur(&test_figur, &game_spase);
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(test_backend_find_full_line_1) {
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  game_spase.space[5][1] = 3;
  game_spase.space[5][2] = 3;
  game_spase.space[5][3] = 3;
  game_spase.space[5][4] = 3;
  game_spase.space[5][5] = 3;
  game_spase.space[5][6] = 3;
  game_spase.space[5][7] = 3;
  game_spase.space[5][8] = 3;
  game_spase.space[5][9] = 3;
  find_full_line(&game_spase, &game_info);
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(test_backend_find_full_line_2) {
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  for (int j = 5; j < 7; j++) {
    for (int i = 1; i < 10; i++) {
      game_spase.space[j][i] = 3;
    }
  }
  find_full_line(&game_spase, &game_info);
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(test_backend_find_full_line_3) {
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  for (int j = 5; j < 8; j++) {
    for (int i = 1; i < 10; i++) {
      game_spase.space[j][i] = 3;
    }
  }
  find_full_line(&game_spase, &game_info);
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(test_backend_find_full_line_4) {
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  for (int j = 5; j < 9; j++) {
    for (int i = 1; i < 10; i++) {
      game_spase.space[j][i] = 3;
    }
  }
  find_full_line(&game_spase, &game_info);
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(test_check_on_game_over_1) {
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  bool result = check_on_game_over(game_spase);
  find_full_line(&game_spase, &game_info);
  game_remove(&game_spase, &game_info);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_check_on_game_over_2) {
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  game_spase.space[1][5] = 3;
  bool result = check_on_game_over(game_spase);
  find_full_line(&game_spase, &game_info);
  game_remove(&game_spase, &game_info);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_backend_rotation_1) {
  Figur test_figur = {0};
  init_figur(1, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
}
END_TEST

START_TEST(test_backend_rotation_2) {
  Figur test_figur = {0};
  init_figur(2, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
}
END_TEST

START_TEST(test_backend_rotation_3) {
  Figur test_figur = {0};
  init_figur(3, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
}
END_TEST

START_TEST(test_backend_rotation_4) {
  Figur test_figur = {0};
  init_figur(5, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
}
END_TEST

START_TEST(test_backend_rotation_5) {
  Figur test_figur = {0};
  init_figur(6, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
}
END_TEST

START_TEST(test_backend_rotation_6) {
  Figur test_figur = {0};
  init_figur(7, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
}
END_TEST

START_TEST(test_tetris_1_1) {
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(1, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(test_tetris_1_2) {
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(1, &test_figur);
  figur_falling_down(&test_figur, &game_spase, &direction);
  figur_falling_down(&test_figur, &game_spase, &direction);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(test_tetris_2_1) {
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(2, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(test_tetris_2_2) {
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(2, &test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(test_tetris_2_3) {
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(2, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(test_tetris_2_4) {
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(2, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(test_tetris_3_1) {
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(3, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(test_tetris_3_2) {
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(3, &test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(test_tetris_3_3) {
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(3, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(test_tetris_3_4) {
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(3, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(test_tetris_4) {
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(4, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(test_tetris_5_1) {
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(5, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(test_tetris_5_2) {
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(5, &test_figur);
  figur_falling_down(&test_figur, &game_spase, &direction);
  figur_falling_down(&test_figur, &game_spase, &direction);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(test_tetris_6_1) {
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(6, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(test_tetris_6_2) {
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(6, &test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(test_tetris_6_3) {
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(6, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(test_tetris_7_1) {
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(7, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(test_tetris_7_2) {
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(7, &test_figur);
  figur_falling_down(&test_figur, &game_spase, &direction);
  figur_falling_down(&test_figur, &game_spase, &direction);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(test_tetris_6_4) {
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(6, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(test_tetris_traffic_permit_left_1_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(1, &test_figur);
  figur_falling_down(&test_figur, &game_spase, &direction);
  figur_falling_down(&test_figur, &game_spase, &direction);
  // rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_left(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]--;
        test_figur.position[3]--;
        test_figur.position[5]--;
        test_figur.position[7]--;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_left_1_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(1, &test_figur);
  figur_falling_down(&test_figur, &game_spase, &direction);
  figur_falling_down(&test_figur, &game_spase, &direction);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_left(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]--;
        test_figur.position[3]--;
        test_figur.position[5]--;
        test_figur.position[7]--;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_left_2_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(2, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_left(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]--;
        test_figur.position[3]--;
        test_figur.position[5]--;
        test_figur.position[7]--;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_left_2_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(2, &test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_left(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]--;
        test_figur.position[3]--;
        test_figur.position[5]--;
        test_figur.position[7]--;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_left_2_3) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(2, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_left(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]--;
        test_figur.position[3]--;
        test_figur.position[5]--;
        test_figur.position[7]--;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_left_2_4) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(2, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_left(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]--;
        test_figur.position[3]--;
        test_figur.position[5]--;
        test_figur.position[7]--;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_left_3_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(3, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_left(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]--;
        test_figur.position[3]--;
        test_figur.position[5]--;
        test_figur.position[7]--;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_left_3_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(3, &test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_left(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]--;
        test_figur.position[3]--;
        test_figur.position[5]--;
        test_figur.position[7]--;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_left_3_3) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(3, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_left(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]--;
        test_figur.position[3]--;
        test_figur.position[5]--;
        test_figur.position[7]--;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_left_3_4) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(3, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_left(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]--;
        test_figur.position[3]--;
        test_figur.position[5]--;
        test_figur.position[7]--;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_left_4) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(4, &test_figur);
  // figur_falling_down(&test_figur, &game_spase, &direction);
  // figur_falling_down(&test_figur, &game_spase, &direction);
  // rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_left(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]--;
        test_figur.position[3]--;
        test_figur.position[5]--;
        test_figur.position[7]--;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_left_5_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(5, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_left(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]--;
        test_figur.position[3]--;
        test_figur.position[5]--;
        test_figur.position[7]--;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_left_5_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(5, &test_figur);
  figur_falling_down(&test_figur, &game_spase, &direction);
  figur_falling_down(&test_figur, &game_spase, &direction);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_left(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]--;
        test_figur.position[3]--;
        test_figur.position[5]--;
        test_figur.position[7]--;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_left_6_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(6, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_left(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]--;
        test_figur.position[3]--;
        test_figur.position[5]--;
        test_figur.position[7]--;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_left_6_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(6, &test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_left(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]--;
        test_figur.position[3]--;
        test_figur.position[5]--;
        test_figur.position[7]--;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_left_6_3) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(6, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_left(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]--;
        test_figur.position[3]--;
        test_figur.position[5]--;
        test_figur.position[7]--;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_left_6_4) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(6, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_left(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]--;
        test_figur.position[3]--;
        test_figur.position[5]--;
        test_figur.position[7]--;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_left_7_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(7, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_left(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]--;
        test_figur.position[3]--;
        test_figur.position[5]--;
        test_figur.position[7]--;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_left_7_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(7, &test_figur);
  figur_falling_down(&test_figur, &game_spase, &direction);
  figur_falling_down(&test_figur, &game_spase, &direction);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_left(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]--;
        test_figur.position[3]--;
        test_figur.position[5]--;
        test_figur.position[7]--;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_left_loop_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  for (int i = 1; i < 9; i++) {
    game_spase.space[i][1] = 3;
  }
  for (int i = 1; i < 9; i++) {
    game_spase.space[i][9] = 3;
  }
  for (int i = 1; i < 8; i++) {
    init_figur(i, &test_figur);
    while (test_figur.move_triger == 0 && us_act == Start &&
           us_act != Terminate) {
      if (conditions_of_falling_down(test_figur, game_spase) == true) {
        print_figur_in_game_poly(&game_spase, &test_figur);
        if (traffic_permit_left(&game_spase, &test_figur) == true) {
          kill_figur(&test_figur, &game_spase);
          test_figur.position[1]--;
          test_figur.position[3]--;
          test_figur.position[5]--;
          test_figur.position[7]--;
          print_figur_in_game_poly(&game_spase, &test_figur);
        }
        figur_falling_down(&test_figur, &game_spase, &direction);

      } else {
        test_figur.move_triger = 1;
      }
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_left_loop_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  for (int i = 1; i < 10; i++) {
    game_spase.space[i][1] = 3;
  }
  for (int i = 1; i < 10; i++) {
    game_spase.space[i][9] = 3;
  }
  for (int i = 1; i < 8; i++) {
    init_figur(i, &test_figur);
    figur_falling_down(&test_figur, &game_spase, &direction);
    figur_falling_down(&test_figur, &game_spase, &direction);
    rotation_figurs(&test_figur);
    while (test_figur.move_triger == 0 && us_act == Start &&
           us_act != Terminate) {
      if (conditions_of_falling_down(test_figur, game_spase) == true) {
        print_figur_in_game_poly(&game_spase, &test_figur);
        if (traffic_permit_left(&game_spase, &test_figur) == true) {
          kill_figur(&test_figur, &game_spase);
          test_figur.position[1]--;
          test_figur.position[3]--;
          test_figur.position[5]--;
          test_figur.position[7]--;
          print_figur_in_game_poly(&game_spase, &test_figur);
        }
        figur_falling_down(&test_figur, &game_spase, &direction);

      } else {
        test_figur.move_triger = 1;
      }
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_left_loop_3) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  for (int i = 1; i < 10; i++) {
    game_spase.space[i][1] = 3;
  }
  for (int i = 1; i < 10; i++) {
    game_spase.space[i][9] = 3;
  }
  for (int i = 1; i < 8; i++) {
    init_figur(i, &test_figur);
    figur_falling_down(&test_figur, &game_spase, &direction);
    figur_falling_down(&test_figur, &game_spase, &direction);
    rotation_figurs(&test_figur);
    rotation_figurs(&test_figur);
    while (test_figur.move_triger == 0 && us_act == Start &&
           us_act != Terminate) {
      if (conditions_of_falling_down(test_figur, game_spase) == true) {
        print_figur_in_game_poly(&game_spase, &test_figur);
        if (traffic_permit_left(&game_spase, &test_figur) == true) {
          kill_figur(&test_figur, &game_spase);
          test_figur.position[1]--;
          test_figur.position[3]--;
          test_figur.position[5]--;
          test_figur.position[7]--;
          print_figur_in_game_poly(&game_spase, &test_figur);
        }
        figur_falling_down(&test_figur, &game_spase, &direction);

      } else {
        test_figur.move_triger = 1;
      }
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_left_loop_4) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  for (int i = 1; i < 10; i++) {
    game_spase.space[i][1] = 3;
  }
  for (int i = 1; i < 10; i++) {
    game_spase.space[i][9] = 3;
  }
  for (int i = 1; i < 8; i++) {
    init_figur(i, &test_figur);
    figur_falling_down(&test_figur, &game_spase, &direction);
    figur_falling_down(&test_figur, &game_spase, &direction);
    rotation_figurs(&test_figur);
    rotation_figurs(&test_figur);
    rotation_figurs(&test_figur);
    while (test_figur.move_triger == 0 && us_act == Start &&
           us_act != Terminate) {
      if (conditions_of_falling_down(test_figur, game_spase) == true) {
        print_figur_in_game_poly(&game_spase, &test_figur);
        if (traffic_permit_left(&game_spase, &test_figur) == true) {
          kill_figur(&test_figur, &game_spase);
          test_figur.position[1]--;
          test_figur.position[3]--;
          test_figur.position[5]--;
          test_figur.position[7]--;
          print_figur_in_game_poly(&game_spase, &test_figur);
        }
        figur_falling_down(&test_figur, &game_spase, &direction);

      } else {
        test_figur.move_triger = 1;
      }
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

/////////////////////////////////////////

START_TEST(test_tetris_traffic_permit_right_1_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(1, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_right(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]++;
        test_figur.position[3]++;
        test_figur.position[5]++;
        test_figur.position[7]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_right_1_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(1, &test_figur);
  figur_falling_down(&test_figur, &game_spase, &direction);
  figur_falling_down(&test_figur, &game_spase, &direction);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_right(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]++;
        test_figur.position[3]++;
        test_figur.position[5]++;
        test_figur.position[7]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_right_2_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(2, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_right(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]++;
        test_figur.position[3]++;
        test_figur.position[5]++;
        test_figur.position[7]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_right_2_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(2, &test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_right(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]++;
        test_figur.position[3]++;
        test_figur.position[5]++;
        test_figur.position[7]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_right_2_3) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(2, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_right(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]++;
        test_figur.position[3]++;
        test_figur.position[5]++;
        test_figur.position[7]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_right_2_4) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(2, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_right(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]++;
        test_figur.position[3]++;
        test_figur.position[5]++;
        test_figur.position[7]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_right_3_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(3, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_right(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]++;
        test_figur.position[3]++;
        test_figur.position[5]++;
        test_figur.position[7]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_right_3_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(3, &test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_right(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]++;
        test_figur.position[3]++;
        test_figur.position[5]++;
        test_figur.position[7]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_right_3_3) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(3, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_right(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]++;
        test_figur.position[3]++;
        test_figur.position[5]++;
        test_figur.position[7]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_right_3_4) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(3, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_right(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]++;
        test_figur.position[3]++;
        test_figur.position[5]++;
        test_figur.position[7]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_right_4) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(4, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_right(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]++;
        test_figur.position[3]++;
        test_figur.position[5]++;
        test_figur.position[7]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_right_5_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(5, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_right(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]++;
        test_figur.position[3]++;
        test_figur.position[5]++;
        test_figur.position[7]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_right_5_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(5, &test_figur);
  figur_falling_down(&test_figur, &game_spase, &direction);
  figur_falling_down(&test_figur, &game_spase, &direction);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_right(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]++;
        test_figur.position[3]++;
        test_figur.position[5]++;
        test_figur.position[7]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_right_6_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(6, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_right(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]++;
        test_figur.position[3]++;
        test_figur.position[5]++;
        test_figur.position[7]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_right_6_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(6, &test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_right(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]++;
        test_figur.position[3]++;
        test_figur.position[5]++;
        test_figur.position[7]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_right_6_3) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(6, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_right(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]++;
        test_figur.position[3]++;
        test_figur.position[5]++;
        test_figur.position[7]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_right_6_4) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(6, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_right(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]++;
        test_figur.position[3]++;
        test_figur.position[5]++;
        test_figur.position[7]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_right_7_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(7, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_right(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]++;
        test_figur.position[3]++;
        test_figur.position[5]++;
        test_figur.position[7]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_right_7_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(7, &test_figur);
  figur_falling_down(&test_figur, &game_spase, &direction);
  figur_falling_down(&test_figur, &game_spase, &direction);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_right(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[1]++;
        test_figur.position[3]++;
        test_figur.position[5]++;
        test_figur.position[7]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_right_loop_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][1] = 3;
  }
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][9] = 3;
  }
  for (int i = 1; i < 8; i++) {
    init_figur(i, &test_figur);
    while (test_figur.move_triger == 0 && us_act == Start &&
           us_act != Terminate) {
      if (conditions_of_falling_down(test_figur, game_spase) == true) {
        print_figur_in_game_poly(&game_spase, &test_figur);
        if (traffic_permit_right(&game_spase, &test_figur) == true) {
          kill_figur(&test_figur, &game_spase);
          test_figur.position[1]++;
          test_figur.position[3]++;
          test_figur.position[5]++;
          test_figur.position[7]++;
          print_figur_in_game_poly(&game_spase, &test_figur);
        }
        figur_falling_down(&test_figur, &game_spase, &direction);

      } else {
        test_figur.move_triger = 1;
      }
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_right_loop_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][1] = 3;
  }
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][9] = 3;
  }
  for (int i = 1; i < 8; i++) {
    init_figur(i, &test_figur);
    figur_falling_down(&test_figur, &game_spase, &direction);
    figur_falling_down(&test_figur, &game_spase, &direction);
    rotation_figurs(&test_figur);
    while (test_figur.move_triger == 0 && us_act == Start &&
           us_act != Terminate) {
      if (conditions_of_falling_down(test_figur, game_spase) == true) {
        print_figur_in_game_poly(&game_spase, &test_figur);
        if (traffic_permit_right(&game_spase, &test_figur) == true) {
          kill_figur(&test_figur, &game_spase);
          test_figur.position[1]++;
          test_figur.position[3]++;
          test_figur.position[5]++;
          test_figur.position[7]++;
          print_figur_in_game_poly(&game_spase, &test_figur);
        }
        figur_falling_down(&test_figur, &game_spase, &direction);

      } else {
        test_figur.move_triger = 1;
      }
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_right_loop_3) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][1] = 3;
  }
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][9] = 3;
  }
  for (int i = 1; i < 8; i++) {
    init_figur(i, &test_figur);
    figur_falling_down(&test_figur, &game_spase, &direction);
    figur_falling_down(&test_figur, &game_spase, &direction);
    rotation_figurs(&test_figur);
    rotation_figurs(&test_figur);
    while (test_figur.move_triger == 0 && us_act == Start &&
           us_act != Terminate) {
      if (conditions_of_falling_down(test_figur, game_spase) == true) {
        print_figur_in_game_poly(&game_spase, &test_figur);
        if (traffic_permit_right(&game_spase, &test_figur) == true) {
          kill_figur(&test_figur, &game_spase);
          test_figur.position[1]++;
          test_figur.position[3]++;
          test_figur.position[5]++;
          test_figur.position[7]++;
          print_figur_in_game_poly(&game_spase, &test_figur);
        }
        figur_falling_down(&test_figur, &game_spase, &direction);

      } else {
        test_figur.move_triger = 1;
      }
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_right_loop_4) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][1] = 3;
  }
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][9] = 3;
  }
  for (int i = 1; i < 8; i++) {
    init_figur(i, &test_figur);
    figur_falling_down(&test_figur, &game_spase, &direction);
    figur_falling_down(&test_figur, &game_spase, &direction);
    rotation_figurs(&test_figur);
    rotation_figurs(&test_figur);
    rotation_figurs(&test_figur);
    while (test_figur.move_triger == 0 && us_act == Start &&
           us_act != Terminate) {
      if (conditions_of_falling_down(test_figur, game_spase) == true) {
        print_figur_in_game_poly(&game_spase, &test_figur);
        if (traffic_permit_right(&game_spase, &test_figur) == true) {
          kill_figur(&test_figur, &game_spase);
          test_figur.position[1]++;
          test_figur.position[3]++;
          test_figur.position[5]++;
          test_figur.position[7]++;
          print_figur_in_game_poly(&game_spase, &test_figur);
        }
        figur_falling_down(&test_figur, &game_spase, &direction);

      } else {
        test_figur.move_triger = 1;
      }
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

//////////////////////////////////////////////////////////

START_TEST(test_tetris_traffic_permit_down_1_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(1, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_down(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[0]++;
        test_figur.position[2]++;
        test_figur.position[4]++;
        test_figur.position[6]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_1_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(1, &test_figur);
  figur_falling_down(&test_figur, &game_spase, &direction);
  figur_falling_down(&test_figur, &game_spase, &direction);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_down(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[0]++;
        test_figur.position[2]++;
        test_figur.position[4]++;
        test_figur.position[6]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_2_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(2, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_down(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[0]++;
        test_figur.position[2]++;
        test_figur.position[4]++;
        test_figur.position[6]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_2_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(2, &test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_down(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[0]++;
        test_figur.position[2]++;
        test_figur.position[4]++;
        test_figur.position[6]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_2_3) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(2, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_down(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[0]++;
        test_figur.position[2]++;
        test_figur.position[4]++;
        test_figur.position[6]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_2_4) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(2, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_down(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[0]++;
        test_figur.position[2]++;
        test_figur.position[4]++;
        test_figur.position[6]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_3_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(3, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_down(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[0]++;
        test_figur.position[2]++;
        test_figur.position[4]++;
        test_figur.position[6]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_3_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(3, &test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_down(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[0]++;
        test_figur.position[2]++;
        test_figur.position[4]++;
        test_figur.position[6]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_3_3) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(3, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_down(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[0]++;
        test_figur.position[2]++;
        test_figur.position[4]++;
        test_figur.position[6]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_3_4) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(3, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_down(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[0]++;
        test_figur.position[2]++;
        test_figur.position[4]++;
        test_figur.position[6]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_4) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(4, &test_figur);
  // figur_falling_down(&test_figur, &game_spase, &direction);
  // figur_falling_down(&test_figur, &game_spase, &direction);
  // rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_down(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[0]++;
        test_figur.position[2]++;
        test_figur.position[4]++;
        test_figur.position[6]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_5_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(5, &test_figur);
  // figur_falling_down(&test_figur, &game_spase, &direction);
  // figur_falling_down(&test_figur, &game_spase, &direction);
  // rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_down(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[0]++;
        test_figur.position[2]++;
        test_figur.position[4]++;
        test_figur.position[6]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_5_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(5, &test_figur);
  figur_falling_down(&test_figur, &game_spase, &direction);
  figur_falling_down(&test_figur, &game_spase, &direction);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_down(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[0]++;
        test_figur.position[2]++;
        test_figur.position[4]++;
        test_figur.position[6]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_6_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(6, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_down(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[0]++;
        test_figur.position[2]++;
        test_figur.position[4]++;
        test_figur.position[6]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_6_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(6, &test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_down(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[0]++;
        test_figur.position[2]++;
        test_figur.position[4]++;
        test_figur.position[6]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_6_3) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(6, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_down(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[0]++;
        test_figur.position[2]++;
        test_figur.position[4]++;
        test_figur.position[6]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_6_4) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(6, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_down(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[0]++;
        test_figur.position[2]++;
        test_figur.position[4]++;
        test_figur.position[6]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_7_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(7, &test_figur);
  // figur_falling_down(&test_figur, &game_spase, &direction);
  // figur_falling_down(&test_figur, &game_spase, &direction);
  // rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_down(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[0]++;
        test_figur.position[2]++;
        test_figur.position[4]++;
        test_figur.position[6]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_7_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(7, &test_figur);
  figur_falling_down(&test_figur, &game_spase, &direction);
  figur_falling_down(&test_figur, &game_spase, &direction);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_down(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        test_figur.position[0]++;
        test_figur.position[2]++;
        test_figur.position[4]++;
        test_figur.position[6]++;
        print_figur_in_game_poly(&game_spase, &test_figur);
      }

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_loop_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][1] = 3;
  }
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][9] = 3;
  }
  for (int i = 1; i < 8; i++) {
    init_figur(i, &test_figur);
    while (test_figur.move_triger == 0 && us_act == Start &&
           us_act != Terminate) {
      if (conditions_of_falling_down(test_figur, game_spase) == true) {
        print_figur_in_game_poly(&game_spase, &test_figur);
        if (traffic_permit_down(&game_spase, &test_figur) == true) {
          kill_figur(&test_figur, &game_spase);
          test_figur.position[0]++;
          test_figur.position[2]++;
          test_figur.position[4]++;
          test_figur.position[6]++;
          print_figur_in_game_poly(&game_spase, &test_figur);
        }

      } else {
        test_figur.move_triger = 1;
      }
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_loop_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][1] = 3;
  }
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][9] = 3;
  }
  for (int i = 1; i < 8; i++) {
    init_figur(i, &test_figur);
    figur_falling_down(&test_figur, &game_spase, &direction);
    figur_falling_down(&test_figur, &game_spase, &direction);
    rotation_figurs(&test_figur);
    while (test_figur.move_triger == 0 && us_act == Start &&
           us_act != Terminate) {
      if (conditions_of_falling_down(test_figur, game_spase) == true) {
        print_figur_in_game_poly(&game_spase, &test_figur);
        if (traffic_permit_down(&game_spase, &test_figur) == true) {
          kill_figur(&test_figur, &game_spase);
          test_figur.position[0]++;
          test_figur.position[2]++;
          test_figur.position[4]++;
          test_figur.position[6]++;
          print_figur_in_game_poly(&game_spase, &test_figur);
        }

      } else {
        test_figur.move_triger = 1;
      }
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_loop_3) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][1] = 3;
  }
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][9] = 3;
  }
  for (int i = 1; i < 8; i++) {
    init_figur(i, &test_figur);
    figur_falling_down(&test_figur, &game_spase, &direction);
    figur_falling_down(&test_figur, &game_spase, &direction);
    rotation_figurs(&test_figur);
    rotation_figurs(&test_figur);
    while (test_figur.move_triger == 0 && us_act == Start &&
           us_act != Terminate) {
      if (conditions_of_falling_down(test_figur, game_spase) == true) {
        print_figur_in_game_poly(&game_spase, &test_figur);
        if (traffic_permit_down(&game_spase, &test_figur) == true) {
          kill_figur(&test_figur, &game_spase);
          test_figur.position[0]++;
          test_figur.position[2]++;
          test_figur.position[4]++;
          test_figur.position[6]++;
          print_figur_in_game_poly(&game_spase, &test_figur);
        }

      } else {
        test_figur.move_triger = 1;
      }
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_loop_4) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][1] = 3;
  }
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][9] = 3;
  }
  for (int i = 1; i < 8; i++) {
    init_figur(i, &test_figur);
    figur_falling_down(&test_figur, &game_spase, &direction);
    figur_falling_down(&test_figur, &game_spase, &direction);
    rotation_figurs(&test_figur);
    rotation_figurs(&test_figur);
    rotation_figurs(&test_figur);
    while (test_figur.move_triger == 0 && us_act == Start &&
           us_act != Terminate) {
      if (conditions_of_falling_down(test_figur, game_spase) == true) {
        print_figur_in_game_poly(&game_spase, &test_figur);
        if (traffic_permit_down(&game_spase, &test_figur) == true) {
          kill_figur(&test_figur, &game_spase);
          test_figur.position[0]++;
          test_figur.position[2]++;
          test_figur.position[4]++;
          test_figur.position[6]++;
          print_figur_in_game_poly(&game_spase, &test_figur);
        }

      } else {
        test_figur.move_triger = 1;
      }
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_loop_5) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][1] = 3;
  }
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][9] = 3;
  }
  for (int i = 1; i < 8; i++) {
    init_figur(3, &test_figur);
    figur_falling_down(&test_figur, &game_spase, &direction);
    figur_falling_down(&test_figur, &game_spase, &direction);
    rotation_figurs(&test_figur);
    rotation_figurs(&test_figur);
    rotation_figurs(&test_figur);
    while (test_figur.move_triger == 0 && us_act == Start &&
           us_act != Terminate) {
      if (conditions_of_falling_down(test_figur, game_spase) == true) {
        print_figur_in_game_poly(&game_spase, &test_figur);
        if (traffic_permit_down(&game_spase, &test_figur) == true) {
          kill_figur(&test_figur, &game_spase);
          test_figur.position[0]++;
          test_figur.position[2]++;
          test_figur.position[4]++;
          test_figur.position[6]++;
          print_figur_in_game_poly(&game_spase, &test_figur);
        }

      } else {
        test_figur.move_triger = 1;
      }
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_loop_6) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][1] = 3;
  }
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][9] = 3;
  }
  for (int i = 1; i < 8; i++) {
    init_figur(2, &test_figur);
    figur_falling_down(&test_figur, &game_spase, &direction);
    figur_falling_down(&test_figur, &game_spase, &direction);
    rotation_figurs(&test_figur);
    rotation_figurs(&test_figur);
    rotation_figurs(&test_figur);
    while (test_figur.move_triger == 0 && us_act == Start &&
           us_act != Terminate) {
      if (conditions_of_falling_down(test_figur, game_spase) == true) {
        print_figur_in_game_poly(&game_spase, &test_figur);
        if (traffic_permit_down(&game_spase, &test_figur) == true) {
          kill_figur(&test_figur, &game_spase);
          test_figur.position[0]++;
          test_figur.position[2]++;
          test_figur.position[4]++;
          test_figur.position[6]++;
          print_figur_in_game_poly(&game_spase, &test_figur);
        }

      } else {
        test_figur.move_triger = 1;
      }
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_loop_7) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][1] = 3;
  }
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][9] = 3;
  }
  for (int i = 1; i < 8; i++) {
    init_figur(1, &test_figur);
    figur_falling_down(&test_figur, &game_spase, &direction);
    figur_falling_down(&test_figur, &game_spase, &direction);
    rotation_figurs(&test_figur);
    rotation_figurs(&test_figur);
    rotation_figurs(&test_figur);
    while (test_figur.move_triger == 0 && us_act == Start &&
           us_act != Terminate) {
      if (conditions_of_falling_down(test_figur, game_spase) == true) {
        print_figur_in_game_poly(&game_spase, &test_figur);
        if (traffic_permit_down(&game_spase, &test_figur) == true) {
          kill_figur(&test_figur, &game_spase);
          test_figur.position[0]++;
          test_figur.position[2]++;
          test_figur.position[4]++;
          test_figur.position[6]++;
          print_figur_in_game_poly(&game_spase, &test_figur);
        }

      } else {
        test_figur.move_triger = 1;
      }
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_loop_8) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][1] = 3;
  }
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][9] = 3;
  }
  for (int i = 1; i < 8; i++) {
    init_figur(5, &test_figur);
    figur_falling_down(&test_figur, &game_spase, &direction);
    figur_falling_down(&test_figur, &game_spase, &direction);
    rotation_figurs(&test_figur);
    rotation_figurs(&test_figur);
    rotation_figurs(&test_figur);
    while (test_figur.move_triger == 0 && us_act == Start &&
           us_act != Terminate) {
      if (conditions_of_falling_down(test_figur, game_spase) == true) {
        print_figur_in_game_poly(&game_spase, &test_figur);
        if (traffic_permit_down(&game_spase, &test_figur) == true) {
          kill_figur(&test_figur, &game_spase);
          test_figur.position[0]++;
          test_figur.position[2]++;
          test_figur.position[4]++;
          test_figur.position[6]++;
          print_figur_in_game_poly(&game_spase, &test_figur);
        }

      } else {
        test_figur.move_triger = 1;
      }
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_down_loop_9) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][1] = 3;
  }
  for (int i = 2; i < 10; i++) {
    game_spase.space[i][9] = 3;
  }
  for (int i = 1; i < 8; i++) {
    init_figur(6, &test_figur);
    figur_falling_down(&test_figur, &game_spase, &direction);
    figur_falling_down(&test_figur, &game_spase, &direction);
    rotation_figurs(&test_figur);
    rotation_figurs(&test_figur);
    rotation_figurs(&test_figur);
    while (test_figur.move_triger == 0 && us_act == Start &&
           us_act != Terminate) {
      if (conditions_of_falling_down(test_figur, game_spase) == true) {
        print_figur_in_game_poly(&game_spase, &test_figur);
        if (traffic_permit_down(&game_spase, &test_figur) == true) {
          kill_figur(&test_figur, &game_spase);
          test_figur.position[0]++;
          test_figur.position[2]++;
          test_figur.position[4]++;
          test_figur.position[6]++;
          print_figur_in_game_poly(&game_spase, &test_figur);
        }

      } else {
        test_figur.move_triger = 1;
      }
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

/////////////////////////////////////////////////////

START_TEST(test_tetris_traffic_permit_flip_1_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(1, &test_figur);
  figur_falling_down(&test_figur, &game_spase, &direction);
  figur_falling_down(&test_figur, &game_spase, &direction);
  figur_falling_down(&test_figur, &game_spase, &direction);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_flip(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        rotation_figurs(&test_figur);
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_flip_1_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(1, &test_figur);
  figur_falling_down(&test_figur, &game_spase, &direction);
  figur_falling_down(&test_figur, &game_spase, &direction);
  figur_falling_down(&test_figur, &game_spase, &direction);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_flip(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        rotation_figurs(&test_figur);
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_flip_2_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(2, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_flip(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        rotation_figurs(&test_figur);
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_flip_2_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(2, &test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_flip(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        rotation_figurs(&test_figur);
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_flip_2_3) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(2, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_flip(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        rotation_figurs(&test_figur);
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_flip_2_4) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(2, &test_figur);
  figur_falling_down(&test_figur, &game_spase, &direction);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_flip(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        rotation_figurs(&test_figur);
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_flip_3_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(3, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_flip(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        rotation_figurs(&test_figur);
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_flip_3_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(3, &test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_flip(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        rotation_figurs(&test_figur);
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_flip_3_3) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(3, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_flip(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        rotation_figurs(&test_figur);
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_flip_3_4) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(3, &test_figur);
  figur_falling_down(&test_figur, &game_spase, &direction);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_flip(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        rotation_figurs(&test_figur);
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_flip_4) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(4, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_flip(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        rotation_figurs(&test_figur);
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_flip_5_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(5, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_flip(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        rotation_figurs(&test_figur);
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_flip_5_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(5, &test_figur);
  figur_falling_down(&test_figur, &game_spase, &direction);
  figur_falling_down(&test_figur, &game_spase, &direction);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_flip(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        rotation_figurs(&test_figur);
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_flip_6_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(6, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_flip(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        rotation_figurs(&test_figur);
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_flip_6_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(6, &test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_flip(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        rotation_figurs(&test_figur);
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_flip_6_3) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(6, &test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_flip(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        rotation_figurs(&test_figur);
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_flip_6_4) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(6, &test_figur);
  figur_falling_down(&test_figur, &game_spase, &direction);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_flip(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        rotation_figurs(&test_figur);
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_flip_7_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(7, &test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_flip(&game_spase, &test_figur) == true) {
        kill_figur(&test_figur, &game_spase);
        rotation_figurs(&test_figur);
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_traffic_permit_flip_7_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(7, &test_figur);
  figur_falling_down(&test_figur, &game_spase, &direction);
  figur_falling_down(&test_figur, &game_spase, &direction);
  rotation_figurs(&test_figur);
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      if (traffic_permit_flip(&game_spase, &test_figur) == true) {
        rotation_figurs(&test_figur);
        print_figur_in_game_poly(&game_spase, &test_figur);
      }
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_conditions_of_falling_down_1) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(1, &test_figur);
  game_spase.space[19][3] = 3;
  game_spase.space[19][4] = 3;
  game_spase.space[19][5] = 3;
  game_spase.space[19][6] = 3;
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_conditions_of_falling_down_2) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  init_figur(1, &test_figur);
  game_spase.space[19][3] = 3;
  game_spase.space[19][4] = 3;
  game_spase.space[19][5] = 3;
  game_spase.space[19][6] = 3;
  while (test_figur.move_triger == 0 && us_act == Start &&
         us_act != Terminate) {
    if (conditions_of_falling_down(test_figur, game_spase) == true) {
      print_figur_in_game_poly(&game_spase, &test_figur);
      figur_falling_down(&test_figur, &game_spase, &direction);

    } else {
      test_figur.move_triger = 1;
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_conditions_of_falling_down_3) {
  WINDOW* window = newwin(24, 27, 0, 0);
  UserAction_t us_act = Start;
  Figur test_figur = {0};
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  VectorDirection direction = Dormant;
  game_info.next_figur = 2;
  init_game_info(&game_info);
  init_space_game(&game_spase);
  print_next_figur(&game_info);
  // init_figur(1, &test_figur);
  game_spase.space[19][3] = 3;
  game_spase.space[19][4] = 3;
  game_spase.space[19][5] = 3;
  game_spase.space[19][6] = 3;
  for (int i = 1; i < 8; i++) {
    init_figur(i, &test_figur);
    while (test_figur.move_triger == 0 && us_act == Start &&
           us_act != Terminate) {
      if (conditions_of_falling_down(test_figur, game_spase) == true) {
        print_figur_in_game_poly(&game_spase, &test_figur);
        figur_falling_down(&test_figur, &game_spase, &direction);

      } else {
        test_figur.move_triger = 1;
      }
    }
  }
  game_remove(&game_spase, &game_info);
  delwin(window);
  // endwin();
}
END_TEST

START_TEST(test_tetris_level_and_speed_1) {
  GameInfo_t game_info = {0};
  game_info.score = 10000;
  game_level_and_speed(&game_info);
}
END_TEST

START_TEST(test_tetris_level_and_speed_2) {
  GameInfo_t game_info = {0};
  game_info.score = 2000;
  game_level_and_speed(&game_info);
}
END_TEST

START_TEST(test_tetris_level_and_speed_3) {
  GameInfo_t game_info = {0};
  game_info.score = 0;
  game_level_and_speed(&game_info);
}
END_TEST

START_TEST(test_tetris_level_and_speed_4) {
  GameInfo_t game_info = {0};
  game_info.score = 354663;
  game_level_and_speed(&game_info);
}
END_TEST

START_TEST(kill_line_tests_1) {
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  for (int i = 0; i < 10; i++) {
    game_spase.space[19][i] = 3;
  }
  find_full_line(&game_spase, &game_info);
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(kill_line_tests_2) {
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  for (int i = 0; i < 10; i++) {
    game_spase.space[19][i] = 3;
  }
  for (int i = 0; i < 10; i++) {
    game_spase.space[18][i] = 3;
  }
  find_full_line(&game_spase, &game_info);
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(kill_line_tests_3) {
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  for (int i = 0; i < 10; i++) {
    game_spase.space[19][i] = 3;
  }
  for (int i = 0; i < 10; i++) {
    game_spase.space[18][i] = 3;
  }
  for (int i = 0; i < 10; i++) {
    game_spase.space[17][i] = 3;
  }
  find_full_line(&game_spase, &game_info);
  game_remove(&game_spase, &game_info);
}
END_TEST

START_TEST(kill_line_tests_4) {
  Game_space game_spase = {0};
  GameInfo_t game_info = {0};
  init_game_info(&game_info);
  init_space_game(&game_spase);
  for (int i = 0; i < 10; i++) {
    game_spase.space[19][i] = 3;
  }
  for (int i = 0; i < 10; i++) {
    game_spase.space[18][i] = 3;
  }
  for (int i = 0; i < 10; i++) {
    game_spase.space[17][i] = 3;
  }
  for (int i = 0; i < 10; i++) {
    game_spase.space[16][i] = 3;
  }
  find_full_line(&game_spase, &game_info);
  game_remove(&game_spase, &game_info);
}
END_TEST

Suite* make_test_backend_suite() {
  Suite* backend_suite = suite_create("backend");
  TCase* tc_core;

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_backend_1);
  tcase_add_test(tc_core, test_backend_2);
  tcase_add_test(tc_core, test_backend_3);
  tcase_add_test(tc_core, test_backend_4);
  tcase_add_test(tc_core, test_backend_5);
  tcase_add_test(tc_core, test_backend_6);
  tcase_add_test(tc_core, test_backend_7);
  tcase_add_test(tc_core, test_backend_1_1);
  tcase_add_test(tc_core, test_backend_2_1);
  tcase_add_test(tc_core, test_backend_3_1);
  tcase_add_test(tc_core, test_backend_4_1);
  tcase_add_test(tc_core, test_backend_5_1);
  tcase_add_test(tc_core, test_backend_6_1);
  tcase_add_test(tc_core, test_backend_7_1);
  tcase_add_test(tc_core, test_backend_kill_figur);
  tcase_add_test(tc_core, test_backend_find_full_line_1);
  tcase_add_test(tc_core, test_backend_find_full_line_2);
  tcase_add_test(tc_core, test_backend_find_full_line_3);
  tcase_add_test(tc_core, test_backend_find_full_line_4);
  tcase_add_test(tc_core, test_check_on_game_over_1);
  tcase_add_test(tc_core, test_check_on_game_over_2);
  tcase_add_test(tc_core, test_backend_rotation_1);
  tcase_add_test(tc_core, test_backend_rotation_2);
  tcase_add_test(tc_core, test_backend_rotation_3);
  tcase_add_test(tc_core, test_backend_rotation_4);
  tcase_add_test(tc_core, test_backend_rotation_5);
  tcase_add_test(tc_core, test_backend_rotation_6);
  tcase_add_test(tc_core, test_tetris_1_1);
  tcase_add_test(tc_core, test_tetris_1_2);
  tcase_add_test(tc_core, test_tetris_2_1);
  tcase_add_test(tc_core, test_tetris_2_2);
  tcase_add_test(tc_core, test_tetris_2_3);
  tcase_add_test(tc_core, test_tetris_2_4);
  tcase_add_test(tc_core, test_tetris_3_1);
  tcase_add_test(tc_core, test_tetris_3_2);
  tcase_add_test(tc_core, test_tetris_3_3);
  tcase_add_test(tc_core, test_tetris_3_4);
  tcase_add_test(tc_core, test_tetris_4);
  tcase_add_test(tc_core, test_tetris_5_1);
  tcase_add_test(tc_core, test_tetris_5_2);
  tcase_add_test(tc_core, test_tetris_6_1);
  tcase_add_test(tc_core, test_tetris_6_2);
  tcase_add_test(tc_core, test_tetris_6_3);
  tcase_add_test(tc_core, test_tetris_6_4);
  tcase_add_test(tc_core, test_tetris_7_1);
  tcase_add_test(tc_core, test_tetris_7_2);

  tcase_add_test(tc_core, test_tetris_traffic_permit_left_1_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_left_1_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_left_2_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_left_2_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_left_2_3);
  tcase_add_test(tc_core, test_tetris_traffic_permit_left_2_4);
  tcase_add_test(tc_core, test_tetris_traffic_permit_left_3_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_left_3_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_left_3_3);
  tcase_add_test(tc_core, test_tetris_traffic_permit_left_3_4);
  tcase_add_test(tc_core, test_tetris_traffic_permit_left_4);
  tcase_add_test(tc_core, test_tetris_traffic_permit_left_5_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_left_5_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_left_6_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_left_6_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_left_6_3);
  tcase_add_test(tc_core, test_tetris_traffic_permit_left_6_4);
  tcase_add_test(tc_core, test_tetris_traffic_permit_left_7_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_left_7_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_left_loop_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_left_loop_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_left_loop_3);
  tcase_add_test(tc_core, test_tetris_traffic_permit_left_loop_4);

  tcase_add_test(tc_core, test_tetris_traffic_permit_right_1_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_right_1_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_right_2_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_right_2_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_right_2_3);
  tcase_add_test(tc_core, test_tetris_traffic_permit_right_2_4);
  tcase_add_test(tc_core, test_tetris_traffic_permit_right_3_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_right_3_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_right_3_3);
  tcase_add_test(tc_core, test_tetris_traffic_permit_right_3_4);
  tcase_add_test(tc_core, test_tetris_traffic_permit_right_4);
  tcase_add_test(tc_core, test_tetris_traffic_permit_right_5_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_right_5_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_right_6_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_right_6_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_right_6_3);
  tcase_add_test(tc_core, test_tetris_traffic_permit_right_6_4);
  tcase_add_test(tc_core, test_tetris_traffic_permit_right_7_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_right_7_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_right_loop_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_right_loop_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_right_loop_3);
  tcase_add_test(tc_core, test_tetris_traffic_permit_right_loop_4);

  tcase_add_test(tc_core, test_tetris_traffic_permit_down_1_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_1_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_2_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_2_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_2_3);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_2_4);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_3_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_3_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_3_3);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_3_4);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_4);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_5_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_5_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_6_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_6_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_6_3);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_6_4);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_7_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_7_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_loop_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_loop_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_loop_3);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_loop_4);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_loop_5);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_loop_6);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_loop_7);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_loop_8);
  tcase_add_test(tc_core, test_tetris_traffic_permit_down_loop_9);

  tcase_add_test(tc_core, test_tetris_traffic_permit_flip_1_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_flip_1_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_flip_2_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_flip_2_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_flip_2_3);
  tcase_add_test(tc_core, test_tetris_traffic_permit_flip_2_4);
  tcase_add_test(tc_core, test_tetris_traffic_permit_flip_3_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_flip_3_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_flip_3_3);
  tcase_add_test(tc_core, test_tetris_traffic_permit_flip_3_4);
  tcase_add_test(tc_core, test_tetris_traffic_permit_flip_4);
  tcase_add_test(tc_core, test_tetris_traffic_permit_flip_5_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_flip_5_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_flip_6_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_flip_6_2);
  tcase_add_test(tc_core, test_tetris_traffic_permit_flip_6_3);
  tcase_add_test(tc_core, test_tetris_traffic_permit_flip_6_4);
  tcase_add_test(tc_core, test_tetris_traffic_permit_flip_7_1);
  tcase_add_test(tc_core, test_tetris_traffic_permit_flip_7_2);
  tcase_add_test(tc_core, test_conditions_of_falling_down_1);
  tcase_add_test(tc_core, test_conditions_of_falling_down_2);
  tcase_add_test(tc_core, test_conditions_of_falling_down_3);
  tcase_add_test(tc_core, test_tetris_level_and_speed_1);
  tcase_add_test(tc_core, test_tetris_level_and_speed_2);
  tcase_add_test(tc_core, test_tetris_level_and_speed_3);
  tcase_add_test(tc_core, test_tetris_level_and_speed_4);
  tcase_add_test(tc_core, kill_line_tests_1);
  tcase_add_test(tc_core, kill_line_tests_2);
  tcase_add_test(tc_core, kill_line_tests_3);
  tcase_add_test(tc_core, kill_line_tests_4);

  suite_add_tcase(backend_suite, tc_core);
  return backend_suite;
}
