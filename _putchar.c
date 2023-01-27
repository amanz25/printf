#include <unistd.h>
#include "main.h"

/**
 * _putchar - writes the character c to stdout
 *
 * @c: The character to print
 * Return: On success 1 on error, -1 is returned
 */
int _putchar(char c)
{
	static char buf[BUFF_SIZE];
	static int i;

	if (c == -1 || i >= BUFF_SIZE)
	{
		write(1, &buf, i);
		i = 0;
	}
	if (c != -1)
	{
		buf[i] = c;
		i++;
	}
	return (1);
}

/**
 * _put - prints a string to stdout
 * @s: pointer to the string to print
 * Return: number of chars written
 */
int _put(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
	return (i);
}
