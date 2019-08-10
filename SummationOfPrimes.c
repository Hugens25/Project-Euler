#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int is_prime(long num);

int main(int argc, char*argv[])
{
  long i = 0, value = 1;

  for(i = 2000000; i > 0; i--)
  {
    if(is_prime(i) == 1)
    {
      //printf("prime[%ld]\n", i);
      value += i;
    }
  }
  printf("Value: %ld\n", value);
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
