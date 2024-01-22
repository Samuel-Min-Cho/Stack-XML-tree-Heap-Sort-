#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
extern char *pop();
extern void push(char *);

int main(int argc, char *argv[])
{
  int ch;
  char input[50];

  while ((ch = getchar()) != EOF)
  {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      continue;
    if (ch == '<')
    {
      int in = 0;
      int catch = 0;
     // printf("You are now in <\n");
      while ((ch = getchar()) != '>')
      {
        if (ch == '/')
        {
       //   printf("These are output\n");
          catch = 1;
        }
        else if (isalpha(ch))
        {
          input[in] = ch;
          in++;
        }
      }
      input[in] = '\0';
      if (in != 0)
      {
        push(input);
     //   printf("Input saved\n");
        in = 0;
      }
      if (catch == 1)
      {
        char *k = pop();
        printf("Popped: %s\n", k);
        catch = 0;
      }
   //   printf("You are now at >\n");
    }
  }
  exit(0);
}
