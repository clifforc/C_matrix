#include "matrix_test_suite.h"

START_TEST(transpose_matrix_test1) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int rows = 3, columns = 3;
  s21_create_matrix(rows - 1, columns, &A);
  s21_create_matrix(rows, columns - 1, &B);

  double counter_a = 1.0;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = counter_a++;
    }
  }

  double counter_b = 1.0;
  for (int j = 0; j < B.columns; j++) {
    for (int i = 0; i < B.rows; i++) {
      B.matrix[i][j] = counter_b++;
    }
  }

  s21_transpose(&A, &result);

  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      ck_assert(result.matrix[i][j] == B.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_matrix_test2) {
  matrix_t result;
  ck_assert(s21_transpose(NULL, &result) == INCORRECT_MATRIX);
}
END_TEST

Suite *transpose_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Test s21_transpose_matrix(matrix_t *A, matrix_t *result)");

  tc_core = tcase_create("transpose matrix");

  tcase_add_test(tc_core, transpose_matrix_test1);
  tcase_add_test(tc_core, transpose_matrix_test2);
  suite_add_tcase(s, tc_core);

  return s;
}