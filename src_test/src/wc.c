#include "util.h"

void word_line_count(char **args)
{
    if(strcmp(args[0], "-l") != 0 && strcmp(args[0], "-w") != 0)
    {
        printf("Invalid option\n");
        return;
    }

    FILE *fptr;
    char *path = build_path(&args[1], 1);
    char ch;
    int lines = 1, words = 1, characters = 1;

    fptr = fopen(path, "r");
    if (fptr == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }

    while ((ch = fgetc(fptr)) != EOF)
    {
        characters++;
        if (ch == '\n' || ch == '\0')
        {
            lines++;
        }
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
        {
            words++;
        }
    }

    if (strcmp(args[0], "-l") == 0)
    {
        printf("%d %s\n", lines, path);
    }
    else if (strcmp(args[0], "-w") == 0)
    {
        printf("%d %s\n", words, path);
    }
    else
    {
        printf("Invalid option\n");
    }

    fclose(fptr);
}