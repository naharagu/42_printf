CC = gcc
CFLAGS   = -Wall -Wextra -Werror

SRCS    = 	ft_printf.c \

NAME		= libftprintf.a

OBJS		= ${SRCS:%.c=%.o}

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
