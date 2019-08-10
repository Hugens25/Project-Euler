#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* itoa(int, char* , int);

int main(int argc, char* argv[])
{
  int num1 = 0, num2 = 0, i = 0, j = 0;
  long num3 = 0;
  char total[7];
  int vals[10000];
  int count = 0;
  long max = 0;
  if (argc > 2)
  {
    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);
  }
  else
  {
    printf("NOT ENOUGH ARGS!\n");
  }

  for (i = num1; i > 100; i--)
  {
    for(j = num2; j > 100; j--)
    {
      num3 = i * j;
      if((num3 / 100000) % 10 == (num3 / 1) % 10 && (num3 / 10000) % 10 == (num3 / 10) % 10 && (num3 / 1000) % 10 == (num3 / 100) % 10)
      {
        printf("%d * %d = %ld\n", i, j, num3);
        vals[count] = num3;
        count++;
      }
    }
  }

  max = vals[0];
  for (i = 0; i < count; i++)
  {
    if (vals[i] > max)
    {
      max = vals[i];
    }
  }
  printf("Max is: %ld\n", max);
  return 0;
}
