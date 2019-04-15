#include <stdio.h>
// prints its input one word per line

#define WITHIN_WORD_BOUNDARY 0
#define OUTSIDE_WORD_BOUNDARY 1

int isWhitespace(int character) {
  return character == ' ' || character == '\n' || character == '\t';
}

int main(void) {
  int character, state = OUTSIDE_WORD_BOUNDARY;
  while ((character = getchar()) != EOF) {
    if (!isWhitespace(character)) {
      state = WITHIN_WORD_BOUNDARY;
      putchar(character);
    } else if (state == WITHIN_WORD_BOUNDARY) {
      state = OUTSIDE_WORD_BOUNDARY;
      putchar('\n');
    }
  }
  return 0;
}
