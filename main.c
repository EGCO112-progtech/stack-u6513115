#include "node.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

  int i, N, j;
  int ckop,ckcl;
  Stack s;
  s.top = NULL;
  s.size = 0;

  for (i = 1; i < argc; i++) // argc 0 is program name
  {
    // check error
    N = 0; 
    ckop = 0;
    ckcl = 0;

    /*if (strlen(argv[i]) % 2 != 0) {
      printf("argv %d : InCorrect!!!!\n", i);
      break;
    }*/

    for (j = 0; j < strlen(argv[i]); j++) {
      switch (argv[i][j]) {
      case '{':
        pushs(&s, argv[i][j]);
        ckop++;
        // printf("%c\n", argv[i][j]);
        break;
      case '[':
        pushs(&s, argv[i][j]);
        ckop++;
        // printf("%c\n", argv[i][j]);
        break;
      case '}':
        ckcl++;
        if (pops(&s) != '{')
          N = 1;
        break;
      case ']':
        ckcl++;
        if (pops(&s) != '[')
          N = 1;
        break;
      }
    }

    if (s.size > 0) {
      N = 1;
    }
    if (N == 0)
      printf("argv %d : correct\n", i);
    else if (ckop>ckcl)
      printf("argv %d : incorrect: too many open parenthesis\n", i);
    else if (ckcl>ckop)
      printf("argv %d : incorrect: too many closed parenthesis\n", i);
    else if (ckcl==ckop&&N==1)
      printf("argv %d : incorrect: mismatch\n", i);
    pop_alls(&s);

  }
  

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
