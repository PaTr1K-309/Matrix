#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

#define OK 0
#define ERROR_MATRIX 1
#define ERROR_CALCULATE 2

#define EPS 1e-7

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

//ОСНОВНЫЕ ФУНКЦИИ S21_MATRIX
/*##############################################################*/
int s21_create_matrix(int rows, int columns,
                      matrix_t *result);      //создание матрицы
void s21_remove_matrix(matrix_t *A);          // очищение матрицы
int s21_eq_matrix(matrix_t *A, matrix_t *B);  //сравнение матриц
int s21_sum_matrix(matrix_t *A, matrix_t *B,
                   matrix_t *result);  //сложение матриц
int s21_sub_matrix(matrix_t *A, matrix_t *B,
                   matrix_t *result);  //вычитание матриц
int s21_mult_number(matrix_t *A, double number,
                    matrix_t *result);  //умножение матрицы на число
int s21_mult_matrix(matrix_t *A, matrix_t *B,
                    matrix_t *result);  //умножение матрицы на матрицу
int s21_transpose(matrix_t *A, matrix_t *result);  //перестановка
int s21_determinant(matrix_t *A, double *result);  //нахождение определителя
int s21_calc_complements(
    matrix_t *A,
    matrix_t *result);  //Минор матрицы и матрица алгебраических дополнений
int s21_inverse_matrix(matrix_t *A, matrix_t *result);  //Обратная матрица
/*##############################################################*/

// ДОП ФУНКЦИИ S21_HELP_FUNCTIONS.C
/*##############################################################*/
void s21_completion_matrix(matrix_t *A, double number);  //заполнение матрицы
int s21_check(matrix_t *A);  //проверка матрицы
void s21_cofactor_matrix(matrix_t *A, matrix_t *B, int row_size,
                         int col_size);  //кофактор
double s21_calc_determinant(matrix_t *A, int n);
/*##############################################################*/

#endif