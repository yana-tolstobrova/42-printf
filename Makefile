CC = gcc
CFLAGS = -Wall -Wextra -Werror
HDIR = includes
SRCS = ft_printf.c ft_printf_utils.c
NAME = libftprintf.a
OBJS = ${SRCS:.c=.o}

%.o: %.c
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
