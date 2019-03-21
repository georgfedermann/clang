#include <stdio.h>
#define UPPER_LIMIT 300
#define LOWER_LIMIT 0
#define STEP 20

int main(void){
  printf("%10s\t%10s\n","Fahrenheit","Celsius");
  int fahr=UPPER_LIMIT;
  for(fahr=UPPER_LIMIT; fahr>=0; fahr-=STEP){
    printf("%10.2d\t%10.2f\n",fahr,(fahr-32)*5.0/9.0);
  }
  return 0;
}
