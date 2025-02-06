// #include <unistd.h>

// #include "../../gui/cli/Tetris/front_end.h"
// #include "back_end.h"

// int main() {
//   Game_space game_space = {0};
//   GameInfo_t game_info = {0};
//   UserAction_t user_actions = Start;
//   init_space_game(&game_space);
//   init_game_info(&game_info);
//   game_info.next_figur = get_random_number();
//   game_info.speed = START_SPEED;
//   game_info.level = START_LEVEL;
//   int ch;
//   bool end = true;
//   WINDOW* window = init_ncurses();
//   WINDOW* Info_Window = newwin(22, 27, 0, 27);
//   game_info.high_score = readNumberFromFile();
//   while (end == true && (user_actions == Start || user_actions == Restart)) {
//     if (user_actions == Restart) {
//       clean_space_game(&game_space);
//       clean_game_info(&game_info, Info_Window);
//       render_game_info(&game_info, user_actions, window);
//     }
//     while ((ch = wgetch(window)) != 'q' && user_actions != Terminate &&
//            user_actions != Game_over) {
//       Figur figur;
//       get_figur(&figur, game_info);
//       game_info.next_figur = get_random_number();
//       clean_game_info(&game_info, Info_Window);
//       user_actions =
//           game_loop(window, Info_Window, &game_space, &game_info,
//           &user_actions, &figur);
//       find_full_line(&game_space, &game_info);
//       game_level_and_speed(&game_info);
//       if (check_on_game_over(game_space) == false) {
//         user_actions = Game_over;
//       }
//     }
//     restart_game(&user_actions, &game_info, window);
//   }
//   if (game_info.score > game_info.high_score) {
//     writeNumberToFile(game_info.score);
//   }
//   if (user_actions == Game_over) {
//     printf("\t\t\t\t\tGAME OVER");
//   }
//   game_remove(&game_space, &game_info);
//   delwin(window);
//   delwin(stdscr);
//   endwin();
//   return 0;
// }
