/*
 * Test module for all the operations of the matrix module.
 */

#include <stdio.h>

#include "matrix.h"

/*
 * This module creates two matrixes and tries to add/sub/skale/mul them with each other, errors unhandled for now
 */
int main(void)
{
  matrix_t m = create_matrix(3, 4);
  fill_random_matrix(10, m);

  madd(m, m, &m);
  msub(m, m, &m);
  mprod(m, m, &m);

  printf("finish......");

  return 0;
}
