#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int
main(int argc, char * argv[]){

	if(argc > 1){
		printf("La commande ne prend pas d'argument\n");
		return 1;
	}
	printf("NAME_MAX: %d \nPATH_MAX: %d\n", NAME_MAX, PATH_MAX);
	return 0;

}
