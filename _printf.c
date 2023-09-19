#include "main.h"

/**
 * _printf - entry point
 * @format: identifier to look for.
 * Return: length of string.
 */
int _printf(const char * const format, ...)
{
	convert_match m[] = {
		{"%s", printf_string}, {"%c", printf_char},
		{"%%", printf_37},
		{"%i", printf_int}, {"%d", printf_dec}, {"%r", printf_srev},
		{"%R", printf_rot13}, {"%b", printf_bin}, {"%u", printf_unsigned},
		{"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
		{"%S", printf_exclusive_string}, {"%p", printf_pointer}
	};

	int a = 0, b, c = 0;
	va_list val;

	va_start(val, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	return (-1);

Here:
	while (format[a] != '\0')
	{
	b = 13;
	while (b >= 0)
	{
	if (m[b].id[0] == format[a] && m[b].id[1] == format[a + 1])
	{
	c += m[b].f(val);
	a = a + 2;
	goto Here;
	}
	b--;
	}
	_putchar(format[a]);
	c++;
	a++;
	}
	va_end(val);
	return (c);
}
