#include "matrix_test_suite.h"

START_TEST(eq_matrix_test1) {
  matrix_t A;
  matrix_t B;
  int rows = 5, columns = 5;
  double val_a = 10.123456799;
  double val_b = 10.123456788;

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  assigning_values_to_matrix(&A, val_a);
  assigning_values_to_matrix(&B, val_b);

  ck_assert(s21_eq_matrix(&A, &B) == SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test2) {
  matrix_t A;
  matrix_t B;
  int rows = 5, columns = 5;
  double val_a = 10.1234567;
  double val_b = 10.1234568;

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  assigning_values_to_matrix(&A, val_a);
  assigning_values_to_matrix(&B, val_b);

  ck_assert(s21_eq_matrix(&A, &B) == FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test3) {
  matrix_t A;
  matrix_t B;
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, 4, &B);
  ck_assert(s21_eq_matrix(&A, &B) == FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test4) {
  matrix_t A;
  matrix_t B;
  int rows = 5, columns = 5;
  s21_create_matrix(4, columns, &A);
  s21_create_matrix(rows, columns, &B);
  ck_assert(s21_eq_matrix(&A, &B) == FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test5) {
  matrix_t A;
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &A);
  ck_assert(s21_eq_matrix(&A, NULL) == FAILURE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(eq_matrix_test6) {
  matrix_t B;
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &B);
  ck_assert(s21_eq_matrix(NULL, &B) == FAILURE);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test7) {
  matrix_t B;
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &B);
  ck_assert(s21_eq_matrix(NULL, &B) == FAILURE);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test8) {
  matrix_t A;
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &A);
  ck_assert(s21_eq_matrix(&A, NULL) == FAILURE);
  s21_remove_matrix(&A);
}
END_TEST

Suite *eq_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Test s21_eq_matrix(matrix_t *A, matrix_t *B)");

  tc_core = tcase_create("Eq matrix");

  tcase_add_test(tc_core, eq_matrix_test1);
  tcase_add_test(tc_core, eq_matrix_test2);
  tcase_add_test(tc_core, eq_matrix_test3);
  tcase_add_test(tc_core, eq_matrix_test4);
  tcase_add_test(tc_core, eq_matrix_test5);
  tcase_add_test(tc_core, eq_matrix_test6);
  tcase_add_test(tc_core, eq_matrix_test7);
  tcase_add_test(tc_core, eq_matrix_test8);
  suite_add_tcase(s, tc_core);

  return s;
}