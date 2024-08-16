#include "./../s21_matrix.h"

// Matrix multiplication by scalar
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (A == NULL) return INCORRECT_MATRIX;
  if (is_inf_or_nan(A) || isinf(number) || isnan(number))
    return CALCULATION_ERROR;

  s21_create_matrix(A->rows, A->columns, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      double mult = A->matrix[i][j] * number;
      result->matrix[i][j] = mult;
    }
  }
  return OK;
}
