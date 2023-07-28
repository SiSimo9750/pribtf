#include "main.h"

/**
 * get_precision - Calculates theprinting  precision
 * @format: Formatted string in which to print the arguments
 * @i: List to print
 * @list: argument's list
 *
 * Return: wil return the precision value
 */
int get_precision(const char *format, int *i, va_list list)
{
	int actual_i = *i + 1;
	int prec = -1;

	if (format[actual_i] != '.')
		return (prec);

	prec = 0;

	for (actual_i += 1; format[actual_i] != '\0'; actual_i++)
	{
		if (is_digit(format[actual_i]))
		{
			prec *= 10;
			prec += format[actual_i] - '0';
		}
		else if (format[actual_i] == '*')
		{
			actual_i++;
			prec = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = actual_i - 1;

	return (prec);
}
