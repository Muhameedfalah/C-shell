#include "util.h"

/*
 * Logout
 * args: array of strings
 * each arg is a command line argument
 * returns: void
 */
void logout(char *str)
{
    if (str == NULL)
    {
        exit(0);
    }
    printf("%s\n", str);
    exit(0);
}
