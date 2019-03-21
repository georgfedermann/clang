#include <stdio.h>
/* Fahrenheit to Celsius converter with headers */
#define LOWER_LIMIT 0
#define UPPER_LIMIT 300
#define STEP 20
int main(void){
  printf("%10s\t%10s\n","Fahrenheit","Celsius");
  float fahr;
  for(fahr=0; fahr <= UPPER_LIMIT; fahr += STEP){
    printf("%10.2f\t%10.2f\n",fahr,(fahr-32)*5/9);
  }
  return 0;
}
