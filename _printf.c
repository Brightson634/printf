#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - Entry point
 * @format: format
 * @param ...
 * Return: always
 */
int _printf(const char *format, ...)
{
	int count = 0;
	int i = 0;
	va_list data;

	va_start(data, *format);

	while (format[i] != '\0')
	{
		/* count the number of characters */
		if (format[i] != '%')
		{
			/* checks for and skips the character % during count */
			count = count + _putchar(format[i]);
			i++;
		} else if (format[i] == '%' && format [i + 1] != ' ')
		{
			switch (format[i + 1])
			{
			case 'c':
				/* prrint character from va_list */
				count = count + _putchar(va_arg(data, int));
				break;
			
			default:
				break;
			}
			/* checks for and skips the character after % during count */
			i += 2;
		}
	}
	return (count);
}
