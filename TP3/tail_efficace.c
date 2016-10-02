#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 2048

long int
get_tail_pos(FILE* f, int tail_size){

	fseek(f, 0, SEEK_END);

	char buf[BUF_SIZE];

	long int file_size = ftell(f);
	long int pos = file_size;

	int remaining_lines = tail_size - 1;	

	while(remaining_lines > 0){

		int read_from;

		if(pos < BUF_SIZE){
			read_from = 0;
		} else {
			read_from = pos - BUF_SIZE;
		}

		fseek(f, read_from, SEEK_SET);

		size_t elements_read = fread(buf, sizeof(char), BUF_SIZE, f);

		for(int i=elements_read; i>=0; i--){
			if(buf[i] == '\n'){
				
				if(remaining_lines < 0) {
					pos++;
					break;
				}
				remaining_lines--;
			}
			pos--;

			if(pos <= 0){
				return pos;
			}
		}
	}
	return pos;
}

int
tail_efficace(char* path, int tail_size){

	FILE* f = fopen(path, "r");
	char buf[BUF_SIZE];
	
	if(f == NULL){

		return -1;
		
	}
	int tail_pos = get_tail_pos(f, tail_size);

	fseek(f, tail_pos, SEEK_SET);

	while(1){

		size_t elements_read = fread(buf, sizeof(char), BUF_SIZE, f);

		for(int i=0; i<elements_read; i++){

			printf("%c", buf[i]);

		}

		if(elements_read < BUF_SIZE) break;

	}

	fclose(f);

	return 0;
}





int
main(void){
	tail_efficace("test.txt", 25);
}