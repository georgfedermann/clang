#include <stdio.h>
// prints lines longer than 80 characters

#define MAX_LINE_LENGTH 120

char currentLine[MAX_LINE_LENGTH];
int currentLineLength;

// reads the current line and returns the length of the current line
void readLine(void);

int main(void) {
  extern char currentLine[];
  extern int currentLineLength;

  do {
    readLine();
    if (currentLineLength > 80) {
      printf("%s\n", currentLine);
    }
  } while (currentLineLength != 0);

  return 0;
}

void readLine() {
  int character, counter;
  extern char currentLine[];
  extern int currentLineLength;

  currentLineLength = 0;

  for (counter = 0; counter < MAX_LINE_LENGTH &&
                    (character = getchar()) != EOF && character != '\n';
       counter++) {
    currentLine[counter] = character;
  }
  printf("Counter has value %d.\n", counter);
  if (counter == 120) counter--;
  currentLine[counter] = '\0';
  currentLineLength = counter;
}
