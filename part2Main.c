#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);

extern int heapSize();
extern void addHeap(int);
extern void printArray();
extern int heapDelete();
extern void tree(int);

int main(int argc, char *argv[])
{
  int value;
  while (scanf("%d\n", &value) != EOF)
  {
    if (isdigit(value)!=0)
    {
      fprintf(stderr, "READING INPUT: %d\n", value);
      exit(1);
    }
    addHeap(value);
  }

  int size = heapSize();
  printArray();
  printf("\n");
  tree(0);
  printf("\n");
  
  while (heapSize() > 0)
  {
    push(heapDelete());
  }

  for (int i = 0; i < size; i++)
  {
    printf("%d ", pop());
  }

  exit(0);
}
