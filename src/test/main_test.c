#include "./../s21_matrix.h"
#include "matrix_test_suite.h"

int run_test_suite(Suite *(*suite_func)(), int *number_failed) {
  Suite *s = suite_func();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  *number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return *number_failed;
}

int main(int argc, char **argv) {
  int number_failed = 0;
  if (argc > 1) {
    if (strcmp(argv[1], "create_matrix") == 0) {
      printf("\nCREATE MATRIX TESTS\n");
      run_test_suite(create_matrix_suite, &number_failed);
    } else if (strcmp(argv[1], "remove_matrix") == 0) {
      printf("\nREMOVE MATRIX TESTS\n");
      run_test_suite(remove_matrix_suite, &number_failed);
    } else if (strcmp(argv[1], "eq_matrix") == 0) {
      printf("\nEQ MATRIX TESTS\n");
      run_test_suite(eq_matrix_suite, &number_failed);
    } else if (strcmp(argv[1], "sum_matrix") == 0) {
      printf("\nSUM MATRIX TESTS\n");
      run_test_suite(sum_matrix_suite, &number_failed);
    } else if (strcmp(argv[1], "sub_matrix") == 0) {
      printf("\nSUB MATRIX TESTS\n");
      run_test_suite(sub_matrix_suite, &number_failed);
    } else if (strcmp(argv[1], "mult_number") == 0) {
      printf("\nMULT NUMBER TESTS\n");
      run_test_suite(mult_number_suite, &number_failed);
    } else if (strcmp(argv[1], "mult_matrix") == 0) {
      printf("\nMULT MATRIX TESTS\n");
      run_test_suite(mult_matrix_suite, &number_failed);
    } else if (strcmp(argv[1], "transpose") == 0) {
      printf("\nTRANSPOSE MATRIX TESTS\n");
      run_test_suite(transpose_matrix_suite, &number_failed);
    } else if (strcmp(argv[1], "calc_complements") == 0) {
      printf("\nCALC COMPLEMENTS TESTS\n");
      run_test_suite(calc_complements_suite, &number_failed);
    } else if (strcmp(argv[1], "determinant") == 0) {
      printf("\nDETERMINANT TESTS\n");
      run_test_suite(determinant_suite, &number_failed);
    } else if (strcmp(argv[1], "inverse") == 0) {
      printf("\nINVERSE MATRIX TESTS\n");
      run_test_suite(inverse_matrix_suite, &number_failed);
    }
  } else {
    printf("\nCREATE MATRIX TESTS\n");
    run_test_suite(create_matrix_suite, &number_failed);
    printf("\nREMOVE MATRIX TESTS\n");
    run_test_suite(remove_matrix_suite, &number_failed);
    printf("\nEQ MATRIX TESTS\n");
    run_test_suite(eq_matrix_suite, &number_failed);
    printf("\nSUM MATRIX TESTS\n");
    run_test_suite(sum_matrix_suite, &number_failed);
    printf("\nSUB MATRIX TESTS\n");
    run_test_suite(sub_matrix_suite, &number_failed);
    printf("\nMULT NUMBER TESTS\n");
    run_test_suite(mult_number_suite, &number_failed);
    printf("\nMULT MATRIX TESTS\n");
    run_test_suite(mult_matrix_suite, &number_failed);
    printf("\nTRANSPOSE MATRIX TESTS\n");
    run_test_suite(transpose_matrix_suite, &number_failed);
    printf("\nCALC COMPLEMENTS TESTS\n");
    run_test_suite(calc_complements_suite, &number_failed);
    printf("\nDETERMINANT TESTS\n");
    run_test_suite(determinant_suite, &number_failed);
    printf("\nINVERSE MATRIX TESTS\n");
    run_test_suite(inverse_matrix_suite, &number_failed);
  }
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}