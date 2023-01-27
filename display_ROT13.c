#include "main.h"

/**
 * _rot13 - encodes a string using rot13
 * @t: pointer to track + # and space
 * @args:  argument track list
 *
 * Return: string length.
 */
int _rot13(va_list args, T_flag *t)
{
	int i, k;

	char *str = va_arg(args, char *);

	char first[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char second[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	(void)t;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
			_putchar(str[i]);
		else
		{
			k = 0;
			while (k <= 52)
			{
				if (str[i] == first[k])
					_putchar(second[k]);
			}
		}
		i++;
	}

	return (i);
}
