#include <stdio.h>
void display_int(unsigned int a){

  if(a == 0) return;

  display_int(a/10);
  putchar(a%10 + '0');
  
  return;

}

void display_int2(unsigned int a){

  if(a == 0)
    putchar('0');
  else
    display_int(a);
  
  return;
  
  
}
