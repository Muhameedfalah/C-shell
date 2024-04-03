#include "util.h"

void echo(char **args)
{
    char *str = malloc(1024); // Allocate initial memory
    if (str == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    str[0] = '\0'; // Initialize str to an empty string

    int i = 0;
    char *mode = "w"; // Default to overwrite mode

    while (args[i] != NULL)
    {
        if (strcmp(args[i], ">") == 0)
        {
            break;
        }
        else
        {
            // Check if str has enough space for the next argument
            if (strlen(str) + strlen(args[i]) + 1 > 1024)
            {
                // Resize str
                str = realloc(str, strlen(str) + strlen(args[i]) + 1);
                if (str == NULL)
                {
                    printf("Memory allocation failed\n");
                    return;
                }
            }
            strcat(str, args[i]);
            strcat(str, " "); // Add space between words
        }
        i++;
    }

    if (args[i] == NULL)
    {
        printf("Missing file path\n");
        free(str); // Free memory
        return;
    }

    char *path = build_path(&args[i + 1], 1);

    FILE *fptr;
    fptr = fopen(path, mode);
    if (fptr == NULL)
    {
        printf("Error opening file!\n");
        free(str); // Free memory
        return;
    }
    fprintf(fptr, "%s", str);
    fclose(fptr);

    free(str); // Free memory
}