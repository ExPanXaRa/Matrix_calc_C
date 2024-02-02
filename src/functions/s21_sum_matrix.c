#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_matrix_check(A) || !s21_matrix_check(B) || !result)
    return INCORRECT_MATRIX_ERROR;
  if (!s21_rc_check(A, B) || !s21_inf_nan_check(A) || !s21_inf_nan_check(B))
    return CALCULATION_ERROR;

  int status = NO_ERROR;

  if (s21_create_matrix(A->rows, A->columns, result) != 0) {
    status = INCORRECT_MATRIX_ERROR;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }

  return status;
}
