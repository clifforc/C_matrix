#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

#define PRECISION 0.0000001
#define ROUND_VAL 10000000.0

#define OK 0
#define INCORRECT_MATRIX 1  // 1 - Ошибка, некорректная матрица
#define CALCULATION_ERROR 2  // 2 - Ошибка вычисления

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// Main functions

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// Additional functions

int is_zero_or_negative(int rows, int columns);
int are_equal(double a, double b);
int equal_size(const matrix_t *A, const matrix_t *B);
int is_inf_or_nan(const matrix_t *A);
void get_minor_matrix(matrix_t *A, matrix_t *minor, int skip_row, int skip_col);
void assigning_values_to_matrix(matrix_t *A, double num);

#endif