#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/wait.h"
#include <math.h>
#include <ctype.h>

#include "parent.h"
#include "child.h"

int main() {

    int pipe_fd[2]; 
	
    int err = pipe(pipe_fd);

    if (err == -1) 
    {
        perror("pipe");
        return -1;
    }
	pid_t pid = fork();
    if (-1 == pid)
    {
        perror("fork");
        exit(-1);
    }
	
    if (0 == pid)
    {
        child(pipe_fd);
    }

    else
    {
        parent(pipe_fd);
    }
    return 0;
}


