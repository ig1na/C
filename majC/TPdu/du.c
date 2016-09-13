#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

struct cell_m
{
  struct cell_m * next;
  struct dirent * e;
  
};

typedef struct cell_m * pile;

int
empty
(pile p)
{
  return p==NULL;

}

void
push
(pile *p, struct dirent *e)
{
  pile tmp;
  tmp = malloc(sizeof(struct cell_m));
  tmp->next = *p;
  tmp->e = e;
  *p = tmp;
  return ;

}

struct dirent *
pop
(pile *p)
{
  pile tmp;
  struct dirent * res;
  if(empty(*p)) return NULL;
  tmp = *p;
  res = tmp->e;
  *p = tmp->next;
  free(tmp);
  return res;

}

int
main
(void)
{
  DIR *vdir;
  struct dirent *entree;
  pile p = NULL;
  
  vdir = opendir(".");
  while(1==1){
    
    entree = readdir(vdir);
    if(entree==NULL) break;
    if(!strcmp(".", entree->d_name)) continue;
    if(strcmp("..",entree->d_name)==0) continue;
    push(&p,entree);
  }

  while(!empty(p))
    {
      entree = pop(&p);
      printf("%s\n",entree->d_name);
    }

  closedir(vdir);

  return 0;

}
