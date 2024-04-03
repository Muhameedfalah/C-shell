#include "util.h"

void getLocation()
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        char *home = getenv("HOME");
        if (home != NULL && strncmp(cwd, home, strlen(home)) == 0)
        {
            char new_cwd[1024];
            size_t len = 1 + strlen(cwd + strlen(home)) + 1; // +1 for '~', +1 for '\0'
            if (len < sizeof(new_cwd))
            {
                sprintf(new_cwd, "~%s", cwd + strlen(home));
                strncpy(cwd, new_cwd, sizeof(cwd) - 1);
                cwd[sizeof(cwd) - 1] = '\0';
            }
        }
    }
    else
    {
        perror("getcwd() error");
    }

    // Get username and hostname
    char username[1024];
    getlogin_r(username, sizeof(username));

    char hostname[1024];
    gethostname(hostname, sizeof(hostname));

    // Print formatted string with colors and highlighting
    printf("%s%s%s@%s%s%s:%s%s%s%s$ ", GREEN, BOLD, username, GREEN, BOLD, hostname, BLUE, BOLD, cwd, RESET);
}