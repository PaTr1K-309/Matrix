#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_check(A) || !s21_check(B)) {
    return ERROR_MATRIX;
  }
  if (A->columns != B->rows) {
    return ERROR_CALCULATE;
  }

  int result_create = s21_create_matrix(A->rows, B->columns, result);
  if (result_create == OK)
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < B->columns; j++)
        for (int l = 0; l < B->rows; l++)
          result->matrix[i][j] += A->matrix[i][l] * B->matrix[l][j];

  return result_create;
}