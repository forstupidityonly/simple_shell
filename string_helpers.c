#include "shell.h"
/**
  * cpy string
  */
char *_strcpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i]= src[i];
	for (; i < n; i++)
		dest[i] = '\0';
	return (dest);
}
/**
  * cmp string
  */
int _strcmp(char *s1, char *s2)
{
	unsigned int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		++i;
	}
	return (1);
}
