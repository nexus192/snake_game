#include "run_tests.h"

#include <stdio.h>

int main() {
  int total_number_run = 0;
  int total_number_failed = 0;

  Suite* suites[] = {make_test_backend_suite(), NULL};

  for (Suite** current_suite = suites; *current_suite != NULL;
       current_suite++) {
    run_suite(*current_suite, &total_number_run, &total_number_failed);
  }

  printf("Total tests run:\t%d\nTotal tests failed:\t%d\n", total_number_run,
         total_number_failed);
  return (total_number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

void run_suite(Suite* current_suite, int* total_number_run,
               int* total_number_failed) {
  SRunner* suite_runner;

  suite_runner = srunner_create(current_suite);
  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);
  *total_number_run += srunner_ntests_run(suite_runner);
  *total_number_failed += srunner_ntests_failed(suite_runner);

  srunner_free(suite_runner);
}
