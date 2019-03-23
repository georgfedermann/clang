#include <stdio.h>
// show that getchar() == EOF is either 0 or 1.
// Program can be run like so:
// cat data/words | bin/CompareEof
int main(void) {
  int c;
  do {
    c = (getchar() == EOF);
    printf("Value of (getchar() == EOF) is %d.\n", c);
  } while (c != 1);
}
