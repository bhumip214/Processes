// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here

    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("It's a child!\n");
        char *myargs[3];

        myargs[0] = "ls";
        myargs[1] = "../";
        myargs[2] = NULL;

        //execvp(myargs[0], myargs);
        execl("/bin/ls", myargs[0]);
        //execl("/bin/ls", myargs[0], myargs[1], myargs[2]);
    }
    else
    {
        int wc = waitpid(rc, NULL, 0);
        printf("It's a parent!\n");
    }
    return 0;
}
