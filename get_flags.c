#include "main.h"

/**
 * get_flags - counts flags
 * @format: Formatted string in which to print the arguments
 * @i: parametr
 * 
 * Return: flags number
 */
int get_flags(const char *format, int *i)
{
	int j, actual_i;
	int f = 0;
	const char CH_FLAGS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int ARR_FLAGS[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (actual_i = *i + 1; format[actual_i] != '\0'; actual_i++)
	{
		for (j = 0; CH_FLAGS[j] != '\0'; j++)
			if (format[actual_i] == CH_FLAGS[j])
			{
				f |= ARR_FLAGS[j];
				break;
			}

		if (CH_FLAGS[j] == 0)
			break;
	}

	*i = actual_i - 1;

	return (f);
}
