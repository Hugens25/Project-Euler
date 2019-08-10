#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int optimized(long num);
int is_prime(long num);

int halt = 0;

int main(int argc, char*argv[])
{
  long num = 0;
  long it = 1;
  int count = 0;
  while(count < 500)
  {
    num += it;
    count = optimized(num);
    it++;
  }
}

int optimized(long num)
{
  int i = 0, count = 1;
  long value = num;
  long factorization[1000000];

  for(i = 0; i < 1000000; i++)
  {
    factorization[i] = 0;
  }

  for(i = 2; i < sqrt(num); i++)
  {
    if(is_prime(i) && num % i == 0)
    {
      factorization[i] += 1;
      num /= i;
      i--;
    }
  }
  for(i = 0; i < sqrt(value); i++)
  {
    if(factorization[i] != 0)
    {
      factorization[i]++;
      count *= factorization[i];
    }
  }
  count *= 2;
  printf("%ld has %d factors\n", value, count);
  return count;
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
