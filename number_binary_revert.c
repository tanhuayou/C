#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_revert_str(unsigned int,char*);
void get_binary_revert_str(unsigned int,char*);

int main(int argc,char** argv){
	
	unsigned int num = 0;
	unsigned int buf_size = 33;
	char* buf = (char*) malloc(buf_size);
	
	printf("Please input one unsigned number: ");
	while(scanf("%d",&num) != EOF){
		memset(buf,0,buf_size);
		get_revert_str(num,buf);
		printf("Not bit op %d --> %s\n",num,buf);
		printf("Please input one unsigned number: ");
	}

	free(buf);
	buf = NULL;

	return 0;
}

void get_revert_str(unsigned int num,char* buf){
	if(NULL == buf){
		printf("Null for buf!\n");
		exit(-1);
	}
	while(num > 0){
		if( 1 & (num)){
			*buf++ = '1';
		}else{
			*buf++ = '0';
		}
		num = num >>1;
	}
}

void get_binary_revert_str(unsigned int num ,char* buf){
	
}
