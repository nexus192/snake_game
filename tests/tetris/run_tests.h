#ifndef SRC_RUN_TESTS_H_
#define SRC_RUN_TESTS_H_

#include <check.h>
#include <ncurses.h>
#include <stdlib.h>

#include "../../src/BrickGame/tetris/back_end.h"
#include "../../src/controller/controller_tetris.h"
#include "../../src/gui/cli/front_end.h"

void run_suite(Suite* current_suite, int* total_number_run,
               int* total_number_failed);

Suite* make_test_backend_suite();

#endif  // SRC_RUN_TESTS_H_
