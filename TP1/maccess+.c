#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int
main(int argc, char * argv[]){

  int result;
  int opt_access = 0;
  int v_ok = 0;
  int opt;


  while ((opt = getopt(argc, argv, "rwxv")) != -1) {
               switch (opt) {
               case 'r':
		opt_access = opt_access | R_OK;
                   break;
               case 'w':
		opt_access = opt_access | W_OK;
                   break;
               case 'x':
		opt_access = opt_access | X_OK;
                   break;
               case 'v':
		v_ok = 1;
                   break;
		}
	}

  
  printf("opt access is : %d\n",opt_access);
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
