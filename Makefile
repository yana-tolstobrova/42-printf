# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytolstob <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 20:38:52 by ytolstob          #+#    #+#              #
#    Updated: 2024/12/23 20:39:00 by ytolstob         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HDIR = includes
SRCS = ft_printf.c ft_printf_utils.c
NAME = libftprintf.a
OBJS = ${SRCS:.c=.o}

%.o: %.c ft_printf.h Makefile
	${CC} ${CFLAGS} -I ${HDIR} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
