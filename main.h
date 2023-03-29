#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * struct format_specifier
 *
 * @fs: the format specifier
 * @func: the function associated to fs
 */
struct format_specifier
{
	char *fs;
	int (*func)(va_list);
};

typedef struct format_specifier fs_t;

int _putchar(char);
int printChar(va_list list);
int printString(va_list list);
int _printf(const char *format, ...);

#endif
