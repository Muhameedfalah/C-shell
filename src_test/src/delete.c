#include "util.h"
void delete_file(char **args)
{
    // Count the number of arguments
    int num_args = 0;
    while (args[num_args] != NULL)
    {
        num_args++;
    }

    if (num_args < 1)
    {
        fprintf(stderr, "delete_file: missing argument\n");
        return;
    }

    char *path = build_path(args, num_args);

    if (remove(path) != 0)
    {
        perror("Unable to delete file");
        return;
    }
}