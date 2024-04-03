#include "util.h"

void printHelp()
{
    printf("Usage: [CMD] [OPTION]...\n");
    printf("Options:\n");
    printf("  -h, --help     Display this help and exit\n");
    printf("CMD:\n");
    printf("  cd             Change the shell working directory\n");
    printf("  cp             Copy files\n");
    printf("  mv             Move files\n");
    printf("  delete         Delete files\n");
    printf("  echo           Write arguments to the standard output\n");
    printf("  read           Read a file\n");
    printf("  wc             Print newline, word, and byte counts for each file\n");
    printf("  exit           Exit the shell\n");

}