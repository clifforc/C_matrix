#include "matrix_test_suite.h"

START_TEST(create_matrix_test1) {
  matrix_t matrix;
  ck_assert(s21_create_matrix(-1, -1, &matrix) == INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_matrix_test2) {
  matrix_t matrix;
  ck_assert(s21_create_matrix(5, 0, &matrix) == INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_matrix_test3) {
  ck_assert(s21_create_matrix(5, 5, NULL) == INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_matrix_test4) {
  matrix_t matrix;
  ck_assert(s21_create_matrix(5, 5, &matrix) == OK);
  s21_remove_matrix(&matrix);
}
END_TEST

Suite *create_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create(
      "Test s21_create_matrix(int row, int column, matrix_t *result)");

  tc_core = tcase_create("Create matrix");

  tcase_add_test(tc_core, create_matrix_test1);
  tcase_add_test(tc_core, create_matrix_test2);
  tcase_add_test(tc_core, create_matrix_test3);
  tcase_add_test(tc_core, create_matrix_test4);
  suite_add_tcase(s, tc_core);

  return s;
}