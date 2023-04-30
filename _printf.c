#include "main.h"
#include <stdarg.h>
#include <stdio.h>
void print_buffer(char buffer[], int *buff_index);
/**
 * _printf - returns output per format stdout
 * format: what to print
 *
 * Return: formatted output
 */
int _printf(const char *format, ...)
{
	int i, output =0, rtn_val = 0, buff_index = 0;
	int flags, width,precision, size;
	char buffer[BUFF_ALLOC];
	va_list args;

	if (format == NULL)
		return(-1);
	va_start(args, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[i];
			if (buff_index == BUFF_ALLOC)
				print_buffer(buffer, &buff_index);
			rtn_val++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			++i;
			output = handle_print(format, &i, args,buffer, flags, width, precision,size);
			if (output == -1)
				return(-1);
			rtn_val += output;
		}
	}
	print_buffer(buffer, &buff_index);
	va_end(args);
	return(rtn_val);
}
/**
 * print_buffer - prints out buffer
 * @buffer: char arrary[buff_index]
 * @buff_index: length
 */
void print_buffer(char buffer[], int *buff_index)
{
	if(*buff_index > 0)
		write(1, &buffer[0], *buff_index);
	*buff_index = 0;
}
