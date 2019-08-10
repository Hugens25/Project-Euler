#include<stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[])
{

  int i = 0, j = 0, n = atoi(argv[1]), count = 0, runner = 0;
  int jStart = 0, iStart = 0, incBy = 1, increase = 0;
  int matrix[n + 1][n + 1];

  while(jStart < n && incBy <= n)
  {
    printf("(%d, %d)->", i, j);
    if(j + 1 <= n)
    {
      j++;
      printf("(%d, %d)->", i, j);
    }
    if(i + 1 <= n)
    {
      while(i + incBy > n)
      {
        incBy--;
      }
      i += incBy;

      printf("(%d, %d)->", i, j);
    }


    if(j == n && i == n)
    {
      printf("(%d, %d)", i, j);
      printf("\n\n");
      count++;
      jStart++;
      j = jStart;
      i = iStart;
      if(jStart == n && incBy < n)
      {
        jStart = 0;
        incBy++;
        j = jStart;
      }
    }
    //printf("(%d, %d)\n", i, j);
  }
  count *= 2;
  printf("\ncount: %d\n", count);
  return 0;
}
