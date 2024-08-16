#include "./../s21_matrix.h"

// Chech (rows <= 0 || columns <= 0)
int is_zero_or_negative(int rows, int columns) {
  return rows <= 0 || columns <= 0;
}

// Check (a == b) with 0.0000001 precision
int are_equal(double a, double b) {
  double c = (int)(fabs(a - b) * ROUND_VAL + 0.5) / ROUND_VAL;
  return c < PRECISION;
}

// Check (A->rows == B->rows && A->columns == B->columns)
int equal_size(const matrix_t *A, const matrix_t *B) {
  return A->rows == B->rows && A->columns == B->columns;
}

// Check matrix elements isinf or nan
int is_inf_or_nan(const matrix_t *A) {
  int flag = 0;
  for (int i = 0; i < A->rows && flag == 0; i++) {
    for (int j = 0; j < A->columns && flag == 0; j++) {
      if (isinf(A->matrix[i][j]) || isnan(A->matrix[i][j])) {
        flag = 1;
      }
    }
  }
  return flag;
}

// Create additional minor matrix with skipped rows
void get_minor_matrix(matrix_t *A, matrix_t *minor, int skip_row,
                      int skip_col) {
  int minor_row = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == skip_row) continue;
    int minor_col = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == skip_col) continue;
      minor->matrix[minor_row][minor_col] = A->matrix[i][j];
      minor_col++;
    }
    minor_row++;
  }
}

// Assigning values to matrix elements
void assigning_values_to_matrix(matrix_t *A, double num) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = num;
    }
  }
}
