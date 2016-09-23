#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <dirent.h>
#include <stdio.h>

/*static int opt_follow_links = -1;*/
  static int opt_apparent_size = 0;

int
valid_name(const char *name){
  return !strcmp(name, ".") && !strcmp(name, "..");
}

int
du_file(const char *pathname)
{
  int size;
  struct stat st;

  stat(pathname, &st);

  if(S_ISREG(st.st_mode) || S_ISLNK(st.st_mode))
    {
      return opt_apparent_size? st.st_size:st.st_blocks;
    }
  
  if(S_ISDIR(st.st_mode))
    {
      DIR *dir;
      struct dirent *st_dir;
      char path_entry[PATH_MAX];

      dir = opendir(pathname);

      while((st_dir = readdir(dir)))
	{
	  if(!valid_name(st_dir->d_name)){
	    continue;
	  }
	  snprintf(path_entry, PATH_MAX, "%s/%s", pathname, st_dir->d_name);
	  size += du_file(path_entry);
	}
    }

  return size;
}

int
main(int argc, char *argv[])
{
  
}
