#include <stdio.h>

int main(int argCount, char** argValues){
  printf("This program lists the arguments it accepted.\n");
  printf("Number of arguments: %d.\n", argCount);
  printf("The argument at position 0 should be the program's own name: %s.\n", argValues[0], 33);
  if ( argCount > 1 ){
    int c;
    for ( c = 1; c < argCount; c++ ) {
      printf("The arg at position %d is %s.\n", c, argValues[c]);
    }
  }
  return 0;
}

