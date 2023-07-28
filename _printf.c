#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - my printf function
 * @format: format
 * Return: Printed chararacters
 */
int _printf(const char *format, ...)
{
	int a, printed = 0, printed_ch = 0;
	int fl, wid, prec, size, buffer_ind = 0;
	va_list l;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(l, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buffer[buffer_ind++] = format[i];
			if (buffer_ind == BUFF_SIZE)
				print_buffer(buffer, &buffer_ind);
			/* write(1, &format[a], 1);*/
			printed_ch++;
		}
		else
		{
			print_buffer(buffer, &buffer_ind);
			fl = get_flags(format, &a);
			wid = get_width(format, &a, l);
			prec = get_precision(format, &a, l);
			size = get_size(format, &a);
			++a;
			printed = handle_print(format, &a, l, buffer,
				f, wid, prec, size);
			if (printed == -1)
				return (-1);
			printed_ch += printed;
		}
	}

	print_buffer(buffer, &buffer_ind);

	va_end(l);

	return (printed_ch);
}

/**
 * print_buffer - if buffer exist prints its contents
 * @buffer: Array of characters
 * @buffer_ind: Index at which to add next char
 */
void print_buffer(char buffer[], int *buffer_ind)
{
	if (*buffer_ind > 0)
		write(1, &buffer[0], *buffer_ind);

	*buffer_ind = 0;
}
