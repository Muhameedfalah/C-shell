#include "util.h"

void read_file(char **args)
{
    char *path = build_path(args, 1);

    FILE *fptr;
    fptr = fopen(path, "r");
    if (fptr == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    char c;
    while ((c = fgetc(fptr)) != EOF)
    {
        printf("%c", c);
    }
    fclose(fptr);
    printf("\n");
}