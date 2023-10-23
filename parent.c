#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/wait.h"

void parent(int* pipe_fd, char* file_name){
	close(pipe_fd[0]); 
	write(pipe_fd[1],  file_name,  sizeof(file_name));

	char c;
	char* digs;
	int num;
	while(scanf("%d", &num)){
			c = getchar();
			write(pipe_fd[1],  &num,  sizeof(num));
			write(pipe_fd[1],  &c,  sizeof(c));
	}
    close(pipe_fd[1]);

    wait(NULL); 
}
