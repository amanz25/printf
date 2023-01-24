#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * _puts - write all char from string to stdout
 *
 * @str: string to print
 * @ascii: enable ascii restriction
 * Return: number of printed char
 */
int _puts(char *str, int ascii)
{
	char *s;
	int i = 0, sum = 0;

	while (str[i])
	{
		if (((str[i] >= 0 && str[i] < 32) || str[i] >= 127) && ascii)
		{
			s = base_conversion(str[i], 16, 1);
			sum += write(1, "\\x", 2);
			if (str[i] >= 0 && str[i] < 16)
				sum += _putchar('0');
			sum += _puts(s, 0);
			free(s);
			i++;
		}
		else
		{
			sum += _putchar(str[i]);
			i++;
		}
	}
	return (sum);
}

/**
 * _strcopy - a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter.
 *
 * @str: char pointer to copy
 * Return: a new char pointer
 */
char *_strcopy(char *str)
{
	char *s;
	int cLoop;

	if (str == NULL)
	{
		return (NULL);
	}

	s = malloc(sizeof(char) * (len_recursion(str) + 1));

	if (s == NULL)
	{
		return (NULL);
	}

	for (cLoop = 0; cLoop < len_recursion(str) + 1; cLoop++)
	{
		s[cLoop] = str[cLoop];
	}

	return (s);
}

/**
 * len_recursion - to print string length
 *
 * @s: char pointer
 *
 * Return: length of a string
 */
int len_recursion(char *s)
{
	if (*s != '\0')
	{
		return (len_recursion(s + 1) + 1);
	}
	else
	{
		return (0);
	}
}
