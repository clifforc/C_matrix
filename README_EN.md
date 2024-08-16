# s21_matrix

## Description

s21_matrix is an implementation of a library for working with matrices in C. The project was developed as part of an educational program aimed at deepening the understanding of matrix operations, memory management, and C programming.

The library is developed in C language standard C11 using the gcc compiler.</br>
The library is designed as a static library named `s21_matrix.a`.</br>
The project is fully covered with unit tests using the Check library.

## Implemented Functions

1. **create_matrix** - Creating a matrix;
2. **remove_matrix** - Clearing and destroying a matrix;
3. **eq_matrix** - Comparing matrices;
4. **sum_matrix** - Adding matrices;
5. **sub_matrix** - Subtracting matrices;
6. **mult_matrix** - Multiplying matrices;
7. **mult_number** - Multiplying a matrix by a number;
8. **transpose** - Transposing a matrix;
9. **determinant** - Calculating the determinant of a matrix;
10. **calc_complements** - Calculating the matrix of algebraic complements;
11. **inverse_matrix** - Finding the inverse matrix.

## Building and Usage

The Makefile is used to build the library and run tests with the following targets:

- `make all`: build the entire project;
- `make clean`: clean build files;
- `make test`: run unit tests;
- `make s21_matrix.a`: build the static library;
- `make gcov_report`: generate a test coverage report in HTML format.

## License

This project is part of the educational program at [School21](https://21-school.ru/) - an educational project by Sber for developers