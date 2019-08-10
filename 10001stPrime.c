#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(long num);

int main(int argc, char*argv[])
{
  long i = 0, count = 1;

  for(i = 1; count <= 10001; i++)
  {
    if (is_prime(i) == 1)
    {
      printf("%ldth element is: %ld\n", count, i);
      if(count == 10001)
      {
        //printf("10,001th element is: %ld\n", i);
      }
      count++;

    }
  }
  return 0;
}

int is_prime(long num)
{
     if (num <= 1) return 0;
     if (num % 2 == 0 && num > 2) return 0;
     for(int i = 3; i <= sqrt(num); i+= 2)
     {
         if (num % i == 0)
             return 0;
     }
     return 1;
}
