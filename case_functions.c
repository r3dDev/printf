#include "main.h"
/**
 * print_character - Prints a single character.
 * @argument: va_list parameter.
 * Description: Prints a single character.
 * Return: 1
 */
int print_character(va_list argument)
{
	int i;

	i = va_arg(argument, int);
	_putchar(i);

	return (1);
}
/**
 * print_sign - Prints signed numbers in specified base.
 * @argument: va_list parameter.
 * @base: Base 10, 8, 16, etc.
 * Description: Prints signed numbers in the specified base.
 * Return: Number of characters printed.
 */
int print_sign(va_list argument, int base)
{
	int i = 0, count = 0;
	char *s;

	i = va_arg(argument, int);
	if (i < 0)
	{
		i = -(i);
		_putchar('-');
		count += 1;
	}
	s = convert_to("0123456789ABCDEF", i, base);
	_puts(s);
	count += _strlen(s);
	return (count);
}
/**
 * print_unsign - Prints unsigned numbers in specified base.
 * @argument: va_list parameter.
 * @base: Base 10, 8, 16, etc.
 * Description: Prints unsigned numbers in the specified base.
 * Return: Number of characters printed.
 */
int print_unsign(va_list argument, int base)
{
	int count = 0;
	unsigned int i;
	char *s;

	i = va_arg(argument, unsigned int);
	s = convert_to("0123456789ABCDEF", i, base);
	_puts(s);
	count = _strlen(s);

	return (count);

}
/**
 * print_string - print a string
 * @argument: va_list parameter
 * Description: print string
 * Return: num of characters
 */
int print_string(va_list argument)
{
	char *s;
	int count = 0;

	s = va_arg(argument, char *);
	if (!s)
	{
		s = "(null)";
		_puts(s);

		return (_strlen(s));
	}
	_puts(s);
	count = _strlen(s);
	return (count);
}
/**
 * print_base16_upper_lower - print_base16_upper_lower
 * @argument: va_list parameter
 *@representation: pointer parameter
 * Description: This function takes 0123456789ABCDEF or 0123456789abcdef
 * in representation parameter for print hexadecimal format
 * Return: num of characters
 */
int print_base16_upper_lower(va_list argument, char *representation)
{
	unsigned int i = 0, count = 0;
	char *s;

	i = va_arg(argument, unsigned int);
	s = convert_to(representation, i, 16);
	_puts(s);
	count = _strlen(s);
	return (count);

}
