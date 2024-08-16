#include "matrix_test_suite.h"

START_TEST(mult_matrix_test1) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t D;

  int rows_a = 2, columns_a = 3;
  int rows_b = 3, columns_b = 2;
  int rows_d = rows_a, columns_d = columns_b;

  double val_a = 2.0;
  double val_b = 2.0;
  double val_d = 12.0;

  s21_create_matrix(rows_a, columns_a, &A);
  s21_create_matrix(rows_b, columns_b, &B);
  s21_create_matrix(rows_d, columns_d, &D);

  assigning_values_to_matrix(&A, val_a);
  assigning_values_to_matrix(&B, val_b);
  assigning_values_to_matrix(&D, val_d);

  s21_mult_matrix(&A, &B, &result);

  for (int i = 0; i < rows_d; i++) {
    for (int j = 0; j < columns_d; j++) {
      ck_assert(result.matrix[i][j] == D.matrix[i][i]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(mult_matrix_test2) {
  matrix_t B;
  matrix_t result;

  int rows_b = 3, columns_b = 2;

  s21_create_matrix(rows_b, columns_b, &B);

  ck_assert(s21_mult_matrix(NULL, &B, &result) == INCORRECT_MATRIX);

  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_test3) {
  matrix_t A;
  matrix_t result;

  int rows_a = 3, columns_a = 2;

  s21_create_matrix(rows_a, columns_a, &A);

  ck_assert(s21_mult_matrix(&A, NULL, &result) == INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_matrix_test4) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int rows_a = 2, columns_a = 2;
  int rows_b = 3, columns_b = 2;

  s21_create_matrix(rows_a, columns_a, &A);
  s21_create_matrix(rows_b, columns_b, &B);

  ck_assert(s21_mult_matrix(&A, &B, &result) == CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_test5) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int rows_a = 2, columns_a = 3;
  int rows_b = 3, columns_b = 2;

  double val_a = 2.0;
  double val_b = 2.0;

  s21_create_matrix(rows_a, columns_a, &A);
  s21_create_matrix(rows_b, columns_b, &B);

  assigning_values_to_matrix(&A, val_a);
  assigning_values_to_matrix(&B, val_b);

  A.matrix[1][1] = INFINITY;

  ck_assert(s21_mult_matrix(&A, &B, &result) == CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_test6) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int rows_a = 2, columns_a = 3;
  int rows_b = 3, columns_b = 2;

  double val_a = 2.0;
  double val_b = 2.0;

  s21_create_matrix(rows_a, columns_a, &A);
  s21_create_matrix(rows_b, columns_b, &B);

  assigning_values_to_matrix(&A, val_a);
  assigning_values_to_matrix(&B, val_b);

  A.matrix[1][1] = NAN;

  ck_assert(s21_mult_matrix(&A, &B, &result) == CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_test7) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int rows_a = 2, columns_a = 3;
  int rows_b = 3, columns_b = 2;

  double val_a = 2.0;
  double val_b = 2.0;

  s21_create_matrix(rows_a, columns_a, &A);
  s21_create_matrix(rows_b, columns_b, &B);

  assigning_values_to_matrix(&A, val_a);
  assigning_values_to_matrix(&B, val_b);

  B.matrix[1][1] = INFINITY;

  ck_assert(s21_mult_matrix(&A, &B, &result) == CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_test8) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int rows_a = 2, columns_a = 3;
  int rows_b = 3, columns_b = 2;

  double val_a = 2.0;
  double val_b = 2.0;

  s21_create_matrix(rows_a, columns_a, &A);
  s21_create_matrix(rows_b, columns_b, &B);

  assigning_values_to_matrix(&A, val_a);
  assigning_values_to_matrix(&B, val_b);

  B.matrix[1][1] = NAN;

  ck_assert(s21_mult_matrix(&A, &B, &result) == CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *mult_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create(
      "Test s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result)");

  tc_core = tcase_create("mult matrix");

  tcase_add_test(tc_core, mult_matrix_test1);
  tcase_add_test(tc_core, mult_matrix_test2);
  tcase_add_test(tc_core, mult_matrix_test3);
  tcase_add_test(tc_core, mult_matrix_test4);
  tcase_add_test(tc_core, mult_matrix_test5);
  tcase_add_test(tc_core, mult_matrix_test6);
  tcase_add_test(tc_core, mult_matrix_test7);
  tcase_add_test(tc_core, mult_matrix_test8);
  suite_add_tcase(s, tc_core);

  return s;
}