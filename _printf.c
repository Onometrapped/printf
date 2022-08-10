#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
/* #include "main.h" */
/**
 *_printf - prints formatted output
 *@format: pointer to char to be formatted
 *
 * description: formats and output text
 *
 * return: length of str
 *
 */
 int _putchar(char c);
 int put_string(char *str);
int _printf(const char *format, ...)
{
	int size;
	va_list spec;

	va_start(spec, format);

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			size = _putchar(format[i]);
		}
		else if (format[i] == '%' && format[i + 1] != '\0')
		{
			if (format[i + 1] == 'c')
			{
			    i++;
			    size += _putchar(va_arg(spec, int));
			}
			if (format[i + 1] == 's')
			{
				i++;
				size += put_string(va_arg(spec, char *));
			}
			if (format[i + 1] == 'd')
			{
			    i++;
			    int num = va_arg(spec, int);

			    if (num < 0)
			    {
			        num = num * -1;
				_putchar('-');
				size += _putchar(num % 10 + '0');
			    }
			    else
				size += _putchar(num % 10 + '0');
			}
			if (format[i + 1] == 'i')
			{
				unsigned int num = va_arg(spec, unsigned int);

				if (num < 0)
			    {
			        put_string("unsigned int expected");
			    }
			    else
			        size += _putchar(num % 10 + '0');
			}
		}
	}
	va_end(spec);
	return (size);

}

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

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

