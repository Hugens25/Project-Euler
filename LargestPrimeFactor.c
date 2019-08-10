#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(long num);

int main(int argc, char*argv[])
{
  long i = 0;
  long num = 0;
  char *ptr;

  if (argc > 1)
  {
    num = strtol(argv[1], &ptr, 10);
  }
  else
  {
    printf("NO ARGS FOUND!\n");
    return 0;
  }

  for(i = sqrt(num); i > 0; i--)
  {
    if(num % i == 0 && is_prime(i) == 1)
    {
      printf("%ld\n", i);
    }
  }

  return 0;
}

int is_prime(long num)
{
     if (num <= 1) return 0;
     if (num % 2 == 0 && num > 2) return 0;
     for(int i = 3; i < sqrt(num); i+= 2)
     {
         if (num % i == 0)
             return 0;
     }
     return 1;
}
