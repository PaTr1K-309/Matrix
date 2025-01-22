#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!s21_check(A)) {
    return ERROR_MATRIX;
  }
  if (A->rows != A->columns) {
    return ERROR_CALCULATE;
  }

  matrix_t B = {0};
  s21_create_matrix(A->rows - 1, A->columns - 1, &B);

  int result_create = s21_create_matrix(A->rows, A->columns, result);

  if (result_create == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        s21_cofactor_matrix(A, &B, i, j);
        double determinant = 0;
        s21_determinant(&B, &determinant);
        result->matrix[i][j] = pow(-1, i + j) * determinant;
      }
    }
  }
  s21_remove_matrix(&B);
  return result_create;
}