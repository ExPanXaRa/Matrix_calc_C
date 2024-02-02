#include "test_matrix.h"

START_TEST(test_transpose_matrix_loop) {
  matrix_t A = {0};
  matrix_t otvet = {0};
  matrix_t res = {0};

  s21_create_matrix(_i, _i, &A);
  s21_create_matrix(_i, _i, &otvet);

  for (int i = 0; i < _i; i++) {
    for (int j = 0; j < _i; j++) {
      A.matrix[i][j] = (double)_i + 5.05;
    }
  }

  for (int i = 0; i < _i; i++) {
    for (int j = 0; j < _i; j++) {
      otvet.matrix[i][j] = A.matrix[j][i];
    }
  }

  int err = s21_transpose(&A, &res);
  ck_assert_int_eq(err, NO_ERROR);
  ck_assert_int_eq(s21_eq_matrix(&otvet, &res), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&otvet);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_transpose_matrix_error_null_ptr) {
  matrix_t otvet = {0};
  matrix_t res = {0};

  s21_create_matrix(5, 7, &otvet);

  int err = s21_transpose(NULL, &res);
  ck_assert_int_eq(err, INCORRECT_MATRIX_ERROR);
  ck_assert_int_eq(s21_eq_matrix(&otvet, &res), FAILURE);
  s21_remove_matrix(&otvet);
  s21_remove_matrix(&res);
}
END_TEST

Suite *s21_test_transpose_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("test_s21_transpose");
  tc_core = tcase_create("Core");

  suite_add_tcase(s, tc_core);

  tcase_add_loop_test(tc_core, test_transpose_matrix_loop, 1, 100);
  tcase_add_test(tc_core, test_transpose_matrix_error_null_ptr);

  return s;
}