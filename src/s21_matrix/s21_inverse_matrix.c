#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!s21_check(A)) {
    return ERROR_MATRIX;
  }
  if (A->rows != A->columns) {
    return ERROR_CALCULATE;
  }
  double determinant = 0;
  int determinant_ret = 0;
  determinant_ret = s21_determinant(A, &determinant);
  if (!determinant || determinant_ret == ERROR_CALCULATE) {
    return ERROR_CALCULATE;
  }
  int result_create = s21_create_matrix(A->rows, A->columns, result);

  if (result_create == OK) {
    if (A->rows != 1) {
      matrix_t B = {0};
      matrix_t C = {0};
      matrix_t D = {0};

      s21_calc_complements(A, &B);
      s21_transpose(&B, &C);
      s21_mult_number(&C, 1.0 / determinant, &D);

      for (int i = 0; i < D.rows; i++) {
        for (int j = 0; j < D.columns; j++) {
          result->matrix[i][j] = D.matrix[i][j];
        }
      }
      s21_remove_matrix(&B);
      s21_remove_matrix(&C);
      s21_remove_matrix(&D);
    } else {
      result->matrix[0][0] = 1.0 / A->matrix[0][0];
    }
  }
  return result_create;
}