#include "./../s21_matrix.h"

// Inverse of the matrix
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (A == NULL) return INCORRECT_MATRIX;
  if (A->rows != A->columns || is_inf_or_nan(A) == 1) return CALCULATION_ERROR;
  int flag = OK;
  double det = 0.0;
  s21_determinant(A, &det);
  if (det == 0) flag = CALCULATION_ERROR;

  if (flag == OK) {
    matrix_t minor;
    matrix_t transponsed;

    s21_create_matrix(A->rows, A->columns, result);

    s21_calc_complements(A, &minor);
    s21_transpose(&minor, &transponsed);

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = transponsed.matrix[i][j] / det;
      }
    }
    s21_remove_matrix(&minor);
    s21_remove_matrix(&transponsed);
  }
  return flag;
}