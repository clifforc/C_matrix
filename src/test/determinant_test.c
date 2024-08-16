#include "matrix_test_suite.h"

START_TEST(determinant_test1) {
  double det;
  ck_assert(s21_determinant(NULL, &det) == INCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_test2) {
  matrix_t A;
  double det;
  int rows = 2, columns = 3;

  s21_create_matrix(rows, columns, &A);
  ck_assert(s21_determinant(&A, &det) == CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test3) {
  matrix_t A;
  double val_a = 2.0;
  double det;
  int rows = 3, columns = 3;

  s21_create_matrix(rows, columns, &A);
  assigning_values_to_matrix(&A, val_a);

  A.matrix[1][1] = INFINITY;

  ck_assert(s21_determinant(&A, &det) == CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test4) {
  matrix_t A;
  double val_a = 2.0;
  double det;
  int rows = 3, columns = 3;

  s21_create_matrix(rows, columns, &A);
  assigning_values_to_matrix(&A, val_a);

  A.matrix[1][1] = NAN;

  ck_assert(s21_determinant(&A, &det) == CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test5) {
  matrix_t A;
  double det = 0.0;
  double expected_det = -1.0;
  int rows = 3, columns = 3;

  double matrix_values[3][3] = {
      {2.0, 5.0, 7.0}, {6.0, 3.0, 4.0}, {5.0, -2.0, -3.0}};

  s21_create_matrix(rows, columns, &A);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = matrix_values[i][j];
    }
  }

  s21_determinant(&A, &det);
  ck_assert(det == expected_det);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test6) {
  matrix_t A;
  double det = 0.0;
  double expected_det = -24.0;
  int rows = 2, columns = 2;

  double matrix_values[2][2] = {{2.0, 5.0}, {6.0, 3.0}};

  s21_create_matrix(rows, columns, &A);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = matrix_values[i][j];
    }
  }

  s21_determinant(&A, &det);
  ck_assert(det == expected_det);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test7) {
  matrix_t A;
  double det = 0.0;
  double expected_det = 2.0;
  int rows = 1, columns = 1;

  s21_create_matrix(rows, columns, &A);

  A.matrix[0][0] = 2.0;

  s21_determinant(&A, &det);
  ck_assert(det == expected_det);

  s21_remove_matrix(&A);
}
END_TEST

Suite *determinant_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Test s21_determinant(matrix_t *A, double *result)");

  tc_core = tcase_create("determinant");

  tcase_add_test(tc_core, determinant_test1);
  tcase_add_test(tc_core, determinant_test2);
  tcase_add_test(tc_core, determinant_test3);
  tcase_add_test(tc_core, determinant_test4);
  tcase_add_test(tc_core, determinant_test5);
  tcase_add_test(tc_core, determinant_test6);
  tcase_add_test(tc_core, determinant_test7);
  suite_add_tcase(s, tc_core);

  return s;
}