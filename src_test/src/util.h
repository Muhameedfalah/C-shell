#ifndef UTIL_H
#define UTIL_H
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sched.h>
#include <sys/wait.h>



#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define BOLD "\033[1m"
#define RESET "\033[0m"


void getLocation();
void printWelcome();
void printHelp();

/*
 * Logout
 * args: array of strings
 * each arg is a command line argument
 * returns: void
 */
void logout(char *str);

/*
 * Build Path
 * args: array of strings
 * each arg is path components
 * each path component is separated by a space
 * returns: a string that is the path
 */
char *build_path(char **args, int num_args);

/*
 * Change Directory
 * args: array of strings
 * each arg is a command line argument
 * returns: void
 */
void cd(char **args);

/*
 * Copy File
 * args: array of strings
 * each arg is a command line argument
 * returns: void
 */
void copy_file(char **args);


/*
    * Move File
    * args: array of strings
    * each arg is a command line argument
    * returns: void
*/
void move_file(char **args);

/*
    * Delete File
    * args: array of strings
    * each arg is a command line argument
    * returns: void
*/
void delete_file(char **args);

/*
 * echo
 * args: array of strings
 * > : redirect output
 */

void echo(char **args);

/*
 * Read File
 * args: array of strings
 * each arg is a command line argument
 * returns: void
 */
void read_file(char **args);


/*
    * Word Line Count
    * args: array of strings
    * each arg is a command line argument
    * returns: void
*/
void word_line_count(char **args);

/*
    * Pipe
    * args1: array of strings
    * each arg is a command line argument
    * args2: array of strings
    * each arg is a command line argument
    * returns: void
*/
void mypipe(char **argv1, char **argv2);

/*
 * 𝑠𝑝𝑙𝑖𝑡𝐴𝑟𝑔𝑢𝑚𝑒𝑛𝑡
 * args: string
 * returns: array of strings
 */
char **𝑠𝑝𝑙𝑖𝑡𝐴𝑟𝑔𝑢𝑚𝑒𝑛𝑡(char *line);