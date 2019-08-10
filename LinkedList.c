#include <stdio.h>
#include <stdlib.h>


struct node
{
  char data;
  struct node* next;
};

struct node* addToFront(struct node* list, char data);
int count(struct node* list);
void printList(struct node* list);
struct node* addToEnd(struct node* list, char data);
struct node* addToMiddle(struct node* list, char data);

int main(int argc, char*argv[])
{
  struct node* myList = NULL;
  char alpha = 'a';
  char selection;
  int counter = 0;

  for(alpha = 'a'; alpha <= 'z' && counter < 3; alpha++)
  {
    //myList = addToFront(myList, alpha);
    //myList = addToEnd(myList, alpha);
    myList = addToMiddle(myList, alpha);

    if(alpha == 'z')
    {
      alpha = 'a';
      alpha--;
      counter ++;
    }
  }

  printList(myList);
  printf("Count: %d\n", count(myList));
  return 0;
}

struct node* addToFront(struct node* list, char data)
{
  struct node* pNew = (struct node*)malloc(sizeof(struct node));
  pNew->data = data;
  pNew->next = list;

  return pNew;
}
struct node* addToEnd(struct node* list, char data)
{
  struct node* pNew = (struct node*)malloc(sizeof(struct node));
  struct node* help = list;
  pNew->data = data;
  pNew->next = NULL;

  if(list == NULL)
  {
    return pNew;
  }
  while(help->next != NULL)
  {
    help = help->next;
  }

  help->next = pNew;

  return list;
}

struct node* addToMiddle(struct node* list, char data)
{
  struct node* help = list;

  struct node* pNew = (struct node*)malloc(sizeof(struct node));
  pNew->data = data;

  if(list == NULL)
  {
    printf("List is NULL\n");
    return pNew;
  }
  if(data <= list->data)
  {
    printf("Item less than elements\n");
    pNew->next = list;
    return pNew;
  }

  while(help->next != NULL && help->next->data < data)
  {
    help = help->next;
  }

  printf("Item between elements\n");
  pNew->next = help->next;
  help->next = pNew;

  return list;
}

int count(struct node* list)
{
  int count = 0;

  while(list != NULL)
  {
    count++;
    list = list->next;
  }
  return count;
}

void printList(struct node* list)
{
  int i = 0;
  while(list != NULL)
  {
    printf("%d.) %c\n", i, list->data);
    i++;
    list = list->next;
  }
}
