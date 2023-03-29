#include "main.h"

/**
 * _printf - printf function
 *
 * @format: format specifier
 *
 * Return: printed characters or string
 */

int _printf(const char *format, ...)
{
	int i, j;
	int numChar = 0;

	fs_t func_list[] = {
		{"c", printChar},
		{"s", printString}
	};

	va_list arg_list;

	va_start(arg_list, format);
	if (format == NULL)
		return (-1);

	for (i = 0; format[i]  != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; func_list[j].fs; j++)
			{
				if (format[i + 1] == func_list[j].fs[0])
				{
					numChar += func_list[j].func(arg_list);
					break;
				}
			}
			i++;
		}
		else
		{
			_putchar(format[i]);
			numChar++;
		}
	}
	va_end(arg_list);
	/* printf("%d\n",numChar); */
	return (numChar);
}
