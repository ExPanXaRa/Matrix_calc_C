#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_matrix_check(A) || !s21_matrix_check(B) || !result)
    return INCORRECT_MATRIX_ERROR;
  if (!s21_rcplus_check(A, B) || !s21_inf_nan_check(A) || !s21_inf_nan_check(B))
    return CALCULATION_ERROR;

  int status = NO_ERROR;

  if (s21_create_matrix(A->rows, B->columns, result) != 0) {
    status = INCORRECT_MATRIX_ERROR;
  } else {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = 0;
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }

  return status;
}