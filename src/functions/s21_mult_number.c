#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (!s21_matrix_check(A) || !result) return INCORRECT_MATRIX_ERROR;
  if (!s21_inf_nan_check(A) || isinf(number) || isnan(number))
    return CALCULATION_ERROR;

  int status = NO_ERROR;

  if (s21_create_matrix(A->rows, A->columns, result) != 0) {
    status = INCORRECT_MATRIX_ERROR;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }

  return status;
}
