#include<stdio.h>
#include<stdlib.h>

int weightedSum(int numbers[], int n);
int multN(int n);

int main()
{
  int array[] = {7,5,8};
  int count = sizeof(array)/sizeof(int);
  //printf("%d\n", weightedSum(array, count));
  //printf("\n%d\n", 0%2);
  printf("Num: %d\n", multN(274));
  return 0;
}

int weightedSum(int numbers[], int n) {
 if (n == 0) return 0;
 printf("%d*numbers[%d] + weightedSum(numbers, %d)\n", n, numbers[n-1], n-1);
 return n*numbers[n-1] + weightedSum(numbers, n-1);
}

int multN(int n)
{
  int num = n%10;

  if(n == 0)
  {
    return 1;
  }

  return num*multN(n/10);
}
