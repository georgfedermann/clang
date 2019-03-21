#include <stdio.h>

#define UPPER_LIMIT 5
// this program counts up from 1 to 10 and prints each number
int main(void){
  int c;
  for ( c=1; c <= UPPER_LIMIT; c++ ){
    printf("%d\n", c);
  }
  return 0;
}
