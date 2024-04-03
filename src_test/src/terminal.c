#include "util.h"

int main()
{
    char *line = NULL;

    printWelcome();
    //printHelp();

    do
    {
        getLocation();
        // Get line
        size_t len = 0;
        getline(&line, &len, stdin);

        // Remove the newline character
        line[strcspn(line, "\n")] = 0;

        // Split the line into tokens
        char **tokens = 𝑠𝑝𝑙𝑖𝑡𝐴𝑟𝑔𝑢𝑚𝑒𝑛𝑡(line);
        // Check for pipe
        int i;
        for (i = 0; tokens[i] != NULL; i++)
        {
            if (strcmp(tokens[i], "|") == 0)
            {
                break;
            }
        }

        if (tokens[i] != NULL)
        {                     // Pipe found
            tokens[i] = NULL; // Split tokens into two arrays
            char **argv1 = tokens;
            char **argv2 = &tokens[i + 1];

            mypipe(argv1, argv2);
        }
        else
        {
            // The first token is the command
            char *cmd = tokens[0];

            // The rest of the tokens are the arguments
            char **args = &tokens[1];

            if(cmd == NULL)
            {
                continue;
            } else if(strcmp(cmd, "help") == 0){
                printHelp();
            }
            else if (strcmp(cmd, "exit") == 0)
            {
                logout(args[0]);
            }
            else if (strcmp(cmd, "cd") == 0)
            {
                cd(args);
            }
            else if (strcmp(cmd, "cp") == 0)
            {
                copy_file(args);
            }
            else if (strcmp(cmd, "mv") == 0)
            {
                move_file(args);
            }
            else if (strcmp(cmd, "delete") == 0)
            {
                delete_file(args);
            }
            else if (strcmp(cmd, "echo") == 0)
            {
                echo(args);
            }
            else if (strcmp(cmd, "read") == 0)
            {
                read_file(args);
            }
            else if (strcmp(cmd, "wc") == 0)
            {
                word_line_count(args);
            }

            else
            {
                printf("\nCommand not found: %s\n", cmd);
                printf("Type 'help' to see a list of available commands.\n");
                printf("Trying to run system command...\n");
                pid_t pid = fork();
                if (pid < 0)
                {
                    perror("fork failed");
                }
                else if (pid == 0)
                {
                    // This is the child process. Call execvp here.
                    execvp(cmd, args);
                    perror("execvp failed");
                    exit(EXIT_FAILURE);
                }
                else
                {
                    // This is the parent process. Wait for the child to finish.
                    int status;
                    waitpid(pid, &status, 0);
                }
            }
        }

        free(tokens);

    } while (line != NULL);

    return 0;
}