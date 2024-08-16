#include "./../s21_matrix.h"

// Matrix determinant
int s21_determinant(matrix_t *A, double *result) {
  if (A == NULL) return INCORRECT_MATRIX;
  if (A->rows != A->columns || is_inf_or_nan(A) == 1) return CALCULATION_ERROR;

  int flag = -1;

  if (A->rows == 1) {
    *result = A->matrix[0][0];
    flag = OK;
  } else if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    flag = OK;
  } else {
    *result = 0;
    for (int k = 0; k < A->rows; k++) {
      matrix_t minor;
      s21_create_matrix(A->rows - 1, A->columns - 1, &minor);

      get_minor_matrix(A, &minor, 0, k);

      double minor_det = 0.0;
      s21_determinant(&minor, &minor_det);
      *result += pow(-1, k) * A->matrix[0][k] * minor_det;

      s21_remove_matrix(&minor);
    }
    flag = OK;
  }
  return flag;
}