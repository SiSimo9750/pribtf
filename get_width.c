#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: arguments to be printed.
 * @list: list of arguments.
 *
 * Return:will return width value
 */
int get_width(const char *format, int *i, va_list list)
{
	int actual_i;
	int wid = 0;

	for (actual_i = *i + 1; format[actual_i] != '\0'; actual_i++)
	{
		if (is_digit(format[actual_i]))
		{
			wid *= 10;
			wid += format[actual_i] - '0';
		}
		else if (format[actual_i] == '*')
		{
			actual_i++;
			wid = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = actual_i - 1;

	return (wid);
}
