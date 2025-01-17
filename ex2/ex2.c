// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    FILE *fptr;
    fptr = fopen("text.txt", "w");
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        char child[] = "Hello, This is child.\n";
        fprintf(fptr, "%s", child);
    }
    else
    {
        char parent[] = "Hello, This is parent.\n";
        fprintf(fptr, "%s", parent);
    }
    fclose(fptr);
    return 0;
}
