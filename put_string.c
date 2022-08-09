#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 *put_string - outputs string
 *@str string to print
 *
 *return: size of str
 */
int put_string(char *str)
{
	int i;

	int counter = 0;

	if (str)
	{
		for (i = 0; str[i] != '\0'; i++)
			counter += _putchar(str[i]);
	}
	return (counter);
}
