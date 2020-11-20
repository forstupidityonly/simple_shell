#include "shell.h"

/**
 * _strlen - outputs the length of a string
 *
 * @s: input of string stored in char pointer
 *
 * Return: int of string length
 */

int _strlen(char *s)
{
	int len;

	len = 0;

	while (s[len] != '\0')
	{
		len++;
	}

	return (len);
}

/**
 * _strcpy - copies string from one character string to another
 *
 * @dest: char string to be copied to
 * @src: char string to be copied from
 * @n: number of char to be copied
 *
 * Return: pointer to copied string (dest)
 */

char *_strcpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = '\0';
	return (dest);
}

/**
 *
 *
 *
 */

int _strcmp_exact(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			break;
	}
	return (*s1 - *s2);
}

/**
 * _strcmp - compates to char strings to see if the match
 *
 * _!_ - This version of strcmp makes sure that newline is
 * not counted as a matchable char
 *
 * @s1: string 1 to compare
 * @s2: string 2 to compare
 *
 * Return: 1 if strings match
 * OR 0 if strings do not match
 */

int _strcmp(char *s1, char *s2)
{
	unsigned int i = 0;

	while (s2[i])
	{
		if ((s2[i] != s1[i]) && s2[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strdup - duplicates a string
 *
 * @str: string to be duplicated
 *
 * Return: NULL if string is NULL
 * OR pointer to new duplicated string
 */

char *_strdup(char *str)
{
	unsigned int i, j = 0;
	char *dest;

	if (str == NULL)
		return (0);
	for (i = 0; str[i]; i++)
		;
	i += 1;
	dest = malloc(i * sizeof(char));
	if (!dest)
		return (NULL);
	for (j = 0; str[j]; j++)
		dest[j] = str[j];
	dest[j] = str[j];
	return (dest);
}
