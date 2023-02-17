#include "node.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

  int i, N, j, count;
  int checkmatch,checkclose,checkopen;
  Stack s;
  s.top = NULL;
  s.size = 0;

  printf("****************************\n");

  for (i = 1; i < argc; i++) // argc 0 is program name
  {
    N = 0; // check error
    checkmatch = 0;
    checkclose = 0;
    checkopen = 0;

    for (j = 0; j < strlen(argv[i]); j++) {
      switch (argv[i][j]) {
      case '{':
        pushs(&s, argv[i][j]);
        // printf("%c\n", argv[i][j]);
        break;
      case '[':
        pushs(&s, argv[i][j]);
        // printf("%c\n", argv[i][j]);
        break;
      case '}':
        if (pops(&s) != '{')
          // pops(&s);
          N = 1;
        if (pops(&s) == 0)
        break;
      case ']':
        if (pops(&s) != '[')
          // pops(&s);
          N = 1;
        if (pops(&s) == 0)
        break;
      }
    }

    if (s.size > 0) {
      // printf("Incorrect: too many open parenthesis\n");
      N = 2;
    }
    if (N == 0)
      printf("argv %d : Correct\n", i);
    else if (N == 2)
      printf("Incorrect: too many open parenthesis\n");
    else if (N == 3)
      printf("Incorrect: too many close parenthesis\n");
    else if (N == 1)
      printf("argv %d : InCorrect: Mismatch\n", i);
    pop_alls(&s);
  }
  printf("****************************\n");

  /*
  printf("****************************\n");
  push(&top,5);
  printf("%d\n",pop(&top));
  push(&top,7);
  push(&top,8);
  printf("%d\n",pop(&top));
  printf("%d\n",pop(&top));
  printf("%d\n",pop(&top));*/

  /*
  Stack s;
  printf("Checking the parentheses in argv arguments\n");
   for(i=1;i<argc;i++){

      for(j=0;j<strlen(argv[i]);j++){
         Use stack to help with the parentheses


      }


   }
 */

  return 0;
}
