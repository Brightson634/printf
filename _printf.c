#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - Entry point
 * @format: format
 * @param ...
 * Return: always
 */
int printString(char *string)
{
	int s = 0;
	int i = 0;
	while (string[i] != '\0')
	{
		s = s + _putchar(string[i]);
		i++;
	}
	return (s);
}
/*
int printInt(int *int)
{
	int s = 0;
	int i = 0;
	while (int[i] != '\0')
	{
		s = s + _putchar(int[i]);
		i++;
	}
	return (s);
}
*/
int printDecimal(int decimal)
{
	int i = 0;

	/* checks for negative and prints negative number */
	if (decimal < 0)
	{
		i = i + _putchar('-');
		decimal = decimal * -1;
	}
	
	/* uses recursion to print all values */
	if(decimal / 10)
	{
		i = i + printDecimal(decimal/10);
	}
	i = i + _putchar(decimal%10 + '0');
	return (i);
}


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
			case 's':
				count = count + printString(va_arg(data, char *));
				break;
			case '%':
				/* prrint percentage from va_list */
				count = count + _putchar('%');
				break;
			case 'd':
				count = count + printDecimal(va_arg(data, long int));
				break;
			case 'i':
				count = count + printDecimal(va_arg(data, long int));
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
