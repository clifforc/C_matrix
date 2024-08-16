#include "matrix_test_suite.h"

START_TEST(calc_complements_test1) {
  matrix_t result;
  ck_assert(s21_calc_complements(NULL, &result) == INCORRECT_MATRIX);
}
END_TEST

START_TEST(calc_complements_test2) {
  matrix_t A;
  matrix_t result;

  int rows = 2, columns = 3;

  s21_create_matrix(rows, columns, &A);

  ck_assert(s21_calc_complements(&A, &result) == CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_test3) {
  matrix_t A;
  matrix_t result;
  double val_a = 2.0;
  int rows = 3, columns = 3;

  s21_create_matrix(rows, columns, &A);
  assigning_values_to_matrix(&A, val_a);
  A.matrix[1][1] = INFINITY;
  ck_assert(s21_calc_complements(&A, &result) == CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_test4) {
  matrix_t A;
  matrix_t result;
  double val_a = 2.0;
  int rows = 3, columns = 3;

  s21_create_matrix(rows, columns, &A);
  assigning_values_to_matrix(&A, val_a);
  A.matrix[1][1] = NAN;
  ck_assert(s21_calc_complements(&A, &result) == CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_test5) {
  matrix_t A;
  matrix_t result;
  matrix_t B;

  int rows = 3, columns = 3;

  double matrix_A_values[3][3] = {
      {1.0, 2.0, 3.0}, {0.0, 4.0, 2.0}, {5.0, 2.0, 1.0}};

  double matrix_B_values[3][3] = {
      {0.0, 10.0, -20.0}, {4.0, -14.0, 8.0}, {-8.0, -2.0, 4.0}};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = matrix_A_values[i][j];
      B.matrix[i][j] = matrix_B_values[i][j];
    }
  }

  s21_calc_complements(&A, &result);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert(B.matrix[i][j] == result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&B);
}
END_TEST

Suite *calc_complements_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Test s21_calc_complements(matrix_t *A, matrix_t *result)");

  tc_core = tcase_create("calc complements");

  tcase_add_test(tc_core, calc_complements_test1);
  tcase_add_test(tc_core, calc_complements_test2);
  tcase_add_test(tc_core, calc_complements_test3);
  tcase_add_test(tc_core, calc_complements_test4);
  tcase_add_test(tc_core, calc_complements_test5);
  suite_add_tcase(s, tc_core);

  return s;
}