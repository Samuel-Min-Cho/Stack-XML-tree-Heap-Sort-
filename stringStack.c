#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 *  The functions in this module implement a Stack data structure
 *  of char pointers (aka "strings").
 *
 *  NOTE: the stack is implemented as a fixed size array (size = 100).
 *  Consequently, no more than 100 strings can be pushed onto
 *  the Stack at any given time.
 */

// Implementation hints:
//   The 3 functions--push, pop and isEmpty--share information
//   about the array used to implement the stack and the index
//   of the "top" of the stack.
//
//   You may want to make these variables global...
//   ...but that would
//   be a mistake (because anyone using the module would have
//   to ensure that they did not use global variables with the
//   same names).
//
//   An alternative in C is a "static global".
//   If a global variable is qualified as "static", it is global only
//   within the source code file where it is declared.
//   In parituclar, it cannot conflict with any other global variable.
//
//  RECOMMENDATION:
//   Uncomment the following 2 lines and use these static globals!
static int top = 0;
static char *stack[100];
/**
 * isEmpty() returns a non-zero integer (not necessarily 1) if the
 * stack is empty; otherwise, it returns 0 (zero).
 *
 */
int isEmpty()
{
  if (stack[0] == NULL)
  {
    return 1;
  }
  else
  {
    return 0; // A dummy return statement
  }
}
/**
 * pop() removes the top string on the stack and returns it.
 *
 * If pop() is attempted on an empty stack, an error message
 * is printed to stderr and the value NULL ((char *) 0) is returned.
 */

char *pop()
{
  char *ch;
  //printf("%s\n",stack[top - 1]);
  //printf("%s\n",stack[top - 2]);
  if (isEmpty()!= 0 || (top-1) <= 0)
  {
    fprintf(stderr, "%s", "Array is Null");
    exit(1);
  }
  else
  {
    if (strcmp(stack[top - 1],stack[top - 2]) == 0)
    {
      ch = stack[top - 2];
      stack[top - 1] = NULL;
      stack[top - 2] = NULL;
      top = top - 2;
      return (ch);
    }
    else
    {
      fprintf(stderr, "%s", "Invalid expression");
      exit(1);
    }
  }
}

/**
 *  push(thing2push) adds the "thing2push" to the top of the stack.
 *
 *  If there is no more space available on the Stack, an error
 *  message is printed to stderr.
 */
void push(char *thing2push)
{
  if (top == 99)
  {
    fprintf(stderr, "%s","No more space available on the Stack");
    exit(1);
  }
  else
  {
    stack[top] = (char *)malloc(strlen(thing2push) * sizeof(char));
    strcpy(stack[top], thing2push);
    top++;
  }
  /*
  int i = 0;
  while (stack [i] != NULL){
    printf("%s\n",stack[i]);
    i++;
  }
  */
}

