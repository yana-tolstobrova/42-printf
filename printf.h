#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int     ft_printf(const char *format, ...);
int	ft_putchar(char c);
int     ft_putstr(char *str);
#endif
