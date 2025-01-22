#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0) {
    return ERROR_MATRIX;
  }
  result->rows = 0;
  result->columns = 0;
  result->matrix = NULL;

  double **matrix =
      malloc(rows * columns * sizeof(double) + rows * sizeof(double *));
  double *temp = (double *)(matrix + rows);

  for (int i = 0; i < rows; i++) {
    matrix[i] = temp + columns * i;
  }

  result->rows = rows;
  result->columns = columns;
  result->matrix = matrix;

  s21_completion_matrix(result, 0);

  return OK;
}
