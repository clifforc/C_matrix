#include "./../s21_matrix.h"

// Minor of matrix and matrix of algebraic complements
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (A == NULL) return INCORRECT_MATRIX;
  if (A->rows != A->columns || is_inf_or_nan(A) == 1) return CALCULATION_ERROR;

  s21_create_matrix(A->rows, A->columns, result);

  matrix_t temp;
  s21_create_matrix(A->rows - 1, A->columns - 1, &temp);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      get_minor_matrix(A, &temp, i, j);
      double minor_det = 0.0;
      s21_determinant(&temp, &minor_det);
      result->matrix[i][j] = pow(-1, i + j) * minor_det;
    }
  }
  s21_remove_matrix(&temp);
  return OK;
}
