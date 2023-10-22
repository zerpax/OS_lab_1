#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/wait.h"

void child(int* pipe_fd){
	close(pipe_fd[1]); 
	char file_name[256];
	

	read(pipe_fd[0], file_name, sizeof(file_name));
	FILE* output = fopen(file_name, "w");


	int num;
	int sum = 0;
	char c = 0;

	while(read(pipe_fd[0], &num, sizeof(num))){
		while(c != 10) {
			
			read(pipe_fd[0], &c, sizeof(c));
			sum += num;
			if(c == 10) break;
			read(pipe_fd[0], &num, sizeof(num));
		}
		fprintf(output, "%d\n", sum);
		sum = 0;
		c = 0;
	}
	fclose(output);
	close(pipe_fd[0]);
}
