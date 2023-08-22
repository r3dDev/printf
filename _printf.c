#include "main.h"
/**
 *_printf - this is a printf function
 *@format: const char pointer
 *Description: this functions implements some functions of printf
 *Return: num of characters printed
 */
int _printf(const char *format, ...)
{
	const char *string;
	int count = 0;
	va_list argument;

	if (!format)
		return (-1);

	va_start(argument, format);
	string = format;

	count = loop_format(argument, string);

	va_end(argument);
	return (count);
}
/**
 *loop_format - loop format
 *@argument: va_list argument
 *@string: pointer from format
 *Description: This function make loop tp string pointer
 *Return: num of characters printed
 */
int loop_format(va_list argument, const char *string)
{
	int i = 0, flag = 0, count_fm = 0, count = 0, checkper = 0;

	while (i < _strlen((char *)string) && *string != '\0')
	{
		char aux = string[i];

		if (aux == '%')
		{
			i++, flag++;
			aux = string[i];
			if (aux == '\0' && _strlen((char *)string) == 1)
				return (-1);
			if (aux == '\0')
				return (count);
			if (aux == '%')
			{
				flag++;
			} else
			{
				count_fm = function_manager(aux, argument);
				if (count_fm >= 0 && count_fm != -1)
				{
					i++;
					aux = string[i];
					if (aux == '%')
						flag--;
					count = count + count_fm;
				} else if (count_fm == -1 && aux != '\n')
				{
					count += _putchar('%');
				}
			}
		}
		checkper = check_percent(&flag, aux);
		count += checkper;
		if (checkper == 0 && aux != '\0' && aux != '%')
			count += _putchar(aux), i++;
		checkper = 0;
	}
	return (count);
}
/**
 * check_percent - calls the function manager
 *@flag: value by reference
 *@aux: character
 *Description: This function print % pear
 *Return: 1 if % is printed
 */
int check_percent(int *flag, char aux)
{
	int tmp_flag;
	int count = 0;

	tmp_flag = *flag;
	if (tmp_flag == 2 && aux == '%')
	{
		_putchar('%');
		tmp_flag = 0;
		count = 1;
	}
	return (count);
}

/**
 * call_function_manager - calls the function manager
 *@aux: character parameter
 *@argument: va_list argument
 *Description: This function calls the function manager
 *Return: number of characters printed
 */

int call_function_manager(char aux, va_list argument)
{
	int count = 0;

	count = function_manager(aux, argument);
	return (count);
}
