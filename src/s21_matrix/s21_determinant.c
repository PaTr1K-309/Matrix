#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (!s21_check(A) || !result) {
    return ERROR_MATRIX;
  }
  if (A->rows != A->columns) {
    return ERROR_CALCULATE;
  }
  *result = s21_calc_determinant(A, A->rows);

  return OK;
}