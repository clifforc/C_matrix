#ifndef MATRIX_TEST_SUITE_H
#define MATRIX_TEST_SUITE_H

#include <check.h>

#include "./../s21_matrix.h"

Suite *create_matrix_suite(void);
Suite *remove_matrix_suite(void);
Suite *eq_matrix_suite(void);
Suite *sum_matrix_suite(void);
Suite *sub_matrix_suite(void);
Suite *mult_number_suite(void);
Suite *mult_matrix_suite(void);
Suite *transpose_matrix_suite(void);
Suite *calc_complements_suite(void);
Suite *determinant_suite(void);
Suite *inverse_matrix_suite(void);

#endif