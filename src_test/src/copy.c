#include "util.h"

void copy_file(char **args)
{
    // Count the number of arguments
    int num_args = 0;
    while (args[num_args] != NULL)
    {
        num_args++;
    }

    if (num_args < 2)
    {
        fprintf(stderr, "copy_file: missing argument\n");
        return;
    }

    char *source_path = build_path(&args[0], 1);
    char *destination_path = build_path(&args[1], 1);

    // Check if destination is a directory
    struct stat s;
    if (stat(destination_path, &s) == 0 && S_ISDIR(s.st_mode))
    {
        // If destination is a directory, append the source filename to the destination path
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
        strcpy(new_destination_path, destination_path);
        strcat(new_destination_path, "/");
        strcat(new_destination_path, source_filename);

        free(destination_path);
        destination_path = new_destination_path;
    }

    FILE *source, *destination;
    char ch;

    // Open source file for reading
    source = fopen(source_path, "r");
    if (source == NULL)
    {
        fprintf(stderr, "Unable to open source file.\n");
        return;
    }

    // Open destination file for writing
    destination = fopen(destination_path, "w");
    if (destination == NULL)
    {
        fclose(source);
        fprintf(stderr, "Unable to open destination file.\n");
        return;
    }

    // Copy file
    while ((ch = fgetc(source)) != EOF)
    {
        fputc(ch, destination);
    }

    // Close files
    fclose(source);
    fclose(destination);
}