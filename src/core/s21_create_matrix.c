#include "./../s21_matrix.h"

// Creating matrices
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (is_zero_or_negative(rows, columns) || result == NULL)
    return INCORRECT_MATRIX;

  result->matrix = (double **)calloc(rows, sizeof(double *));

  for (int i = 0; i < rows; i++) {
    result->matrix[i] = (double *)calloc(columns, sizeof(double));
  }
  result->rows = rows;
  result->columns = columns;
  return OK;
}