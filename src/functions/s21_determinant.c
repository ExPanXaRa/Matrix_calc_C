#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (!s21_matrix_check(A)) return INCORRECT_MATRIX_ERROR;
  if (A->columns != A->rows) return CALCULATION_ERROR;

  int status = NO_ERROR;

  if (A->columns == 1) {
    *result = A->matrix[0][0];
  } else if (A->columns == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    *result = s21_det_recursion(A);
  }

  return status;
}

double s21_det_recursion(matrix_t *A) {
  if (A->columns == 2) {
    return A->matrix[0][0] * A->matrix[1][1] -
           A->matrix[0][1] * A->matrix[1][0];
  }

  double result = 0.0;
  for (int i = 0; i < A->rows; i++) {
    matrix_t temp = {0};
    s21_create_matrix(A->rows - 1, A->columns - 1, &temp);
    for (int j = 0; j < A->columns; j++) {
      s21_smaller_matrix_completion(&temp, A, i, j);
      result += (pow(-1.0, i)) * A->matrix[i][0] * (s21_det_recursion(&temp));
    }
    s21_remove_matrix(&temp);
  }

  return result;
}

void s21_smaller_matrix_completion(matrix_t *temp, matrix_t *A, int i, int j) {
  for (int k = 0; k < A->rows; k++) {
    for (int g = 0; g < A->columns; g++) {
      if (i != k && j != g) {
        if (k < i && g < j) {
          temp->matrix[k][g] = A->matrix[k][g];
        } else if (k < i && g > j) {
          temp->matrix[k][g - 1] = A->matrix[k][g];
        } else if (k > i && g < j) {
          temp->matrix[k - 1][g] = A->matrix[k][g];
        } else {
          temp->matrix[k - 1][g - 1] = A->matrix[k][g];
        }
      }
    }
  }
}
