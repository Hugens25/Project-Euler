#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int asciiToInt(int num);


int main(int argc, char*argv[])
{
  FILE *file = fopen("test", "r");
  int chars[1000];
  char c;
  long i = 0, j = 0, count = 0, max = 0, k = 0;
  long vals[1000];

  if (file == NULL)
  {
    printf("FILE NOT FOUND!\n");
    return 0;
  }
  else
  {
    while((c = fgetc(file)) != EOF)
    {
      if(c != '\n')
      {
        chars[i] = asciiToInt(c);
        i++;
      }
    }
  }
  for (i = 0; i < 1000; i ++)
  {
    vals[i] = 1;
  }

  for(i = 0; i < (1000 - 13); i++)
  {
    k = i + 13;
    vals[count] = 1;

    for (j = i; j < k; j++)
    {
      vals[count] *= chars[j];
    }
    
    if(vals[count] > 0)
    {
      count++;
    }

  }

  max = vals[0];

  for (i = 0; i < count; i++)
  {
    printf("vals[%ld] = %ld\n", i, vals[i]);
    if (vals[i] > max)
    {
      max = vals[i];
    }
  }

  printf("MAX: %ld\n", max);
  return 0;
}

int asciiToInt(int num)
{
  int val = 0;

  switch (num){
    case 48:
      val = 0;
      break;
    case 49:
      val = 1;
      break;
    case 50:
      val = 2;
      break;
    case 51:
      val = 3;
      break;
    case 52:
      val = 4;
      break;
    case 53:
      val = 5;
      break;
    case 54:
      val = 6;
      break;
    case 55:
      val = 7;
      break;
    case 56:
      val = 8;
      break;
    case 57:
      val = 9;
      break;

    default:
      break;
    }
    return val;
}
