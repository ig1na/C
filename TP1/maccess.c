#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int
main(int argc, char * argv[]){

  int result;
  int opt_access = 0;
  int v_ok = 0;
  int i;

  for(i=2; i<argc; i++){
      if(!strcmp(argv[i],"-r")){
	opt_access = opt_access | R_OK;
      }
      if(!strcmp(argv[i],"-w")){
	opt_access = opt_access | W_OK;
      } 
      if(!strcmp(argv[i],"-x")){
	opt_access = opt_access | X_OK; 
      }
      if(!strcmp(argv[i], "-v")){
	v_ok = 1;
      }
  }
  
  result = access(argv[1], opt_access);
  
  if(v_ok){
    switch(errno){
    case EACCES :
      printf("Impossible d'accéder au fichier\n");
      break;

    case ELOOP :
      printf("Trop de liens symboliques dans le chemin spécifié\n");
      break;

    case ENAMETOOLONG :
      printf("Le chemin spécifié est trop long\n");
      break;

    case ENOENT :
      printf("Un composant du chemin spécifié n'existe pas ou ne pointe nulle part\n");
      break;

    case ENOTDIR :
      printf("Un composant du chemin spécifié n'est pas un répertoire\n");
      break;

    }

  }
  
  return result;
}
