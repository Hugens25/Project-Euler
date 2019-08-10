#include<stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[])
{
  int i = 1, j = 1, k = 1;
  for(i = 1; i < 1000; i++)
  {
    for (j = 1; j < 1000; j++)
    {
      for(k = 1; k < 1000; k++)
      {
        if (i + j + k == 1000 && (i * i) + (j * j) == (k*k))
        {
          printf("(%d, %d, %d)\n", i, j, k);
          printf("%d\n", i * j * k);
          return 0;
        }
      }
    }
  }
  return 0;
}
