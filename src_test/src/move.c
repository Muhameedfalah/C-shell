#include "util.h"


void move_file(char **args)
{
    int num_args = 0;
    while (args[num_args] != NULL)
    {
        num_args++;
    }

    if (num_args < 2)
    {
        fprintf(stderr, "move_file: missing argument\n");
        return;
    }

    char *source_path = build_path(&args[0], 1);
    char *destination_path = build_path(&args[1], 1);

    struct stat s;
    if (stat(destination_path, &s) == 0 && S_ISDIR(s.st_mode))
    {
        char *source_filename = strrchr(source_path, '/');
        if (source_filename == NULL)
        {
            source_filename = source_path;
        }
        else
        {
            source_filename++;
        }

        char *new_destination_path = malloc(strlen(destination_path) + strlen(source_filename) + 2);
        if (new_destination_path == NULL)
        {
            fprintf(stderr, "malloc failed\n");
            return;
        }
        strcpy(new_destination_path, destination_path);
        strcat(new_destination_path, "/");
        strcat(new_destination_path, source_filename);

        free(destination_path);
        destination_path = new_destination_path;
    }

    if (rename(source_path, destination_path) != 0)
    {
        perror("Unable to move file");
        return;
    }
}