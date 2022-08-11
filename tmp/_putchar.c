#include <unistd.h>
/**
 *_putchar - outputs char to stdout
 *@c: the char to print
 *
 *Return: on success 1
 *
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
