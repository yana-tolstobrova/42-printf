/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:07:01 by ytolstob          #+#    #+#             */
/*   Updated: 2024/12/21 23:07:09 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_check_and_print(char format_c, va_list args)
{
	int	res;

	res = 0;
	if (format_c == 'c')
		res += ft_putchar(va_arg(args, int));
	else if (format_c == 's')
		res += ft_putstr(va_arg(args, char *));
	else if (format_c == 'p')
		res += ft_putptr(va_arg(args, void *));
	else if (format_c == 'd' || format_c == 'i')
		res += ft_putnbr(va_arg(args, int));
	else if (format_c == 'u')
		res += ft_putunbr(va_arg(args, unsigned int));
	else if (format_c == 'x')
		res += ft_puthex(va_arg(args, unsigned int), 0);
	else if (format_c == 'X')
		res += ft_puthex(va_arg(args, unsigned int), 1);
	else if (format_c == '%')
		res += write(1, "%", 1);
	return (res);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		res;
	va_list	args;

	va_start (args, format);
	i = 0;
	res = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			res += ft_check_and_print(format[i], args);
		}
		else
			res += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (res);
}
