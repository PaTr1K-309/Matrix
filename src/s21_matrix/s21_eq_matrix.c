#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (!s21_check(A) || !s21_check(B)) {
    return FAILURE;
  }
  if ((A->rows != B->rows) || (A->columns != B->columns)) {
    return FAILURE;
  }
  int res = SUCCESS;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPS) {
        res = FAILURE;
      }
    }
  }
  return res;
}