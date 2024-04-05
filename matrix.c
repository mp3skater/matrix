/*
 * Module: matrix.c
 * Author: mp3skater
 * Version: 0.1
 * License: MIT License
 */

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "matrix.h"

matrix_t create_random_matrix(int row, int col)
{
  // Allocate the memory for a new matrix
  matrix_t *mat = malloc(sizeof(matrix_t) + sizeof(val_t *) * row);

  if(mat == NULL) {
    // Handle allocation failure
    return NULL;
  }

  srand(time(NULL));

  // All elements of the matrix filled and printed
  val_t r;
  for(int i = 0; i<m.i; i++) {
    for(int j = 0; j<m.j; j++) {
      r.val = rand()%(n+1);
      m.m[i][j] = r;
      printf("%lf ", r.val);
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
    return 1;
  }

  // Compute the operation for all elements of the matrixes to the p
  for(int i = 0; i<m1.i; i++) {
    for(int j = 0; j<m1.j; j++) {
      (*ans_p).m[i][j].val = m1.m[i][j].val + m2.m[i][j].val;
    }
  }

  printf("done...");

  return 0;
}
