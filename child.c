#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/wait.h"
#include <fcntl.h>
#include <ctype.h>

void child(int* pipe_fd){
	close(pipe_fd[1]); 
	char file_name[256];

	read(pipe_fd[0], file_name,  sizeof(file_name));

	int output = open(file_name, O_CREAT | O_RDWR, S_IRWXU);

	int num;
	int sum = 0;
	char c = 0;
	char res[10];
	while(read(pipe_fd[0], &num, sizeof(num))){
		while(c != 10) {
			
			read(pipe_fd[0], &c, sizeof(c));
			sum += num;
			if(c == 10) break;
			read(pipe_fd[0], &num, sizeof(num));
		}
		//sprintf(res, "%d", sum);
		write(output, &sum, sizeof(sum));
		//fprintf(output, "%d\n", sum);
		sum = 0;
		c = 0;
	}
	close(output);
	close(pipe_fd[0]);
}
