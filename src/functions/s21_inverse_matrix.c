#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!s21_matrix_check(A) || !result) return INCORRECT_MATRIX_ERROR;
  if (A->columns != A->rows) return CALCULATION_ERROR;

  int status = NO_ERROR;
  double check = 0.0;
  status = s21_determinant(A, &check);
  if (check != 0) {
    if (A->columns == 1) {
      if (s21_create_matrix(A->rows, A->columns, result) == 0) {
        if (A->matrix[0][0]) {
          result->matrix[0][0] = 1.0 / A->matrix[0][0];
        } else {
          status = CALCULATION_ERROR;
        }
      } else {
        status = INCORRECT_MATRIX_ERROR;
      }
    } else {
      matrix_t temp = {0};
      status = s21_calc_complements(A, &temp);
      if (!status) {
        matrix_t trans = {0};
        status = s21_transpose(&temp, &trans);
        if (!status) {
          s21_mult_number(&trans, 1.0 / check, result);
        }
        s21_remove_matrix(&trans);
      }
      s21_remove_matrix(&temp);
    }
  } else {
    status = CALCULATION_ERROR;
  }

  return status;
}