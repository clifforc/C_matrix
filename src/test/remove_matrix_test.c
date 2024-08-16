#include "matrix_test_suite.h"

START_TEST(remove_matrix_test1) {
  matrix_t matrix;
  s21_create_matrix(5, 5, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert(matrix.matrix == NULL);
  s21_remove_matrix(NULL);
}
END_TEST

Suite *remove_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Test s21_remove_matrix(matrix_t *A)");

  tc_core = tcase_create("Remove matrix");

  tcase_add_test(tc_core, remove_matrix_test1);
  suite_add_tcase(s, tc_core);

  return s;
}