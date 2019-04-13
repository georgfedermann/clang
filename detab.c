#include <stdio.h>
// scans a character stream that replaces tab characters in the input stream by
// the propert number of blanks.

// max line length in characters
#define MAX_LINE_LENGTH 120

int readline(char currentLine[], int lineMaxLength);

void replaceTabs(char currentLine[], int lineMaxLength);

int main(void){
  
  char currentLine[120];
  int maxLineLength = MAX_LINE_LENGTH, currentLineLength;

  while ((currentLineLength = readline(currentLine, maxLineLength)) > 0){

  }

  return 0;
}
