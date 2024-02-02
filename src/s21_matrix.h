#ifndef S21_MATRIX
#define S21_MATRIX

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define NO_ERROR 0
#define INCORRECT_MATRIX_ERROR 1
#define CALCULATION_ERROR 2
#define SUCCESS 1
#define FAILURE 0

#define EPSILON 1e-7

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_matrix_check(matrix_t *A);
int s21_rc_check(matrix_t *A, matrix_t *B);
int s21_rcplus_check(matrix_t *A, matrix_t *B);
int s21_inf_nan_check(matrix_t *A);
void s21_print_matrix(matrix_t *A);

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
double s21_det_recursion(matrix_t *A);
void s21_smaller_matrix_completion(matrix_t *temp, matrix_t *A, int i, int j);
int s21_calc_complements(matrix_t *A, matrix_t *result);
void s21_calc_complements_plus(matrix_t *A, matrix_t *result, int *status);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif