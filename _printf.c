#include "main.h"
/**
 *_printf - this is print function
 *@format: const char pointer
 *Description: this function is executing a set of printf functions
 *Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	const char *string;
	int count = 0;
	vlist arg;

	if (!format)
		return (-1);

	va_start(arg, format);
	string = format;

	count = loop_format(arg, string);

	va_end(arg);
	return (count);
}
/**
 *loop_format - this is loop format
 *@arg: vlist arg
 *@string: pointer from format
 *Description: This is a function that makes a loop string pointer 
 *Return: number of characters printed
 */
int loop_format(vlist arg, const char *string)
{
	int i = 0, flag = 0, cfm = 0, count = 0, chkper = 0;

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
				cfm = function_manager(aux, arg);
				if (cfm >= 0 && cfm != -1)
				{
					i++;
					aux = string[i];
					if (aux == '%')
						flag--;
					count = count + cfm;
				} else if (cfm == -1 && aux != '\n')
				{
					count += _putchar('%');
				}
			}
		}
		chkper = chkpercent(&flag, aux);
		count += chkper;
		if (chkper == 0 && aux != '\0' && aux != '%')
			count += _putchar(aux), i++;
		chkper = 0;
	}
	return (count);
}
/**
 * chkpercent - call function manager
 *@flag: value by reference
 *@aux: character
 *Description: This function prints % per
 *Return: 1 if % is printed
 */
int chkpercent(int *flag, char aux)
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
 * call_function_manager - this calls the function manager
 *@aux: character param aux
 *@arg: vlist arg
 *Description: This is a function that calls the function manager
 *Return: number of characters printed
 */

int call_function_manager(char aux, vlist arg)
{
	int count = 0;

	count = function_manager(aux, arg);
	return (count);
}
