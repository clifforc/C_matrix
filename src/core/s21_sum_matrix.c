#include "./../s21_matrix.h"

// Adding matrices
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL) return INCORRECT_MATRIX;
  if (!equal_size(A, B) || is_inf_or_nan(A) || is_inf_or_nan(B))
    return CALCULATION_ERROR;

  s21_create_matrix(A->rows, A->columns, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
  return OK;
}
