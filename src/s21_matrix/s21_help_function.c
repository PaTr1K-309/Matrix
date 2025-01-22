#include "../s21_matrix.h"

void s21_completion_matrix(matrix_t *A, double number) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = number;
    }
  }
}

int s21_check(matrix_t *A) {
  if (A == NULL || A->rows <= 0 || A->columns <= 0 || !A->matrix)
    return 0;
  else
    return 1;
}

void s21_cofactor_matrix(matrix_t *A, matrix_t *B, int row_size, int col_size) {
  int i = 0, j = 0;
  for (int row = 0; row < A->rows; row++)
    for (int col = 0; col < A->columns; col++)
      if (row != row_size && col != col_size) {
        B->matrix[i][j] = A->matrix[row][col];
        j++;
        if (j == A->rows - 1) {
          j = 0;
          i++;
        }
      }
}

double s21_calc_determinant(matrix_t *A, int n) {
  double determinant = 0;

  if (n == 1) return A->matrix[0][0];

  matrix_t B = {0};
  s21_create_matrix(A->rows, A->columns, &B);

  int sign = 1;

  for (int f = 0; f < n; f++) {
    s21_cofactor_matrix(A, &B, 0, f);
    determinant += sign * A->matrix[0][f] * s21_calc_determinant(&B, n - 1);
    sign = -sign;
  }

  s21_remove_matrix(&B);

  return determinant;
}