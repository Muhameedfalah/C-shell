#include "util.h"

char **𝑠𝑝𝑙𝑖𝑡𝐴𝑟𝑔𝑢𝑚𝑒𝑛𝑡(char *line)
{
    char **tokens = malloc(100 * sizeof(char *));
    char *token;
    int i = 0;

    while (*line != '\0')
    {
        while (isspace(*line))
        {
            ++line; // Skip spaces
        }

        if (*line == '"')
        {
            ++line; // Skip the opening quote
            token = line;
            while (*line != '\0' && *line != '"')
            {
                ++line;
            }
        }
        else
        {
            token = line;
            while (*line != '\0' && !isspace(*line))
            {
                ++line;
            }
        }

        if (*line != '\0')
        {
            *line = '\0';
            ++line;
        }

        tokens[i] = token;
        ++i;
    }

    tokens[i] = NULL;
    return tokens;
}