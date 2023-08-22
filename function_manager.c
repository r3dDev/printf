#include "main.h"
#include <stdarg.h>
/**
 *function_manager - this is the function manager
 *@c: character to find
 *@argument: va_list type
 *Description: This function calls other functions
 * when the character is found
 *Return: count of printed characters
 */
int function_manager(char c, va_list argument)
{
	int count = 0;

	count = _switch(c, argument);
	if (c == 'p')
		count = print_ptr(argument);
	return (count);
}
/**
 *_switch - switch
 *@c: character to find
 *@argument: va_list type
 *Description: This function evaluates cases
 *Return: count of printed characters
 */
int _switch(char c, va_list argument)
{
	int count = 0;

	switch (c)
	{
		case 'b':
			count += print_unsign(argument, 2);
			break;
		case 'c':
			count += print_character(argument);
			break;
		case 'd':
		case 'i':
			count += print_sign(argument, 10);
			break;
		case 'o':
			count += print_unsign(argument, 8);
			break;
		case 'r':
			count += print_rev(argument);
			break;
		case 'R':
			count += print_rot13(argument);
			break;
		case 's':
			count += print_string(argument);
			break;
		case 'u':
			count += print_unsign(argument, 10);
			break;
		case 'x':
			count += print_base16_upper_lower(argument, "0123456789abcdef");
			break;
		case 'X':
			count += print_base16_upper_lower(argument, "0123456789ABCDEF");
			break;
		default:
			count = -1;
	}
	return (count);
}
