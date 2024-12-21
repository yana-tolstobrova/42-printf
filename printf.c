/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:07:01 by ytolstob          #+#    #+#             */
/*   Updated: 2024/12/21 23:07:09 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			i++;
			if (format[i] == 'c')
				res += ft_putchar(va_arg(args, int));
			else if (format[i] == 's')
				res += ft_putstr(va_arg(args, char *));
			else if (format[i] == 'p')
				res += ft_putptr(va_arg(args, char *));
			else if (format[i] == 'd' || format[i + 1] == 'i')
				res += ft_putnbr(va_arg(args, int));
			else if (format[i] == 'u')
                                res += ft_putunbr(va_arg(args, unsigned int));
			else if (format[i] == 'x')
				res += ft_puthex(va_arg(args, int), 0);
			else if (format[i] == 'X')
				res += ft_puthex(va_arg(args, int), 1);
			else if (format[i] == '%')
			       	res += write(1, "%", 1);
		}	
		else
			res += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	printf("%d", res);
	return (res);
}

int	main()
{
	ft_printf("%cu", 'a');
	//printf("og: %cu", 'a');
	//printf("%c", '\n');
	//ft_printf("%s", "test string");
	printf("%c", '\n');
	ft_printf("%p", main);
	printf("%c", '\n');
	ft_printf("%d", 42);
	//printf("%c", 'a');
	ft_printf("%X", 47483648);
	printf("%c", '\n');
	ft_printf("%%");
	//printf("%c", '\n');
	//printf("%p", main);
	//printf("%s", "test string");
	//printf("%%");
}	
