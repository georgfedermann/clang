#include <stdio.h>
// create an array, do not initialize it, and see what you find in memory
int main(void) {
  char memory[1024];
  int c;
  int arraySize = sizeof(memory) / sizeof(memory[0]);

  for (c = 0; c < arraySize; c++) {
    if ((memory[c] >= '0' && memory[c] <= 9) ||
        (memory[c] >= ' ' && memory[c] <= '~'))
      printf("%c", memory[c]);
    else
      printf(".");
  }
  printf("*%d\n", arraySize);
  return 0;
}
