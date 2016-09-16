#include <unistd.h>
#include <stdio.h>
#include <string.h>
int
main(int argc, char * argv[]){

  int result;
  int opt_access = 0;
  int i;

  for(i=2; i<argc; i++){
      if(strcmp(argv[i],"-r")){
	opt_access = opt_access | R_OK;
      }
      if(strcmp(argv[i],"-w")){
	opt_access = opt_access | W_OK;
      } 
      if(strcmp(argv[i],"-x")){
	opt_access = opt_access | X_OK; 
      }
  }

  result = access(argv[1], opt_access);
  
  printf("chemin: %s\narg1: %s\narg2: %s\narg3: %s\n",argv[1], argv[2], argv[3], argv[4]);
  printf("%d\n%d\n%d\n", result, opt_access, argc);
  
  
  return 0;
}
