#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/wait.h"

void parent(int* pipe_fd){
	close(pipe_fd[0]); 
	char file_name[256];	
	
	scanf("%s",file_name);

	write(pipe_fd[1],  file_name,  sizeof(file_name));
	char c = '_';
	int num;
	while(scanf("%d", &num)){
			c = getchar();
			write(pipe_fd[1],  &num,  sizeof(num));
			write(pipe_fd[1],  &c,  sizeof(c));
	}
    close(pipe_fd[1]);

    wait(NULL); 
}
