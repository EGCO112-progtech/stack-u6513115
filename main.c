#include "node.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

  int i, N, j;
  Stack s;
  s.top = NULL;
  s.size = 0;

  printf("****************************\n");
  printf("atoi(argv[i]) = ");
  for (i = 1; i < argc; i++) // argc 0 is program name
  {
    pushs(&s, atoi(argv[i]));
    printf("%d\t", atoi(argv[i]));
  }
  printf("****************************\n");

  while (s.top) {
    printf("%d\n", pops(&s));
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
