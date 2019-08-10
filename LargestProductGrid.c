#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int asciiToInt(int num);
int bannedNums(int num, char det);
void getUpDown();
void getDiagL();
void getDiagR();

long upDown[1000], rDiag[1000], lDiag[1000];
int countL = 0, countR = 0;
int chars[1000];


int main(int argc, char*argv[])
{
  FILE *file = fopen("test2", "r");
  char c;
  long i = 0, j = 0, count = 0, max = 0, maxU = 0, maxR = 0, maxL = 0, k = 0;
  long vals[1000];

  if (file == NULL)
  {
    printf("FILE NOT FOUND!\n");
    return 0;
  }
  else
  {
    while(!feof (file))
    {
      fscanf(file, "%d", &chars[i]);
      i++;
    }
  }

  for (i = 0; i < 1000; i ++)
  {
    vals[i] = 1;
    upDown[i] = 1;
    rDiag[i] = 1;
    lDiag[i] = 1;
  }

  getUpDown();
  getDiagL();
  getDiagR();

  for(i = 0; i < (1000 - 4); i++)
  {
    k = i + 4;
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
  maxU = upDown[0];
  maxL = lDiag[0];
  maxR = rDiag[0];

  for (i = 0; i < 400; i++)
  {
    if (vals[i] > max)
    {
      max = vals[i];
    }
    if (upDown[i] > max)
    {
      maxU = upDown[i];
    }
    if (lDiag[i] > max)
    {
      maxL = lDiag[i];
    }
    if (rDiag[i] > max)
    {
      maxR = rDiag[i];
    }
  }

  if(maxL > max)
  {
    max = maxL;
  }
  if(maxR > max)
  {
    max = maxR;
  }
  if(maxU > max)
  {
    max = maxU;
  }

  printf("MAX: %ld\n", max);

  fclose(file);
  return 0;
}

void getUpDown()
{
  int i = 0; int j = 0, k = 0, count = 0;
  printf("*******UPDOWN********\n");
  for(i = 0; i < (400 - 60); i++)
  {
    printf("%d * %d * %d * %d\n", chars[i],chars[i + 20],chars[i + 40],chars[i + 60]);
    upDown[i] = (chars[i] * chars[i + 20] * chars[i + 40] * chars[i + 60]);
  }
}

void getDiagR()
{
  int i = 0; int j = 0, k = 0, count = 0;
  printf("*******RDIAG********\n");
  for(i = 0; i < (400 - 63); i++)
  {
    if(bannedNums(i, 'r') == 1)
    {
      printf("%d * %d * %d * %d\n", chars[i],chars[i + 21],chars[i + 42],chars[i + 63]);
      rDiag[i] = (chars[i] * chars[i + 21] * chars[i + 42] * chars[i + 63]);
    }
  }
}

void getDiagL()
{
  int i = 1; int j = 0, k = 0, count = 0;
  printf("*******LDIAG********\n");
  for(i = 0; i < (400 - 59); i++)
  {
    if(bannedNums(i, 'l') == 1)
    {
      printf("%d * %d * %d * %d\n", chars[i],chars[i + 19],chars[i + 38],chars[i + 57]);
      lDiag[i] = (chars[i] * chars[i + 19] * chars[i + 38] * chars[i + 57]);
    }
  }
}

int bannedNums(int num, char det)
{
  int i = 0, l = 0, r = 0;
  if(det == 'r')
  {
    i = 17;
    l = 17;
    r = 20;
  }
  else if (det == 'l')
  {
    i = 0;
    l = 0;
    r = 2;
  }

  for (i = i; i < 400; i += 10, l+= 10, r += 10)
  {
    if(num >= l && num <= r)
    {
      return 0;
    }
  }
  return 1;
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
