#include "../s21_matrix.h"

int s21_matrix_check(matrix_t *A) {
  if (!A || A->rows <= 0 || A->columns <= 0) return FAILURE;
  return SUCCESS;
}

int s21_rc_check(matrix_t *A, matrix_t *B) {
  if (A->rows != B->rows || A->columns != B->columns) return FAILURE;
  return SUCCESS;
}

/* Матрицу P можно умножить на матрицу K только в том случае,
если число столбцов матрицы P равняется числу строк матрицы K */
int s21_rcplus_check(matrix_t *A, matrix_t *B) {
  if (A->columns != B->rows) return FAILURE;
  return SUCCESS;
}

int s21_inf_nan_check(matrix_t *A) {
  int status = SUCCESS;

  for (int i = 0; i < A->rows && status == SUCCESS; i++) {
    for (int j = 0; j < A->columns && status == SUCCESS; j++) {
      if (isinf(A->matrix[i][j]) || isnan(A->matrix[i][j])) status = FAILURE;
    }
  }

  return status;
}