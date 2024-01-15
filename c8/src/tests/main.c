#include "main.h"

int failed_tests = 0;

int main() {
  Suite *list_cases[] = {create_parser_testcase(), create_move_testcase(),
                         create_rotate_testcase(), create_scale_testcase(),
                         NULL};

  for (Suite **testcase = list_cases; *testcase != NULL; testcase++) {
    run_testcase(*testcase);
  }

  if (failed_tests) {
    fprintf(stderr, "FAIL TEST: %d\n", failed_tests);
  }

  return 0;
}

void run_testcase(Suite *testcase) {
  static int counter_testcase = 1;

  if (counter_testcase > 1) putchar('\n');

  printf("CURRENT TEST: %d\n", counter_testcase);
  counter_testcase++;

  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  failed_tests += srunner_ntests_failed(sr);

  srunner_free(sr);
}
