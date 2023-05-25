#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>


#define MAX_CMD 15
#define MAX_CMDLEN 50
char *getPath(char *cmd);
void _prompt(char **av, char **env);

#endif
