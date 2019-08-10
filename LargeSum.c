#include<stdio.h>
#include<stdlib.h>


int asciiToInt(int num);


int main(int agc, char*argv[])
{
  FILE *file = fopen("test3", "r");
  int i = 0, j = 0, k = 99, halt = 0, counter = 0, rem = 0;
  char c;
  int array[100][50];
  int result[100];

  for(i = 0; i < 100; i++)
  {
    result[i] = -1;
    for(j = 0; j < 50; j++)
    {
      array[i][j] = 0;
    }
  }

  if(file == NULL)
  {
    printf("FILE NOT FOUND!\n");
    return 0;
  }
  //while(!feof (file))
  //{
    //fscanf(file, "%lld", &array[i]);
    //i++;
  //}

  for(i = 0; i < 100; i++)
  {
    for(j = 0; j < 50; j++)
    {
      c = fgetc(file);
      if(c != '\n')
      {
        array[i][j] = asciiToInt(c);
        printf("array[%d][%d] = %d\n", i, j, array[i][j]);
        //printf("c = %c: %d\n", c, asciiToInt(c));
      }
      else
      {
        j--;
      }
    /*while((c = fgetc(file)) != EOF && halt == 0)
    {
      if(c != '\n')
      {
        array[i][j] = asciiToInt(c);
        j++;
        if(j == 50)
        {
          i++;
          if(i == 100)
          {
            halt = 1;
          }
          j = 0;
        }
      }*/
    }
  }

  for (i = 49; i >= 0; i--, k--)
  {
    for (j = 0; j < 100; j++)
    {
      printf("result[%d] += %d\n", k, array[j][i]);
      result[k] += array[j][i];
    }
    result[k]++;
    printf("result: %d\n", result[k]);
    result[k] += rem;
    printf("result + rem[%d]: %d\n", rem, result[k]);
    rem = result[k] / 10;
    result[k] = result[k] % 10;
    printf("updated result: %d, rem: %d\n", result[k], rem);
  }

  for(i = 0; i < 100; i++)
  {
    if(result[i] != -1)
    {
      printf("%d", result[i]);
    }
  }
  printf("\nrem: %d\n", rem);


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
      val = -1;
      break;
    }
    return val;
}
