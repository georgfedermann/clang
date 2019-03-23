#include <stdio.h>
// Makes whitespace visible by replacing whitespace with 
// respective escape sequences: \t for tab, \n for newline
// underscore for blanks, backslash by escaped backslash
int main(void){
  int character;
  while( (character = getchar()) != EOF ){
    if(character==' ')
      putchar('_');
    else if(character=='\\')
      putchar('\\');
    else if(character=='\t'){
      putchar('\\');
      putchar('t');
    } else if(character=='\n'){
      putchar('\\');
      putchar('n');
    } else if(character == '\b' ){
      putchar('\\');
      putchar('b');
    } else
      putchar(character);
  }
  return 0;
}
