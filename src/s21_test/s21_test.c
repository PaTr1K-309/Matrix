#include "s21_test.h"

int main() {
  int number_tests = 0;
  int number_failed = 0;
  Suite *s21matrix[] = {test(), NULL};

  for (int i = 0; s21matrix[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21matrix[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    number_tests += srunner_ntests_run(sr);
    number_failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("===> TOTAL TESTS: %3d <===\n", number_tests);
  printf("===> TOTAL FAILED: %2d <===\n", number_failed);

  return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;

  return 0;
}