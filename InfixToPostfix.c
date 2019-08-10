#include<stdio.h>
#include<stdlib.h>
#define SIZE 30

struct stack
{
  char items[SIZE];
  int top;
};

void init(struct stack* stackPtr);
int isEmpty(struct stack* stackPtr);
int full(struct stack* stackPtr);
int push(struct stack* stackPtr, char value);
char pop(struct stack* stackPtr);
int top(struct stack* stackPtr);
int computeValue(char array[], int count);
int convertValues(char a);


int main(int argc, char*argv[])
{
  FILE *file = fopen("infix", "r");
  char result[SIZE];
  char finalResult[15];
  char expression[SIZE];
  char c;
  int i = 0, j = 0, count = 0;
  struct stack* stackPtr;

  init(stackPtr);

  if(file == NULL)
  {
    printf("FILE NOT FOUND!\n");
    return 0;
  }

  for(i = 0; i < SIZE; i++)
  {
    expression[i] = '&';
    result[i] = '&';
  }

  i = 0;
  while((c = fgetc(file)) != EOF)
  {
    if (c != ' ' && c != '\n')
    {
      expression[i] = c;
      i++;
    }
  }

  for(i = 0; i < SIZE && expression[i] != '&'; i++)
  {
    if (expression[i] >= '0' && expression[i] <= '9')
    {
      result[j] = expression[i];
      j++;
    }

    else if(expression[i] == '(')
    {
      push(stackPtr, expression[i]);
    }

    else if(expression[i] == '*' || expression[i] == '/')
    {
      if(stackPtr->items[stackPtr->top] == '*' || stackPtr->items[stackPtr->top] == '/')
      {
        result[j] = pop(stackPtr);
        j++;
        i--;
      }
      else
      {
        push(stackPtr, expression[i]);
      }
    }

    if (expression[i] == '+' || expression[i] == '-')
    {
      if(isEmpty(stackPtr) || stackPtr->items[stackPtr->top] == '(')
      {
        push(stackPtr, expression[i]);
      }
      else
      {
        result[j] = pop(stackPtr);
        j++;
        i--;
      }
    }
  }

  for(i = 0; i < SIZE && stackPtr->items[i] != '&'; i++)
  {
    result[j] = stackPtr->items[i];
    j++;
  }

  j = 0;
  for(i = 0; i < SIZE && result[i] != '&'; i++)
  {
    if(result[i] == '+' || result[i] == '-' || result[i] == '*' || result[i] == '/' || (result[i] <= '9' && result[i] >= '0'))
    {
      //printf("%c, ", result[i]);
      finalResult[j] = result[i];
      j++;
      count++;
    }
  }
  for (i = 0; i < count; i++)
  {
    printf("%c ", finalResult[i]);
  }
  printf("\nComputed Value: %d", computeValue(finalResult, count));
  printf("\n");
  return 0;
}

int computeValue(char array [], int count)
{
  int result = 0, i = 0;
  struct stack* stackPtr2;
  init(stackPtr2);

  for (i = 0; i < count; i++)
  {
    if(array[i] <= '9' && array[i] >= '0')
    {
      push(stackPtr2, array[i]);
    }
    else
    {
      if(array[i] == '+')
      {
        result = convertValues(pop(stackPtr2)) + convertValues(pop(stackPtr2));
        push(stackPtr2, result);
      }

      if(array[i] == '-')
      {
        result = convertValues(pop(stackPtr2)) - convertValues(pop(stackPtr2));
        push(stackPtr2, result);
      }

      if(array[i] == '*')
      {
        result = convertValues(pop(stackPtr2)) * convertValues(pop(stackPtr2));
        push(stackPtr2, result);
      }

      if(array[i] == '/')
      {
        result = convertValues(pop(stackPtr2)) / convertValues(pop(stackPtr2));
        push(stackPtr2, result);
      }
    }
  }
  return pop(stackPtr2);
}

int convertValues(char a)
{
  int retval = 0;
  switch (a)
  {
    case '0':
      retval = 0;
    case '1':
      retval = 1;
    case '2':
      retval = 2;
    case '3':
      retval = 3;
    case '4':
      retval = 4;
    case '5':
      retval = 5;
    case '6':
      retval = 6;
    case '7':
      retval = 7;
    case '8':
      retval = 8;
    case '9':
      retval = 9;

    default:
      break;

  }
  return retval;
}

void init(struct stack* stackPtr)
{
   stackPtr->top = -1;
}

int isEmpty(struct stack* stackPtr)
{
  return (stackPtr->top == -1);
}

int full(struct stack* stackPtr)
{
  return (stackPtr->top == SIZE - 1);
}

int push(struct stack* stackPtr, char value)
{
  (stackPtr->top)++;
  stackPtr->items[stackPtr->top] = value;
  return 1;
}

char pop(struct stack* stackPtr)
{
  char temp = stackPtr->items[stackPtr->top];
  stackPtr->items[stackPtr->top] = '&';
  (stackPtr->top)--;
  return temp;
}

int top(struct stack* stackPtr)
{
  return (stackPtr->top);
}
