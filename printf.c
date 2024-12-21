#include "printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	int	i;
	int	res;
	va_list	args;
	va_start (args, format);

	i = 0;
	res = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (format[i + 1] == 'c')
				res += ft_putchar(va_arg(args, int));
			if (format[i + 1] == 's')
				res += ft_putstr(va_arg(args, char *));
		}
		i++;
	}
	va_end(args);
	return (res);
}

int	main()
{
	//ft_printf("%c", 'a');
	ft_printf("%s", "test string");
	//printf("%c", 'a');
	printf("%c", '\n');
	printf("%s", "test string");
}	
