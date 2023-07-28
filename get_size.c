#include "main.h"

/**
 * get_size - get the size of the argument
 * @format: Formatted string in which to print the arguments
 * @i: arguments to print
 *
 * Return: the size
 */
int get_size(const char *format, int *i)
{
	int actual_i = *i + 1;
	int size = 0;

	if (format[actual_i] == 'l')
		size = S_LONG;
	else if (format[actual_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = actual_i - 1;
	else
		*i = actual_i;

	return (size);
}
