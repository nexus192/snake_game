#ifndef SRC_RUN_TESTS_H_
#define SRC_RUN_TESTS_H_

#include <check.h>
#include <ncurses.h>
#include <stdlib.h>

#include "../../src/BrickGame/tetris/tetris_backend.h"
#include "../../src/gui/cli/controller_cli/controller_tetris_cli.h"
#include "../../src/gui/cli/front.h"

void run_suite(Suite* current_suite, int* total_number_run,
               int* total_number_failed);

Suite* make_test_backend_suite();

#endif  // SRC_RUN_TESTS_H_
