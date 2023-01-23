#include <unistd.h>
/**
 * _putchar - fucntion to print characters
 * @c: the character to be printed
 *
 * Return: 1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
