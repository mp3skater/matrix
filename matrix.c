/*
 * Module: matrix.c
 * Author: mp3skater
 * License: MIT License
 */

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "matrix.h"

int create_matrix(matrix_t* mat, int row, int col)
{
  // Allocate memory for a new matrix
  mat = malloc(sizeof(matrix_t) + sizeof(val_t *) * row);

  if(mat == NULL) {
    // Handle allocation failure
    return 1;
  }

  mat->i = row;
  mat->j = col;
  
  // Allocate memory for the flexible array member
  for (int i = 0; i < row; i++) {
    mat->m[i] = malloc(sizeof(val_t) * col);
    if(mat->m[i] == NULL) {
      // Handle allocation failure
      // Free previously allocated memory
      for (int j = 0; j < i; j++) {
        free(mat->m[j]);
      }
      free(mat);
      return 1;
    }
  }

  return 0;
}

int fill_random_matrix(int n, matrix_t m)
{
  srand(time(NULL));
  // Random variable
  val_t random;
  
  // All elements of the matrix filled and printed
  for(int i = 0; i<m.i; i++) {
    for(int j = 0; j<m.j; j++) {
      random.val = rand()%(n+1);
      m.m[i][j] = random;
      printf("%lf ", random.val);
    }
    printf("\n");
  }

  return 0;
}

int madd(matrix_t m1, matrix_t m2, matrix_t* ans_p)
{
  // Assert both matrixes have the same size
  if(m1.i != m2.i || m1.j != m2.j) {
    printf("The matrixes %p and %p don't have the same size, Addition not possible", &m1, &m2);
    return -1;
  }

  // Compute the operation for all elements of the matrixes to the answer-matrix
  for(int i = 0; i<m1.i; i++) {
    for(int j = 0; j<m1.j; j++) {
      (*ans_p).m[i][j].val = m1.m[i][j].val + m2.m[i][j].val;
    }
  }

  return 0;
}

int msub(matrix_t m1, matrix_t m2, matrix_t* ans_p)
{
  // Assert both matrixes have the same size
  if(m1.i != m2.i || m1.j != m2.j) {
    printf("The matrixes %p and %p don't have the same size, Subtraction not possible", &m1, &m2);
    return -1;
  }

  // Compute the operation for all elements of the matrixes to the answer-matrix
  for(int i = 0; i<m1.i; i++) {
    for(int j = 0; j<m1.j; j++) {
      (*ans_p).m[i][j].val = m1.m[i][j].val - m2.m[i][j].val;
    }
  }

  return 0;
}


int mskal(matrix_t m1, val_t skal, matrix_t* ans_p)
{
  // Compute the operation for all elements of the matrixes to the answer-matrix
  for(int i = 0; i<m1.i; i++) {
    for(int j = 0; j<m1.j; j++) {
      (*ans_p).m[i][j].val = m1.m[i][j].val * skal.val;
    }
  }

  return 0;
}


int mprod(matrix_t m1, matrix_t m2, matrix_t* ans_p)
{
  // Assert both matrixes have the same size
  if(m1.i != m2.i || m1.j != m2.j) {
    printf("The matrixes %p and %p don't have the same size, Multiplication not possible", &m1, &m2);
    return -1;
  }

  // Compute the operation for all elements of the matrixes to the answer-matrix
  for(int i = 0; i<m1.i; i++) {
    for(int j = 0; j<m1.j; j++) {
      (*ans_p).m[i][j].val = m1.m[i][j].val * m2.m[i][j].val;
    }
  }

  return 0;
}
