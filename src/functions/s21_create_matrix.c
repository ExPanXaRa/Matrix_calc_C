#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0 || !result) return INCORRECT_MATRIX_ERROR;

  int status = NO_ERROR;

  result->rows = rows;
  result->columns = columns;
  result->matrix = calloc(rows, sizeof(double *));

  if (result->matrix) {
    for (int i = 0; i < rows && status == NO_ERROR; i++) {
      result->matrix[i] = calloc(columns, sizeof(double));
      if (!result->matrix[i]) status = INCORRECT_MATRIX_ERROR;
    }
  } else {
    status = INCORRECT_MATRIX_ERROR;
  }

  return status;
}