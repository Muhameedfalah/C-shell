#include "util.h"

void mypipe(char **argv1, char **argv2)
{

    char *cmd1 = argv1[0];
    char **args1 = &argv1[1];
    
    char *cmd2 = argv2[0];
    
    char **args2 = &argv2[1];
    
    int pipefd[2];
    pid_t pid1, pid2;

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid1 = fork();
    if (pid1 == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0)
    {                                   // Child process
        close(pipefd[0]);               // Close read end
        dup2(pipefd[1], STDOUT_FILENO); // Redirect stdout to write end of pipe

       
        // Execute first command
        if(strcmp(cmd1, "cd") == 0){
            cd(args1);
        } else if(strcmp(cmd1, "cp") == 0){
            copy_file(args1);
        } else if(strcmp(cmd1, "mv") == 0){
            move_file(args1);
        } else if(strcmp(cmd1, "delete") == 0){
            delete_file(args1);
        } else if(strcmp(cmd1, "echo") == 0){
            echo(args1);
        } else if(strcmp(cmd1, "read") == 0){
            read_file(args1);
        } else if(strcmp(cmd1, "wc") == 0){
            word_line_count(args1);
        } else {
            execvp(cmd1, args1);
        }

        exit(EXIT_FAILURE);
    }

    pid2 = fork();

    if (pid2 == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0) {                                        
        
        close(pipefd[1]);              // Close write end
        dup2(pipefd[0], STDIN_FILENO); // Redirect stdin to read end of pipe
        close(pipefd[0]);              // Close read end (not necessary after dup2)
        char *new_args2[] = { cmd2, args2[0], NULL };
        execvp(cmd2, new_args2);       // Execute second command
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    close(pipefd[0]);
    close(pipefd[1]);

    int status1, status2;
    waitpid(pid1, &status1, 0);
    waitpid(pid2, &status2, 0);
}