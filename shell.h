#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern char **environ;
char *_strcpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_getenv(char *name);
#endif
