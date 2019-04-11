#include <stdio.h>
// capable of reversing strings

#define MAX_LINE_LENGTH 10000

void reverse(char line[], int length);
int getLine(char data[], int maxLength);

int main(void) {
  char currentLine[MAX_LINE_LENGTH];

  int lineLength;
  while ((lineLength = getLine(currentLine, MAX_LINE_LENGTH)) != 0) {
    reverse(currentLine, lineLength);
    printf("%s\n", currentLine);
  }

  return 0;
}

void reverse(char line[], int length) {
  char buffer;
  int counter;
  for (counter = 0; counter < length / 2; counter++) {
    buffer = line[counter];
    line[counter] = line[length - 1 - counter];
    line[length - 1 - counter] = buffer;
  }
}

// returns number of characters read in current line
int getLine(char data[], int maxLength) {
  int counter, character;

  for (counter = 0; counter < maxLength - 1 && (character = getchar()) != EOF &&
                    character != '\n';
       counter++) {
    data[counter] = character;
  }
  data[counter] = '\0';
  return counter;
}
