#include "./../s21_matrix.h"

// Matrix comparison
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (A == NULL || B == NULL || !equal_size(A, B)) return FAILURE;
  int flag = SUCCESS;
  for (int i = 0; i < A->rows && flag; i++) {
    for (int j = 0; j < B->columns && flag; j++) {
      double a = (int)(A->matrix[i][j] * ROUND_VAL) / ROUND_VAL;
      double b = (int)(B->matrix[i][j] * ROUND_VAL) / ROUND_VAL;
      flag = are_equal(a, b);
    }
  }
  return flag;
}
