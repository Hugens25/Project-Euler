#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int num);
int primeFactorization(int num);

int main(int argc, char*argv[])
{
  int i = 0, j = 0, result = 1, breakNow = 0;
  for (i = 2520; i < 1000000; i++)
  {
    result = 1;
    for(j = 1; j <= 20; j++)
    {
      if(i % j != 0)
      {
        i++;
        j = 0;
      }
    }
    if(result == 1)
    {
      printf("Result: %d\n", i);
    }
  }
  return 0;
}
