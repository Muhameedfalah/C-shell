#include "util.h"

char *build_path(char **args, int num_args)
{
    char *path = malloc(100 * sizeof(char));
    if (path == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for path.\n");
        exit(1);
    }

    path[0] = '\0';

    for (int i = 0; i < num_args; i++)
    {

        if (args[i][0] == '"')
        {
            char *end_quote = strchr(args[i] + 1, '"');
            if (end_quote)
            {

                args[i]++;
                *end_quote = '\0';
            }
            else
            {
                fprintf(stderr, "Missing closing quote in argument.\n");
                exit(1);
            }
        }

        strcat(path, args[i]);

        if (i < num_args - 1 && args[i][strlen(args[i]) - 1] != '"')
        {
            strcat(path, "/");
        }
    }
    return path;
}