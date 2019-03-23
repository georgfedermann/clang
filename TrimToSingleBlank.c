#include <stdio.h>
// Read input and replace any sequence of whitespace with
// one single blank character.

int isWhitespace(int character) {
  return character == ' ' || character == '\t';
}

int main(void) {
  // 1 if last character was non whitespace, 0 if it was whitespace.
  int lastCharWasNotBlank = 0;
  int readChar;
  while ((readChar = getchar()) != EOF) {
    if (!isWhitespace(readChar)) {
      lastCharWasNotBlank = 1;
      putchar(readChar);
    } else if (lastCharWasNotBlank) {
      lastCharWasNotBlank = 0;
      putchar(' ');
    } else {
      ;
    }
  }
  return 0;
}
