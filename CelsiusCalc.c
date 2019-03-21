#include <stdio.h>
// Implement a simple Fahrenheit to Celsius converter 
#define LOWER_LIMIT 0
#define UPPER_LIMIT 300
#define STEP 20
int main(void){
  int fahr = 0;
  while(fahr <= 300){
    printf("%4d\t%4d\n",fahr,(fahr-32)*5/9);
    fahr += STEP;
  } 
  return 0;
}

