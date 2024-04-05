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
  val_t m1[3][4];
  matrix_t matrix_1 = (matrix_t) {3, 4, m1};
  val_t m2[3][4];
  matrix_t matrix_2 = (matrix_t) {3, 4, m2};

  printf("finish......");

  return 0;
}
