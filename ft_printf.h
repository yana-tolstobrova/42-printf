/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:07:41 by ytolstob          #+#    #+#             */
/*   Updated: 2024/12/21 23:07:49 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_check_and_print(char format_c, va_list args);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putptr(void *pointer);
int	ft_putnbr(int nb);
int	ft_putunbr(unsigned int nb);
int	ft_puthex(unsigned long num, int uppercase);
#endif
