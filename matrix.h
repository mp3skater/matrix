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
 * Allocates the storage (initializes) and returns a new matrix with the size of i * j.
 *
 * Parameter:
 * 1: pointer to the matrix that will be created
 * 2: count of rows (y)
 * 3: count of columns (x)
 *
 * Return:
 * 0: Creation successful
 * 1: Error happens
 */
int create_matrix(matrix_t*, int, int);

/*
 * Fills a matrix with random values from 0 to <n>
 *
 * Parameter:
 * 1: maximal size of matrix-values
 * 2: pointer to the matrix that gets filled
 *
 * Return:
 * 0: Operation successful
 */
int fill_random_matrix(int, matrix_t);

/*
 * Group of operation-methods:
 *
 * Parameter: 
 * 1: first matrix
 * 2: second matrix or skal-value
 * 3: pointer to the answer-matrix
 *
 * Return:
 * 0:  Operation successful
 * -1: Size uncompatible
 */
// Adds two matrixes together if they are the same size, else the answer-matrix will be NULL.
int madd(matrix_t, matrix_t, matrix_t*);

// Subtracts two matrixes, if they are not of the same size the answer-matrix will be NULL.
int msub(matrix_t, matrix_t, matrix_t*);

// Multiplies all members of the matrix by the given value of the second parameter.
int mskal(matrix_t, val_t, matrix_t*);

// Multiply two matrixes, if they are not of the same size the answer-matrix will be NULL.
int mprod(matrix_t, matrix_t, matrix_t*);

#endif
