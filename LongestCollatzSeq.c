#include<stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[])
{
  long i = 1, count = 0, var = 1, max = 0, index = 0;
  long map[1000000];
  printf("*****************************************\n");
  while(var < 1000000)
  {
    if(i == 1)
    {
      printf("map[%ld]: %ld\n", var, map[var]);
      i = var;
      var++;
      count = 0;
    }
    if (i % 2 == 0)
    {
      i /= 2;
      count++;
    }
    else
    {
      i = (3*i) + 1;
      count++;
    }
    map[var] = count;
  }

  for(i = 0; i < 1000000; i++)
  {
    if(map[i] > max)
    {
      //printf("max: %ld\n", max);
      max = map[i];
      index = i;
    }
  }

  for (i = 0; i < 1000000; i++)
  {
    if (map[i] >= max)
    {
      printf("match at index: %ld\n", i - 1);
    }
  }
  printf("Index: %ld holds %ld-long chain\n", index - 1, max);
  return 0;
}
