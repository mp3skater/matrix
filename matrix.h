#ifndef __MATRIX_H__
#define __MATRIX_H__

/*
 * Type for the value of the matrix, can so easily be changed
 * Parameter:
 * 1: double val
 */
typedef
  struct val_s
  {
    double val;
  }  val_t;

/*
 * Type matrix is a 2d array with the methods:
 * madd(Addition between matrixes), msub(Subtraction b.m.), mskal(Skalarproduct), mprod(Multiplication b.m.);
 * Parameter:
 * 1: count of []... (y)
 * 2. count of [...] (x) (limit is 20)
 * 3: value variable
 */
typedef
  struct matrix_s
  {
    int i;
    int j;
    val_t *m[];
  } matrix_t;

/*
 * Fills a matrix with random values from 0 to <n>
 * Parameter:
 * 1: maximal size of matrix-values
 */
int fill_random_matrix(int, matrix_t);

/*
 * Return value:
 * 0: Operation successful
 * 1: Size uncompatible
 *
 * Parameter: 
 * m1: First matrix
 * m2: Second matrix or skal-value
 * ans_p: Pointer to the answer-matrix
 */
int madd(matrix_t, matrix_t, matrix_t*);
int msub(matrix_t, matrix_t, matrix_t*);
int mskal(matrix_t, double, matrix_t*);
int mprod(matrix_t, matrix_t, matrix_t*);

#endif
