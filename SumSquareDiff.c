#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
  int sumOfSquares = 0, squareOfSums = 0, i = 0, result = 0;

  for (i = 1; i <= 100; i++)
  {
    sumOfSquares += i * i;
    squareOfSums += i;
    //printf("sumOfSquares: %d, squareOfSums: %d\n", sumOfSquares, squareOfSums);
  }
  squareOfSums = squareOfSums * squareOfSums;

  result = squareOfSums - sumOfSquares;

  printf("%d - %d = %d\n", squareOfSums, sumOfSquares, result);

  return 0;
}
