#include<stdio.h>
#include<stdlib.h>

long factorial(int num);

int main(int argc, char*argv[])
{
  printf("%ld\n", factorial(atoi(argv[1])));
  return 0;
}

long factorial(int num)
{
long i = 0, result = 1;
for(i = 1; i <= num; i++)
{
  result *= i;
}
return result;
}
