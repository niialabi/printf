#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - returns output per format stdout
 * format: what to print
 *
 * Return: int value
 */
int _printf(const char *format, ...)
{
	va_list args;
	int rtn_val;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
				rtn_val += printf("%c", va_arg(args, int));
				break;
				case 's':
				rtn_val += printf("%s", va_arg(args, char*));
				break;
				case 'd':
				rtn_val += printf("%d", va_arg(args, int));
				break;
				case 'i':
				rtn_val += printf("%d", va_arg(args, unsigned int));
				break;
				case '%':
				putchar('%');
				rtn_val++;
				break;
				default:
					printf("Invalid format specifier: %c", *format);
				return (-1);
			}
		}
		else if (*format == '\\')
		{
			format++;
			switch (*format)
			{
				case 'n':
					putchar('\n');
					rtn_val++;
					break;
				case 't':
					putchar('\t');
					rtn_val++;
					break;
				default:
				putchar('\\');
				putchar(*format);
				rtn_val += 2;
				break;
			}
		}
		else
		{
			putchar(*format);
			rtn_val++;
		}
		format++;
	}
	va_end(args);
	return (rtn_val);
}
