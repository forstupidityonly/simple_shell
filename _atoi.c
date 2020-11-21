#include "shell.h"

/**
 * _atoi - converts a string to an int
 * @s: pointer to string
 * Return: 0
 */

int _atoi(char *s)
{
	int len = 0, tmp = 0, tmp2 = 0;
	unsigned int sign = 1;

	while (s[len] != '\0')
	{
		if (s[len] >= 48 && s[len] <= 57)
		{
			tmp2 = s[len] - 48;
			tmp = (tmp * 10) + tmp2;
			if (tmp > 250)
				return (-1);
		}
		else if (s[len] == 45)
		{
			return (-1);
		}
		else if ((s[len] < 48 || s[len] > 57) && (s[len + 1] >= 48 &&
s[len + 1] <= 57))
			return (-1);
		else if ((s[len] < 48 || s[len] > 57) && tmp != 0)
			return (-1);
		else
			break;
		len++;
	}

	return (tmp * sign);
}

/**
 * exit_stat - exits with status
 *
 * @buffer: getlines input
 * @head: head of list
 * @s: buffer
 * Return: -1 on fail
 */

int exit_stat(char *buffer, list_t *head, char *s)
{
	int ext_val = -1;
	int i = 0;

	if (buffer[0] != 'e' || buffer[1] != 'x' || buffer[2] != 'i' || buffer[
3] != 't' || buffer[4] != ' ')
	{
		printf("should be doing this\n");
		return (-1);
	}
	while (*buffer != ' ')
	{
		++i;
		buffer++;
	}
	while (*buffer == ' ')
	{
		++i;
		buffer++;
	}
	ext_val = _atoi(buffer);

	if (ext_val == -1)
		return (-1);

	buffer = buffer - i;
	free_list(head);
	free(buffer);
	free(s);
	exit(ext_val);
}
