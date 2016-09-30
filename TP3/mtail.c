#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int
nb_lines_buf(char* buf, size_t size){

  int i;
  int nb_lines = 0;
  
  for(i=0; i<size; i++){
    if(buf[i] == '\n'){
      nb_lines++;
    }
  }

  return nb_lines;
}

int
nb_lines_file(int fd){

  char buf[BUF_SIZE];
  int result = 0;
  
  lseek(fd, 0, SEEK_SET);
  while(!read(fd, buf, BUF_SIZE)){
    result += nb_lines_buf(buf, BUF_SIZE);
    
  }

  return result;
}

int
tail(char *path, int nb_lines){
  int fd;
  int total_lines;
  int i;
  char buf[BUF_SIZE];
  int line_at;
  
  fd = open(path, O_CREAT);

  total_lines = nb_lines_file(fd);
  lseek(fd, 0, SEEK_SET);

  while(read(fd, buf, BUF_SIZE)){
    
    for(i=0; i<BUF_SIZE; i++){
      if(buf[i] == '\n'){
	line_at++;
	if(line_at >= total_lines - nb_lines){
	  printf("%s", &buf[i]);
	}
      }
      
    }
    
  }
  return 0;
}

int
main(void){

  char *path = "./Makefile";

  tail(path, 3);

  return 0;

}
