#include <stdio.h>
int main(void){
  int car;

  while((car = getchar()) != EOF){

    putchar(car ^ 'x');

  }
  return 1;
}
