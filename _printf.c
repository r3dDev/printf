#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Description: This function implements some functions of printf.
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	const char *string;
	int cont = 0;
	va_list arg;

	if (!format)
		return (-1);

	va_start(arg, format);
	string = format;

	cont = loop_format(arg, string);

	va_end(arg);
	return (cont);
}

/**
 * loop_format - Loop through format string
 * @arg: va_list argument
 * @string: Pointer to format string
 *
 * Description: This function iterates through the format string.
 * Return: Number of characters printed
 */
int loop_format(va_list arg, const char *string)
{
	int i = 0, flag = 0, cont_fm = 0, cont = 0, check_per = 0;

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
				return (cont);
			if (aux == '%')
			{
				flag++;
			}
			else
			{
				cont_fm = function_manager(aux, arg);
				if (cont_fm >= 0 && cont_fm != -1)
				{
					i++;
					aux = string[i];
					if (aux == '%')
						flag--;
					cont += cont_fm;
				}
				else if (cont_fm == -1 && aux != '\n')
				{
					cont += _putchar('%');
				}
			}
		}
		check_per = check_percent(&flag, aux);
		cont += check_per;
		if (check_per == 0 && aux != '\0' && aux != '%')
			cont += _putchar(aux), i++;
		check_per = 0;
	}
	return (cont);
}

/**
 * check_percent - Check and print '%' character
 * @flag: Value by reference
 * @aux: Character
 *
 * Description: This function prints '%' character.
 * Return: 1 if '%' is printed, else 0
 */
int check_percent(int *flag, char aux)
{
	int tmp_flag;
	int cont = 0;

	tmp_flag = *flag;
	if (tmp_flag == 2 && aux == '%')
	{
		_putchar('%');
		tmp_flag = 0;
		cont = 1;
	}
	return (cont);
}

/**
 * call_function_manager - Call function manager
 * @aux: Character parameter
 * @arg: va_list argument
 *
 * Description: This function calls the function manager.
 * Return: Number of characters printed
 */
int call_function_manager(char aux, va_list arg)
{
	int cont = 0;

	cont = function_manager(aux, arg);
	return (cont);
}

