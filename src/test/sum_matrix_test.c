#include "matrix_test_suite.h"

START_TEST(sum_matrix_test1) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t D;
  int rows = 3, columns = 3;
  double val_a = 2;
  double val_b = 3;
  double val_d = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &D);

  assigning_values_to_matrix(&A, val_a);
  assigning_values_to_matrix(&B, val_b);
  assigning_values_to_matrix(&D, val_d);

  s21_sum_matrix(&A, &B, &result);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert(result.matrix[i][j] == D.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(sum_matrix_test2) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int rows = 3, columns = 3;
  s21_create_matrix(4, columns, &A);
  s21_create_matrix(rows, columns, &B);
  ck_assert(s21_sum_matrix(&A, &B, &result) == CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_test3) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, 4, &A);
  s21_create_matrix(rows, columns, &B);
  ck_assert(s21_sum_matrix(&A, &B, &result) == CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_test4) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[1][1] = INFINITY;
  ck_assert(s21_sum_matrix(&A, &B, &result) == CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_test5) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  B.matrix[1][1] = INFINITY;
  ck_assert(s21_sum_matrix(&A, &B, &result) == CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_test6) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[1][1] = NAN;
  ck_assert(s21_sum_matrix(&A, &B, &result) == CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_test7) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  B.matrix[1][1] = NAN;
  ck_assert(s21_sum_matrix(&A, &B, &result) == CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_test8) {
  matrix_t A;
  matrix_t result;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  ck_assert(s21_sum_matrix(&A, NULL, &result) == INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(sum_matrix_test9) {
  matrix_t B;
  matrix_t result;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &B);
  ck_assert(s21_sum_matrix(NULL, &B, &result) == INCORRECT_MATRIX);
  s21_remove_matrix(&B);
}
END_TEST

Suite *sum_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create(
      "Test s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result)");

  tc_core = tcase_create("sum matrix");

  tcase_add_test(tc_core, sum_matrix_test1);
  tcase_add_test(tc_core, sum_matrix_test2);
  tcase_add_test(tc_core, sum_matrix_test3);
  tcase_add_test(tc_core, sum_matrix_test4);
  tcase_add_test(tc_core, sum_matrix_test5);
  tcase_add_test(tc_core, sum_matrix_test6);
  tcase_add_test(tc_core, sum_matrix_test7);
  tcase_add_test(tc_core, sum_matrix_test8);
  tcase_add_test(tc_core, sum_matrix_test9);
  suite_add_tcase(s, tc_core);

  return s;
}