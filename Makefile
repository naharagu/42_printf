CC		= gcc

LIFBT	= ./libft/

CFLAGS	= -Wall -Wextra -Werror -I$(LIFBT)

SRCS	= ft_printf.c

NAME	= libftprintf.a

OBJS	= ${SRCS:%.c=%.o}

$(NAME): $(OBJS)
	make -C $(LIFBT)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	make clean -C $(LIFBT)
	rm -f $(OBJS)

fclean: clean
	make flean -C $(LIFBT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
