#include "matrix_test_suite.h"

START_TEST(mult_number_test1) {
  matrix_t result;
  double num = 2.0;
  ck_assert(s21_mult_number(NULL, num, &result) == INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_number_test2) {
  matrix_t A;
  matrix_t result;

  int rows = 3, columns = 3;
  double val_a = 2.0;
  double num = 2.0;

  s21_create_matrix(rows, columns, &A);

  assigning_values_to_matrix(&A, val_a);

  A.matrix[1][1] = INFINITY;

  ck_assert(s21_mult_number(&A, num, &result) == CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_number_test3) {
  matrix_t A;
  matrix_t result;

  int rows = 3, columns = 3;
  double val_a = 2.0;
  double num = 2.0;

  s21_create_matrix(rows, columns, &A);

  assigning_values_to_matrix(&A, val_a);

  A.matrix[1][1] = NAN;

  ck_assert(s21_mult_number(&A, num, &result) == CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_number_test4) {
  matrix_t A;
  matrix_t result;

  int rows = 3, columns = 3;
  double val_a = 2.0;
  double num = INFINITY;

  s21_create_matrix(rows, columns, &A);

  assigning_values_to_matrix(&A, val_a);

  ck_assert(s21_mult_number(&A, num, &result) == CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_number_test5) {
  matrix_t A;
  matrix_t result;

  int rows = 3, columns = 3;
  double val_a = 2.0;
  double num = NAN;

  s21_create_matrix(rows, columns, &A);

  assigning_values_to_matrix(&A, val_a);

  ck_assert(s21_mult_number(&A, num, &result) == CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_number_test6) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int rows = 3, columns = 3;
  double val_a = 2.0;
  double val_b = 4.0;
  double num = 2.0;

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  assigning_values_to_matrix(&A, val_a);
  assigning_values_to_matrix(&B, val_b);

  ck_assert(s21_mult_number(&A, num, &result) == OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert(B.matrix[i][j] == result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

Suite *mult_number_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create(
      "Test s21_mult_number(matrix_t *A, double number, matrix_t *result)");

  tc_core = tcase_create("mult number");

  tcase_add_test(tc_core, mult_number_test1);
  tcase_add_test(tc_core, mult_number_test2);
  tcase_add_test(tc_core, mult_number_test3);
  tcase_add_test(tc_core, mult_number_test4);
  tcase_add_test(tc_core, mult_number_test5);
  tcase_add_test(tc_core, mult_number_test6);
  suite_add_tcase(s, tc_core);

  return s;
}