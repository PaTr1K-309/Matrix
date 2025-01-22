#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_check(A) || !s21_check(B)) {
    return ERROR_MATRIX;
  }
  if ((A->rows != B->rows) || (A->columns != B->columns)) {
    return ERROR_CALCULATE;
  }
  int result_create = s21_create_matrix(A->rows, A->columns, result);
  if (result_create == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return result_create;
}