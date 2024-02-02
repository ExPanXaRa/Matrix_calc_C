#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!s21_matrix_check(A) || !result) return INCORRECT_MATRIX_ERROR;
  if (A->columns != A->rows) return CALCULATION_ERROR;

  int status = NO_ERROR;
  if (s21_create_matrix(A->rows, A->columns, result) != 0) {
    status = INCORRECT_MATRIX_ERROR;
  } else {
    if (A->columns == 1) {
      result->matrix[0][0] = 1;
    } else {
      s21_calc_complements_plus(A, result, &status);
    }
  }
  return status;
}

void s21_calc_complements_plus(matrix_t *A, matrix_t *result, int *status) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (A->columns == 2) {
        result->matrix[i][j] =
            pow(-1.0, i + j) * A->matrix[(i + 1 + A->rows) % A->rows]
                                        [(j + 1 + A->columns) % A->columns];
      } else {
        matrix_t temp = {0};
        *status = s21_create_matrix(A->rows - 1, A->columns - 1, &temp);
        if (*status == NO_ERROR) {
          s21_smaller_matrix_completion(&temp, A, i, j);
          double aal = 0.0;
          *status = s21_determinant(&temp, &aal);
          result->matrix[i][j] = pow(-1.0, i + j) * aal;
          s21_remove_matrix(&temp);
        }
      }
    }
  }
}