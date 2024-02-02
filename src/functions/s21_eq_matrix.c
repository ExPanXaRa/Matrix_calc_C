#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (!s21_matrix_check(A) || !s21_matrix_check(B)) return FAILURE;

  int status = SUCCESS;

  if (A->rows == B->rows && A->columns == B->columns) {
    for (int i = 0; i < A->rows && status == SUCCESS; i++) {
      for (int j = 0; j < A->columns && status == SUCCESS; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPSILON) status = FAILURE;
      }
    }
  } else
    status = FAILURE;

  return status;
}