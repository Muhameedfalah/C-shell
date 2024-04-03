#include "util.h"


void cd(char **args)
{
    int num_args = 0;
    while (args[num_args] != NULL)
    {
        num_args++;
    }

    if (num_args < 1)
    {
        fprintf(stderr, "cd: missing argument\n");
        return;
    }

    if (strcmp(args[0], "-h") == 0 || strcmp(args[0], "--help") == 0)
    {
        printf("Usage: cd [DirectoryFragment] (...) | [\"Directory Fragment Containing space\"]\n");
        printf("Change the shell working directory.\n");
        return;
    }

    if (strcmp(args[0], "-") == 0)
    {
        char *previous = getenv("OLDPWD");
        if (previous == NULL)
        {
            fprintf(stderr, "cd: OLDPWD not set\n");
            return;
        }
        if (chdir(previous) != 0)
        {
            perror("cd");
        }
        return;
    }

    if (strcmp(args[0], "~") == 0)
    {
        char *home = getenv("HOME");
        if (home == NULL)
        {
            fprintf(stderr, "cd: HOME not set\n");
            return;
        }
        if (chdir(home) != 0)
        {
            perror("cd");
        }
        return;
    }



    char *path = build_path(args, num_args);
    if (chdir(path) != 0)
    {
        perror("cd");
    }
}