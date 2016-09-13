#include <stdlib.h>
#include <stdio.h>

#define M 10

int main(void){

  int tab[M];
  int sorted_tab[M];
  
  int i;
  for(i = 0; i < M; i++){
    *(tab + i) = random() % 100; /*permet d'avoir des randoms entre 0 et 100*/
    printf("tab[%d] = %d \n", i, tab[i]);/*e*/
  }

  tri(tab);
  
  for(i = 0; i < M; i++){
    *(tab + i) = random() % 100; /*permet d'avoir des randoms entre 0 et 100*/
    printf("tab[%d] = %d \n", i, tab[i]);/*e*/
  }
  
    return 0[tab];
}


void tri(int tab[]){

  int t;
  int smaller;
  int temp, j;
  
  for(int i = 0; i < M; i++)
    {
      t = tab[i];
      for(j = i; j < M; j++)
	{
	  if(tab[j] <= t){
	    smaller = tab[j];
	    
	  }
	}
      tab[i] = smaller;
      tab[j] = t;
    }

}
