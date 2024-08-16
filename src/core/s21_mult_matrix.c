#include "./../s21_matrix.h"

// Multiplication of two matrices
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL) return INCORRECT_MATRIX;
  if (A->columns != B->rows || is_inf_or_nan(A) || is_inf_or_nan(B))
    return CALCULATION_ERROR;

  s21_create_matrix(A->rows, B->columns, result);

  int sum = 0;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      for (int k = 0; k < B->rows; k++) {
        sum += A->matrix[i][k] * B->matrix[k][j];
      }
      result->matrix[i][j] = sum;
      sum = 0;
    }
  }
  return OK;
}