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

	while (format[i] != '%' && format[i] != '\0')
	{
		/*count the number of characters*/
		count = count + _putchar(format[i]);
		i++;
	}
	return (count);
}
