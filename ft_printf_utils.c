/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:07:20 by ytolstob          #+#    #+#             */
/*   Updated: 2024/12/21 23:07:25 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	unsigned long int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
		return(write(1, "-2147483648", 11));
	else
	{
		if (nb < 0)
		{
			i += ft_putchar('-');
			nb = -nb;
		}
		if (nb < 10)
			i += ft_putchar(nb + 48);
		else
		{
			i += ft_putnbr(nb / 10);
			i += ft_putnbr(nb % 10);
		}
	}
	return (i);
}

int	ft_putunbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb < 10)
		i += ft_putchar(nb + 48);
	else
	{
		i += ft_putunbr(nb / 10);
                i += ft_putunbr(nb % 10);
        }
	return (i);
}

int	ft_puthex(unsigned long num, int uppercase)
{
	int	i;
	char    *base;

	base = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	i = 0;
	if (num >= 16)
                i += ft_puthex(num / 16, uppercase);
        i += ft_putchar(base[num % 16]);
        return (i);
}
	
int	ft_putptr(void *pointer)
{
	int	i;
	unsigned long	num;

	i = 0;
	if (!pointer)
		return (ft_putstr("(null)"));
	i += write(1, "0x", 2);
	num = (unsigned long)pointer;
	i += ft_puthex(num, 0);
	return (i);
}
