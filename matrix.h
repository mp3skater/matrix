#ifndef __MATRIX_H__
#define __MATRIX_H__

/*
 * Type for the value of the matrix, can so easily be changed
 * 
 * Members:
 * val: value (double)
 */
typedef
  struct val_s
  {
    double val;
  }  val_t;

/*
 * Type matrix is a 2d array of val_t values in every spot.
 * 
 * Members:
 * i: count of rows (y)
 * j: count of columns (x) (limit is 20)
 * *val_t[]: grid
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
 * 2: pointer to the matrix that gets filled
 */
int fill_random_matrix(int, matrix_t);

/*
 * Return value:
 * 0:  Operation successful
 * -1: Size uncompatible
 *
 * Parameter: 
 * m1: First matrix
 * m2: Second matrix or skal-value
 * ans_p: Pointer to the answer-matrix
 */
// Adds two matrixes together if they are the same size, else the answer-matrix will be NULL.
int madd(matrix_t, matrix_t, matrix_t*);

// Subtracts two matrixes, if they are not of the same size the answer-matrix will be NULL.
int msub(matrix_t, matrix_t, matrix_t*);

// Multiplies all members of the matrix by the given value of the second parameter.
int mskal(matrix_t, double, matrix_t*);

// Multiply two matrixes, if they are not of the same size the answer-matrix will be NULL.
int mprod(matrix_t, matrix_t, matrix_t*);

#endif
